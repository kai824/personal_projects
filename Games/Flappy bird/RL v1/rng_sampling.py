import random

#do like BST for k log n random sampling...
#from the PER paper, just use sum-tree method (cos i have no idea what they're talking about for rank-based)

nodes=[]

class Tree:
    def __init__(self,s,e,parent):
        self.parent=parent
        self.sum=0
        self.s,self.e=s,e
        if s<e:
            self.left=Tree(s,(s+e)//2,self)
            self.right=Tree((s+e)//2+1,e,self)
        else:
            nodes.append(self)
            self.left=self.right=None
    def sweep(self):
        if self.s<self.e:
            self.left.sweep()
            self.right.sweep()
            self.sum=self.left.sum+self.right.sum
    def sample(self,l,rng=-1):#l is list to store nodes...
        if self.s==self.e:
            l.append(self)
            return None
        if rng==-1:
            rng=random.random()*self.sum
        if rng>self.left.sum:
            self.right.sample(l,rng-self.left.sum)
        else:
            self.left.sample(l,rng)
    def update(self,neww=-1):#do bottom-up
        if neww==-1:
            self.sum=self.left.sum+self.right.sum
        else:
            self.sum=neww
        self.parent.update()
