from tkinter import*
import time
import random
import pickle

import enn
import copy
from numpy import array
try:
    networks=enn.load('population.dat')
except FileNotFoundError:
    networks=[]
    for x in range(15):
        networks.append(enn.NeuralNetwork(1,4))
        #2 hidden layers, 4 inputs: velocity, dist to next pipe, dist to bottom pipe, dist to 2nd bottom pipe
    enn.save('population.dat',networks)

class Bird:
    def __init__(self,canvas,colour,score):
        self.speed=0.1
        self.deceleration=30
        self.canvas=canvas
        self.score=score
        self.paused=False
        self.started=False
        self.press=False
        self.quit=False
        self.died=False
        self.n=False
        self.pause_text=()
        self.id=self.canvas.create_oval(40,190,60,210,fill=colour,outline=colour)
        self.canvas.bind_all('<ButtonPress-1>',self.jump)
        self.canvas.bind_all('<space>',self.jump)
        self.canvas.bind_all('<KeyPress-m>',self.pause)
        self.canvas.bind_all('<KeyPress-n>',self.nn)
        self.canvas.bind_all('<KeyPress-q>',self.end)
    def nn(self,evt):
        if self.n==False:
            self.n=True
        else:
            self.n=False
    def end(self,evt):
        self.quit=True
    def game_over(self):
        tk.update()
        tk.update_idletasks()
        self.speed=0
        #time.sleep(0.3)
        self.died=True
        while True:
            self.speed+=self.deceleration/100
            self.canvas.move(self.id,0,self.speed)
            coords=self.canvas.coords(self.id)
            if coords[3]>=400:
                break
            tk.update()
            tk.update_idletasks()
            #time.sleep(0.01)
        self.score.game_over()
    def update(self):
        self.canvas.move(self.id,0,self.speed)
        self.speed+=self.deceleration/(1/0.01)
        coords=self.canvas.coords(self.id)
        if coords[3]>400 or coords[1]<0:
            self.game_over()
    def jump(self,evt):
        if self.paused==True:
            return 0
        self.press=True
        self.started=True
        if self.n==True:
            return 0
        if self.died==False:
            self.speed=-5
        self.started=True
    def pause(self,evt):
        if self.paused==False:
            self.paused=True
            self.pause_text=(self.canvas.create_rectangle(100,100,600,300,fill='#FFFFFF'),self.canvas.create_text(350,200,text='Paused'))
        else:
            self.paused=False
            self.canvas.delete(self.pause_text[0])
            self.canvas.delete(self.pause_text[1])
    def decide(self,obstacles,network):#take list of obstacles, get state, feed to network, decide on jump...
        plc=self.canvas.coords(self.id)#player coords
        state=[self.speed]
        for o in obstacles:
            loc=self.canvas.coords(o.lo)#get coords of hi and lo
            if 60<=loc[2]:#not passed yet...
                if len(state)==1:
                    state.append(loc[2]-60)#x difference
                state.append(loc[1]-((plc[1]+plc[3])/2) )#y difference
                if len(state)>=4:
                    break#take next 2 obstacles...
        while len(state)<4:
            state.append(500)
            state.append(0)
        #print(state)
        if state[1]>=250:#front part...
            return (plc[3]>=200)#jump if below middle line...
        try:
            out=network.think(array(state))[-1][0]
        except:
            print(state)
            raise Exception('gayyy')
        return (out>=0.5)

class Score:
    def __init__(self,canvas,colour):
        self.canvas=canvas
        self.score=0
        self.over=False
        self.paused=False
        self.end1=0
        self.end2=0
        self.id=self.canvas.create_text(650,15,text='Score: 0',fill='#FFFFFF')
        self.canvas.bind_all('<KeyPress-Left>',self.jump)
    def jump(self,evt):
        self.score-=100
        self.canvas.itemconfig(self.id,text='Score: '+str(self.score))
        self.canvas.tag_raise(self.id)
    def add(self):
        self.score+=1
        self.canvas.itemconfig(self.id,text='Score: '+str(self.score))
        self.canvas.tag_raise(self.id)
    def game_over(self):
        if self.over==True:
            return 0
        self.end1=self.canvas.create_rectangle(200,150,500,250,fill='#FFFFFF')
        try:
            lf=open('flappy_bird_hs','rb')
        except FileNotFoundError:
            sf=open('flappy_bird_hs','wb')
            pickle.dump(-1,sf)
            sf.close()
            lf=open('flappy_bird_hs','rb')
        hs=pickle.load(lf)
        lf.close()
        hs=str(hs)
        if self.score>int(hs):
            sf=open('flappy_bird_hs','wb')
            pickle.dump(self.score,sf)
            sf.close()
            hs=str(self.score)+"\nCongratulations on your high score!"
        self.end2=self.canvas.create_text(350,200,text='GAME OVER!\nScore: '+str(self.score)+'\nHigh score: '+hs)
        self.over=True

it=0
r=1
heights=[]
for i in range(500):#change the heights...
    heights.append(random.randint(1,3000))
def myrand(a,b):
    global it,heights
    it+=1
    it%=len(heights)
    return a+(heights[it]%(b-a+1) )
