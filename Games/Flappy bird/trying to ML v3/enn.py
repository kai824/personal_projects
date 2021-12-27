#my own try at evolutionary neural network with genetic algorithm
#based on neueral network coded for astroparty
#Inspiration:https://pdf.sciencedirectassets.com/277811/1-s2.0-S1877042812X00284/1-s2.0-S187704281204668X/main.pdf?X-Amz-Security-Token=AgoJb3JpZ2luX2VjEO3%2F%2F%2F%2F%2F%2F%2F%2F%2F%2FwEaCXVzLWVhc3QtMSJGMEQCIEUIuNibua4n2g43BrlDo10iBEDL96OTVZwi%2BJb7jKO3AiBOUS02m8KSZ%2B%2BPI9Viq8qocDUtLqb1DT8RoH%2FMBFIrlSraAwh2EAIaDDA1OTAwMzU0Njg2NSIMXwTQ6RlAgNDFl7hfKrcDNBJ%2BKacznklunK8BBIbdCK4VsdoE42Pk5mOkf42ySE9EwuuZPB%2BLDXqpSGm%2BG23Gc%2FPP%2B4wH2Xn8yOPBQ%2FQLLmPKddd2BWBoYstmoCmvlfdVKUuLcIqjzh6qxzWkyc9Xd9qPFQdO5oQ97WoLdQ7LEkb0rGieI3IjkC%2FJb1ba9TjA0TxL8aWz7L%2BCCr2b417LYx1co%2Fyc3VgvwED9n6H59hB3F0%2BMXGnLJ%2Bd03Nnro3zPmq73c1YBFrE4lhX107xSIz9se7JyufQG%2BWGIJGkdrD0iF2qMc7SK4gDVgU%2FN9hycXFZq%2BQKhfWe%2BfeRWxUX8E4uUBHCCrr61XesmTP6h8Gp%2FRdPtQ4bbiUmg%2FxY9lT8s%2FILNj0o6fx%2FSjPtDp%2BJjB5lfKSWFDTPE0C%2FacI0Td8dBIIbh0yeYLn8rSa5eHLsARLxFJzqZll1dE4%2F9EZr00l72njw%2BmsjeGcLWWPktWfo9Vo6PxTegdbjWCNN%2FX47Y4OgoMLj0uPcSKw9o3XF9OmIiCZqm52lIr0%2BjQXCgWx2A0qp%2FAz2BOlj9DMS3s31%2BC4OcknI19rz8oTZjPvCDZCx%2BKNXLXDCNsLDqBTq1AXs%2FKoOljTPgXSL%2F1uwKwT9Q9xTdCuIiG95kwENSVqj6pdMPTzffLNZQhwYf1Gjk6IhMcsJncQlNpJalLG0u5DFyXIMh%2Bu7X%2BhrlFJn25FrIMyFKPh2TH4pUiz1kr33avyweoIskGVXjHiJEFYlgQqCw0HH1JK%2BRrwgYyw9EUObMH4mVxkG%2FcCudzV4GbnLUN2pwmdyLglJuyBCDCU4z9%2FSGn9uMIeyNrwwmaeKKuQoKoyVyjLM%3D&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20190808T135032Z&X-Amz-SignedHeaders=host&X-Amz-Expires=300&X-Amz-Credential=ASIAQ3PHCVTY7XWHVSDA%2F20190808%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=b21531b9a8028e5e73bbd2665da3de37b80a3470bed434bccb4118188dec6bc9&hash=aca695dd3af0f5eef9dbfbd3118d17aeb537275b8c5377755f801e4a0d301bc7&host=68042c943591013ac2b2430a89b270f6af2c76d8dfd086a07176afe7c76c2c61&pii=S187704281204668X&tid=spdf-f2153836-f1cb-43ac-96aa-e393dc27f9d2&sid=7af4c5402c57804eba0920d03bad43120c41gxrqb&type=client
#Explanation:https://www.youtube.com/watch?v=ziMHaGQJuSI&vl=en

#modified to make it usable as a module

from numpy import exp, array, random, dot
import pickle

random.seed(42)#seeding the rng

class NeuronLayer():
    def __init__(self, number_of_neurons, number_of_inputs_per_neuron):
        self.synaptic_weights = 2 * random.random((number_of_inputs_per_neuron, number_of_neurons)) - 1#goes between -1 and 1


