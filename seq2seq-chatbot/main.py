import csv
import string
import re
from pickle import dump
from unicodedata import normalize
import numpy as np
from numpy import array
import itertools
from pickle import load
from tensorflow.keras.utils import to_categorical
#from keras.utils.vis_utils import plot_model
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM
from tensorflow.keras.layers import Dense
from tensorflow.keras.layers import Embedding
from pickle import load
from numpy import array
from numpy import argmax
import tensorflow as tf
from tensorflow.keras.models import load_model,save_model
from nltk.translate.bleu_score import corpus_bleu
from sklearn.model_selection import train_test_split
import tensorflow_addons as tfa

STATE_SIZE=300


# split a loaded document into sentences
def doc_sep_pair(doc):
  lines = doc.strip().split('\n')
  pairs = [line.split('\t') for line in  lines]
  return pairs

# clean a list of lines
def clean_sentences(lines):
  cleaned = list()
  re_print = re.compile('[^%s]' % re.escape(string.printable))
  # prepare translation table
  table = str.maketrans('', '', string.punctuation)
  for pair in lines:
    clean_pair = list()
    for line in pair:
      # normalizing unicode characters
      line = normalize('NFD', line).encode('ascii', 'ignore')
      line = line.decode('UTF-8')
      # tokenize on white space
      line = line.split()
      # convert to lowercase
      line = [word.lower() for word in line]
      # removing punctuation
      line = [word.translate(table) for word in line]
      # removing non-printable chars form each token
      line = [re_print.sub('', w) for w in line]
      # removing tokens with numbers
      line = [word for word in line if word.isalpha()]

      line.insert(0,'<start> ')
      line.append(' <end>')
      # store as string
      clean_pair.append(' '.join(line))
    cleaned.append(clean_pair)
  return array(cleaned)

f=open('_chat.txt','r')
lines=f.read().lower().split('\n[')
f.close()

prev_me=None
sent_tokens=[]

for line in lines:
    if line.endswith('image omitted'): continue
    message=': '.join(line.split(': ')[1:])
    if prev_me==True and line.split(': ')[0][-3:]=='kai':
        sent_tokens[-1]+='\n'+message
    elif prev_me==False and line.split(': ')[0][-3:]!='kai':
        sent_tokens[-1]+='\n'+message
    else:
        sent_tokens.append(message)
    prev_me = (line.split(': ')[0][-3:]=='kai')

pairs=[]
for i in range(0,len(sent_tokens)-1):
    pairs.append((sent_tokens[i],sent_tokens[i+1]))#the message corresponds to the reply
cleaned_sentences=clean_sentences(pairs)


raw_data = cleaned_sentences
raw_data_call = list()
raw_data_resp = list()#call, response...
for data1 in raw_data:
  raw_data_call.append(data1[0])
  raw_data_resp.append(data1[1])

#lazy to change variable names honestly
raw_data_en=raw_data_call
raw_data_ge=raw_data_resp

en_tokenizer = tf.keras.preprocessing.text.Tokenizer(filters='')
en_tokenizer.fit_on_texts(raw_data_en)

data_en = en_tokenizer.texts_to_sequences(raw_data_en)
data_en = tf.keras.preprocessing.sequence.pad_sequences(data_en,padding='post')

ge_tokenizer = tf.keras.preprocessing.text.Tokenizer(filters='')
ge_tokenizer.fit_on_texts(raw_data_ge)

data_ge = ge_tokenizer.texts_to_sequences(raw_data_ge)
data_ge = tf.keras.preprocessing.sequence.pad_sequences(data_ge,padding='post')

def max_len(tensor):
    #print( np.argmax([len(t) for t in tensor]))
    return max( len(t) for t in tensor)

X_train,  X_test, Y_train, Y_test = train_test_split(data_en,data_ge,test_size=0.2)
BATCH_SIZE = 64
BUFFER_SIZE = len(X_train)
steps_per_epoch = BUFFER_SIZE//BATCH_SIZE
embedding_dims = 256
rnn_units = STATE_SIZE
dense_units = STATE_SIZE
Dtype = tf.float32   #used to initialize DecoderCell Zero state

Tx = max_len(data_en)
Ty = max_len(data_ge)

input_vocab_size = len(en_tokenizer.word_index)+1
output_vocab_size = len(ge_tokenizer.word_index)+ 1
dataset = tf.data.Dataset.from_tensor_slices((X_train, Y_train)).shuffle(BUFFER_SIZE).batch(BATCH_SIZE, drop_remainder=True)
example_X, example_Y = next(iter(dataset))
#print(example_X.shape)
#print(example_Y.shape)