class Obstacle:
    def __init__(self,canvas,player,score):
        self.player=player
        self.canvas=canvas
        height=myrand(85,400-85-100)
        self.hi=self.canvas.create_rectangle(700,0,740,height-(30*r),fill='#228b22',outline='#228b22')
        #self.lo=self.canvas.create_rectangle(700,height+100-min(30,score.score),740,400,fill='#228b22',outline='#228b22')
        self.lo=self.canvas.create_rectangle(700,height+100-10+45*r,740,400,fill='#228b22',outline='#228b22')
        #make it narrower for more challenge, more effective to train...
        self.passed=False
        self.i=False
        self.score=score
        canvas.tag_raise(score.id)
        canvas.tag_raise(score.id)
        canvas.tag_raise(player.id)
        canvas.tag_raise(player.id)
    def update(self):
        self.canvas.move(self.hi,-4,0)
        self.canvas.move(self.lo,-4,0)
        hic=self.canvas.coords(self.hi)
        loc=self.canvas.coords(self.lo)
        plc=self.canvas.coords(self.player.id)
        #n
        if player.n==True:
            if self.i==False:
                if plc[3]+player.speed>=400:
                    self.i=True#(first one)
                elif loc[0]<198:
                    self.i=True
            if self.i==True:
                if loc[2]-1<=plc[0]:
                    self.i=False
            if self.i==True:
                if plc[3]+player.speed>loc[1]:#hic[3]<plc[1]-45:
                    if plc[2]<loc[0]:
                        if hic[3]<=plc[1]-47:
                            player.speed=-5
                    else:
                        player.speed=-5
        #check if touching
        plx=(plc[0]+plc[2])/2
        if plx<hic[0]:#not inside yet
            ply=(plc[1]+plc[3])/2
            if pow(hic[3]-ply,2)+pow(hic[0]-plx,2)<=100:
                self.player.game_over()
            if pow(loc[1]-ply,2)+pow(loc[0]-plx,2)<=100:
                self.player.game_over()
            if (plc[1]<=hic[3] or plc[3]>=loc[1]) and plc[2]>hic[0]:
                self.player.game_over()
        elif plx<=hic[2]:#currently inside
            if plc[1]<=hic[3] or plc[3]>=loc[1]:
                self.player.game_over()
        else:#out, but may not be completely out..
            ply=(plc[1]+plc[3])/2
            if pow(hic[3]-ply,2)+pow(hic[2]-plx,2)<=100:
                self.player.game_over()
            if pow(loc[1]-ply,2)+pow(loc[2]-plx,2)<=100:
                self.player.game_over()

        #update score
        if self.passed==False and (hic[0]+hic[2])/2<=plx:
            self.score.add()
            self.passed=True

        if hic[2]<=0:
            canvas.delete(self.hi)
            canvas.delete(self.lo)
            return False  #not relevant any more, so can delete already
        return True

tk=Tk()
tk.title("Flappy bird")
tk.resizable(0,0)
#tk.wm_attributes("-topmost",1)
canvas=Canvas(tk,width=700,height=400,bd=0,highlightthickness=0)
canvas.pack()
tk.lift()
tk.update()
canvas.create_rectangle(0,0,700,400,fill='#87CEFF',outline='#87CEFF')
score=Score(canvas,'black')
player=Bird(canvas,'yellow',score)
canvas.tag_raise(score.id)
tk.update()
tk.update_idletasks()
obstacles=[]
prev_results=[]

for gen in range(1000):#15 generations
    fitnesses=[]
    prev_results=[]#cos we change obstacles repeatedly
    for i in range(len(prev_results)):
        fitnesses.append([prev_results[i],networks[i]])
        print('Fitness:',prev_results[i])
    for net in networks[len(prev_results):] :
        fitness_val=0

        for i in range(5):#play 5 games...
            it=100*i
            #play with the net...
            canvas.delete(player.id)
            canvas.delete(score.id)
            canvas.delete(score.end1)
            canvas.delete(score.end2)
            while len(obstacles)>0:
                canvas.delete(obstacles[0].hi)
                canvas.delete(obstacles[0].lo)
                del obstacles[0]
            score=Score(canvas,'black')
            player=Bird(canvas,'yellow',score)
            canvas.tag_raise(score.id)
            cnt=40#use as fitness

            while True:
                if player.decide(obstacles,net):
                    player.jump(None)
                player.update()
                cnt+=1#will use as
                if (cnt%50)==0:
                    obstacles.append(Obstacle(canvas,player,score))
                i=0
                while i<len(obstacles):
                    if obstacles[i].update()==False:
                        del obstacles[i]
                    else:
                        i+=1
                #tk.update() #just dao updating screen...
                #tk.update_idletasks()
                if score.over==True:
                    break
                #time.sleep(0.01)
            fitness_val+=cnt
        fitness_val/=5#since 5 games...

        fitnesses.append([fitness_val,net])
        print('Fitness:',fitness_val)

    #based on the fitnesses, tweak networks
    print("Next generation!!")
    heights=[]
    for i in range(500):#change the heights...
        heights.append(random.randint(1,3000))
    r-=0.005
    fitnesses.sort(reverse=True,key=lambda x:x[0])#sort by fitness value...

    next_gen=[]
    prev_results=[]
    for i in range(5):#let's be elitist...
        next_gen.append(fitnesses[i][1])
        prev_results.append(fitnesses[i][0])
    for i in range(5):#reproduce 5...
        a=random.randint(0,9)
        b=random.randint(0,8)
        if b>=a:b+=1#pick 2 from top 10...
        if True or enn.equal(fitnesses[a][1],fitnesses[b][1]):
            next_gen.append(copy.deepcopy(fitnesses[a][1]) )
            enn.mutate(next_gen[-1])
        else:
            next_gen.append(enn.reproduce(fitnesses[a][1],fitnesses[b][1]) )
    for i in range(5):#mutate 5...
        model=fitnesses[random.randint(0,7)][1]
        next_gen.append(copy.deepcopy(model) )
        enn.mutate(next_gen[-1])
    networks=next_gen
    enn.save('population.dat',networks)
    time.sleep(5)