class NeuralNetwork():
    def __init__(self, layers,input_no):#no. of hidden layers, number of inputs
        self.layers=[]
        self.input_size=input_no
        size=input_no+1
        for x in range(layers):
            if x==0:
                self.layers.append(NeuronLayer(size,input_no))
            else:
                self.layers.append(NeuronLayer(size,size))
        self.layers.append(NeuronLayer(1,size))#output layer

    def __sigmoid(self, x):
        return 1 / (1 + exp(-x))
    def __l_relu(self,x):#leaky relu
        return (1.1*x+abs(0.9*x))/2  #essentially max (0.1x,x)

    #Derivative indicates how confident we are about the existing weight.
    def __sigmoid_derivative(self, x):
        return x * (1 - x)
    def __l_derivative(self,x):#NOT DONE HERE, no idea how to fix issue of x=0...
        return 0.9*(abs(x)/(2*x)+0.5)+0.1 #x is value of output, but doesn't matter since polarity of output same as polarity of input

    # We train the neural network through a process of trial and error.
    # Adjusting the synaptic weights each time.
    def train(self, training_set_inputs, training_set_outputs, number_of_training_iterations,typ='sigmoid'):
        for iteration in range(number_of_training_iterations):
            # Pass the training set through our neural network
            outputs= self.think(training_set_inputs,typ=typ)
            prev_delta=None

            for xx in range(len(self.layers)):
                x=len(self.layers)-1-xx #reverse the thing, 'cause back propagation
                if type(prev_delta)==type(None):
                    error=training_set_outputs-outputs[x]
                else:
                    error=prev_delta.dot(self.layers[x+1].synaptic_weights.T)
                if typ=='sigmoid':
                    delta=error * self.__sigmoid_derivative(outputs[x])
                else:
                    delta=error * self.__l_derivative(outputs[x])
                prev_delta=delta
                if x==0:
                    adjustment=training_set_inputs.T.dot(delta)
                else:
                    adjustment=outputs[x-1].T.dot(delta)
                self.layers[x].synaptic_weights += adjustment

    # The neural network thinks.
    def think(self, inputs,typ='sigmoid'):
        outputs=[]
        prev=inputs
        for x in range(len(self.layers)):
            if typ=='relu':
                prev = self.__l_relu(dot(prev,self.layers[x].synaptic_weights))
            else:
                prev = self.__sigmoid(dot(prev,self.layers[x].synaptic_weights))
            outputs.append(prev)
        #output_from_layer1 = self.__sigmoid(dot(inputs, self.layer1.synaptic_weights))
        return outputs

    def query(self,state,colour,state_list=None):
        situation=[]
        for i in state:
            for j in i:
                if j[0]==colour:#own piece of player who just played
                    situation+=[0,1]
                elif j[0]=='n':
                    situation+=[0,0]#no piece
                else:
                    situation+=[1,0]#opponent piece
                #converting inputs first
        if state_list!=None:
            state_list.append(situation)
        try:
            return self.think(array(situation))[-1][0]
        except ValueError:
            print("Error on:",situation)
            return 0.5

    # The neural network prints its weights
    def print_weights(self):
        for x in range(len(self.layers)):
            print("Layer",x+1)
            print(self.layers[x].synaptic_weights)

def save(filename,neural_network):
    f=open(filename,'wb')
    pickle.dump(neural_network,f)
    f.close()
def load(filename):
    f=open(filename,'rb')
    neural_network=pickle.load(f)
    f.close()
    return neural_network
def reproduce(network1,network2):
    network3=NeuralNetwork(len(network1.layers)-1,network1.input_size)
    for i in range(len(network3.layers)):
        for j in range(len(network3.layers[i].synaptic_weights)):
            for k in range(len(network3.layers[i].synaptic_weights[j])):
                #network3.layers[i].synaptic_weights[j][k]=random.choice([network1.layers[i].synaptic_weights[j][k],network2.layers[i].synaptic_weights[j][k]])
                network3.layers[i].synaptic_weights[j][k]=network1.layers[i].synaptic_weights[j][k] + \
                                                           ( (network2.layers[i].synaptic_weights[j][k]-network1.layers[i].synaptic_weights[j][k]) * (1.5*random.random()-0.25))
    return network3
def mutate(network):
    changes=random.randint(1,3)
    for i in range(changes):
        x=random.randint(len(network.layers))
        y=random.randint(len(network.layers[x].synaptic_weights))
        z=random.randint(len(network.layers[x].synaptic_weights[y]))
        if abs(network.layers[x].synaptic_weights[y][z])<=1:
            network.layers[x].synaptic_weights[y][z]+= (random.random()-0.5)*0.05#modify by a bit
        else:
            network.layers[x].synaptic_weights[y][z]*= 1+((random.random()-0.5)*0.05)
    '''for layer in network.layers:#layer.synaptic_weights
        for i in range(len(layer.synaptic_weights)):
            for j in range(len(layer.synaptic_weights[i])):
                layer.synaptic_weights[i][j]+=random.random() - 0.5#between -0.5 and 0.5'''

def equal(n1,n2):
    for i in range(len(n1.layers)):
        for j in range(len(n1.layers[i].synaptic_weights)):
            for k in range(len(n1.layers[i].synaptic_weights[j])):
                if n1.layers[i].synaptic_weights[j][k]!=n2.layers[i].synaptic_weights[j][k]:
                    return False
    return True

if __name__ == "__main__":

    # Combine the layers to create a neural network
    neural_network = NeuralNetwork(2,3)#2 hidden layer, 3 inputs
    network2=NeuralNetwork(2,3)

    print("Stage 1) Random starting synaptic weights: ")
    neural_network.print_weights()

    # The training set. We have 7 examples, each consisting of 3 input values
    # and 1 output value.
    training_set_inputs = array([[0, 0, 1], [0, 1, 1], [1, 0, 1], [0, 1, 0], [1, 0, 0], [1, 1, 1], [0, 0, 0]])
    training_set_outputs = array([[0, 1, 1, 1, 1, 0, 0]]).T

    print(training_set_inputs)
    print(training_set_outputs)

    # Train the neural network using the training set.

    neural_network.train(training_set_inputs, training_set_outputs, 20000)
    network2.train(training_set_inputs, training_set_outputs, 30000)

    print("Stage 2) New synaptic weights after training: ")
    neural_network=reproduce(neural_network,network2)
    #mutate(neural_network)
    neural_network.print_weights()

    # Test the neural network with a new situation.
    situation=[1,1,0]
    print("Stage 3) Considering a new situation",situation,"-> ?: ")
    output = neural_network.think(array(situation))[-1][0]
    print(round(output,5))