#ENCODER
class EncoderNetwork(tf.keras.Model):
    def __init__(self,input_vocab_size,embedding_dims, rnn_units ):
        super().__init__()
        self.encoder_embedding = tf.keras.layers.Embedding(input_dim=input_vocab_size,
                                                           output_dim=embedding_dims)
        self.encoder_rnnlayer = tf.keras.layers.LSTM(rnn_units,return_sequences=True,
                                                     return_state=True )

#DECODER
class DecoderNetwork(tf.keras.Model):
    def __init__(self,output_vocab_size, embedding_dims, rnn_units):
        super().__init__()
        self.decoder_embedding = tf.keras.layers.Embedding(input_dim=output_vocab_size,
                                                           output_dim=embedding_dims)
        self.dense_layer = tf.keras.layers.Dense(output_vocab_size)
        self.decoder_rnncell = tf.keras.layers.LSTMCell(rnn_units)
        # Sampler
        self.sampler = tfa.seq2seq.sampler.TrainingSampler()
        # Create attention mechanism with memory = None
        self.attention_mechanism = self.build_attention_mechanism(dense_units,None,BATCH_SIZE*[Tx])
        self.rnn_cell =  self.build_rnn_cell(BATCH_SIZE)
        self.decoder = tfa.seq2seq.BasicDecoder(self.rnn_cell, sampler= self.sampler,
                                                output_layer=self.dense_layer)

    def build_attention_mechanism(self, units,memory, memory_sequence_length):
        return tfa.seq2seq.LuongAttention(units, memory = memory,
                                          memory_sequence_length=memory_sequence_length)
        #return tfa.seq2seq.BahdanauAttention(units, memory = memory, memory_sequence_length=memory_sequence_length)

    # wrap decodernn cell
    def build_rnn_cell(self, batch_size ):
        rnn_cell = tfa.seq2seq.AttentionWrapper(self.decoder_rnncell, self.attention_mechanism,
                                                attention_layer_size=dense_units)
        return rnn_cell

    def build_decoder_initial_state(self, batch_size, encoder_state,Dtype):
        decoder_initial_state = self.rnn_cell.get_initial_state(batch_size = batch_size,
                                                                dtype = Dtype)
        decoder_initial_state = decoder_initial_state.clone(cell_state=encoder_state)
        return decoder_initial_state

encoderNetwork = EncoderNetwork(input_vocab_size,embedding_dims, rnn_units)
decoderNetwork = DecoderNetwork(output_vocab_size,embedding_dims, rnn_units)


encoderNetwork.load_weights(f'{STATE_SIZE} nodes/network1')
decoderNetwork.load_weights(f'{STATE_SIZE} nodes/network2')



#In this section we evaluate our model on a raw_input converted to german, for this the entire sentence has to be passed
#through the length of the model, for this we use greedsampler to run through the decoder
#and the final embedding matrix trained on the data is used to generate embeddings

