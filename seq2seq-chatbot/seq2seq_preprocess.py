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
from tensorflow.keras.models import load_model
from nltk.translate.bleu_score import corpus_bleu
from sklearn.model_selection import train_test_split
import tensorflow_addons as tfa


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


f=open('_chat_boston.txt','r')
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
for i in range(10):
    print(cleaned_sentences[i])


raw_data = cleaned_sentences
raw_data_call = list()
raw_data_resp = list()#call, response...
for data1 in raw_data:
  raw_data_call.append(data1[0])
  raw_data_resp.append(data1[1])

print(len(raw_data_call))