def call(input_raw):
    # We have a transcript file containing English-German pairs
    # Preprocess X
    input_lines = ['<start> '+input_raw+'']
    input_lines = [list(clean_sentences([(input_raw,input_raw)])[0])[0][:-7]]

    #print(input_lines)
    #print(input_lines2)

    input_sequences=[]
    for line in input_lines:
        tmp=[]
        for w in line.split():
            if w in en_tokenizer.word_index:
                tmp.append(en_tokenizer.word_index[w])
        input_sequences.append(tmp)
        if tmp==[]:
            return 'hello'
    #input_sequences = [[en_tokenizer.word_index[w] for w in line.split()] for line in input_lines]
    input_sequences = tf.keras.preprocessing.sequence.pad_sequences(input_sequences,
                                                                    maxlen=Tx, padding='post')
    inp = tf.convert_to_tensor(input_sequences)
    #print(inp.shape)
    inference_batch_size = input_sequences.shape[0]
    encoder_initial_cell_state = [tf.zeros((inference_batch_size, rnn_units)),
                                  tf.zeros((inference_batch_size, rnn_units))]
    encoder_emb_inp = encoderNetwork.encoder_embedding(inp)
    a, a_tx, c_tx = encoderNetwork.encoder_rnnlayer(encoder_emb_inp,
                                                    initial_state =encoder_initial_cell_state)
    ##print('a_tx :',a_tx.shape)
    ##print('c_tx :', c_tx.shape)

    start_tokens = tf.fill([inference_batch_size],ge_tokenizer.word_index['<start>'])

    end_token = ge_tokenizer.word_index['<end>']

    greedy_sampler = tfa.seq2seq.GreedyEmbeddingSampler()

    decoder_input = tf.expand_dims([ge_tokenizer.word_index['<start>']]* inference_batch_size,1)
    decoder_emb_inp = decoderNetwork.decoder_embedding(decoder_input)

    decoder_instance = tfa.seq2seq.BasicDecoder(cell = decoderNetwork.rnn_cell, sampler = greedy_sampler,
                                                output_layer=decoderNetwork.dense_layer)
    decoderNetwork.attention_mechanism.setup_memory(a)
    #pass [ last step activations , encoder memory_state ] as input to decoder for LSTM
    ##print("decoder_initial_state = [a_tx, c_tx] :",np.array([a_tx, c_tx]).shape)
    decoder_initial_state = decoderNetwork.build_decoder_initial_state(inference_batch_size,
                                                                       encoder_state=[a_tx, c_tx],
                                                                       Dtype=tf.float32)
    ##print("\nCompared to simple encoder-decoder without attention, the decoder_initial_state \
     #is an AttentionWrapperState object containing s_prev tensors and context and alignment vector \n ")
    ##print("decoder initial state shape :",np.array(decoder_initial_state).shape)
    ##print("decoder_initial_state tensor \n", decoder_initial_state)

    # Since we do not know the target sequence lengths in advance, we use maximum_iterations to limit the translation lengths.
    # One heuristic is to decode up to two times the source sentence lengths.
    maximum_iterations = tf.round(tf.reduce_max(Tx) * 2)

    #initialize inference decoder
    decoder_embedding_matrix = decoderNetwork.decoder_embedding.variables[0]
    (first_finished, first_inputs,first_state) = decoder_instance.initialize(decoder_embedding_matrix,
                                 start_tokens = start_tokens,
                                 end_token=end_token,
                                 initial_state = decoder_initial_state)
    #print( first_finished.shape)
    ##print("\nfirst_inputs returns the same decoder_input i.e. embedding of  <start> :",first_inputs.shape)
    ##print("start_index_emb_avg ", tf.reduce_sum(tf.reduce_mean(first_inputs, axis=0))) # mean along the batch

    inputs = first_inputs
    state = first_state
    predictions = np.empty((inference_batch_size,0), dtype = np.int32)
    for j in range(maximum_iterations):
        outputs, next_state, next_inputs, finished = decoder_instance.step(j,inputs,state)
        inputs = next_inputs
        state = next_state
        outputs = np.expand_dims(outputs.sample_id,axis = -1)
        predictions = np.append(predictions, outputs, axis = -1)
    #prediction based on our sentence earlier
    ##print("English Sentence:")
    ##print(input_raw)
    ##print("\nBot response:")
    output=''
    for i in range(len(predictions)):
        line = predictions[i,:]
        seq = list(itertools.takewhile( lambda index: index !=2, line))
        ##print(" ".join( [ge_tokenizer.index_word[w] for w in seq]))
        output+=" ".join( [ge_tokenizer.index_word[w] for w in seq])
    return output

'''
34.682559967041016
31.821107864379883
30.34479522705078
29.191219329833984
28.13306999206543
27.220993041992188
26.202707290649414
25.041528701782227
23.774778366088867
22.334728240966797
20.8861141204834
19.5262393951416
18.192121505737305
17.17095375061035
16.48561668395996
16.082435607910156
14.347171783447266
13.167433738708496
12.193612098693848
11.185471534729004
10.388354301452637
9.714715957641602
9.028855323791504
8.858036041259766
9.27112102508545

34.69567108154297
31.94304847717285
30.486848831176758
29.42804527282715
28.34331512451172
27.23287010192871
26.156299591064453
25.00956916809082
23.762361526489258
22.414188385009766
21.051883697509766
19.767715454101562
18.786741256713867
18.06842803955078
17.5032958984375
14.948121070861816
13.064859390258789
11.974366188049316
11.10659408569336
10.403155326843262
9.771699905395508
9.22927474975586
8.746261596679688
8.233621597290039
7.857337951660156
7.707322120666504
7.422140121459961

34.439613342285156
31.921215057373047
30.44633674621582
29.435588836669922
28.400489807128906
27.348373413085938
26.299562454223633
25.27605628967285
24.009641647338867
22.743043899536133
21.492652893066406
20.23497772216797
19.082836151123047
17.9973201751709
17.086252212524414
14.24674129486084
12.294146537780762
11.139044761657715
10.187171936035156
9.626032829284668
8.85684871673584
8.158413887023926
7.62219762802124
7.471086025238037
'''
while True:
    try:
        i=input('You: ')
    except KeyboardInterrupt:
        break
    print("BOT:",call(i.lower()))
