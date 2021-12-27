from tkinter import*
import time
import random
import pickle
import random

import tensorflow as tf
from numpy import array

print('want u back')
gen_no=int(input("Gen no: "))
if gen_no>0:#not from scratch
    f=open('losses.dat','rb')
    losses=pickle.load(f)
    f.close()
else:
    losses=[]

exploration_rate=float(input("exploration_rate") )#1 - (gen_no*0.0005)#also known as epilson
discount=0.9
reward=0#idk, maybe it won't make sense to the network since the space is continuous?

try:
    model = tf.keras.models.load_model('attempt.h5')
except OSError:
    model = tf.keras.models.Sequential([
      tf.keras.layers.Flatten(input_shape=(5,)),
      tf.keras.layers.Dense(6, activation='relu'),
      tf.keras.layers.Dense(6, activation='relu'),
      #attempt1.h5 uses sigmoid here, may face diminishing gradient
      #tf.keras.layers.Dropout(0.2),
      tf.keras.layers.Dense(2, activation='linear'),#actions: 0 for nothing, 1 for jump
    ])

opt=tf.keras.optimizers.Adam(#to change learning rate, since defsult of 0.001 causes divergence
    learning_rate=3e-4
)
model.compile(optimizer=opt,
              loss='mse',)
target_net=tf.keras.models.clone_model(model)
#let's do double dqn cos easy imple anyway
quick_check={}
def target_query(state):
    state2=tuple(state)
    if state2 in quick_check:
        return quick_check[state2]
    v=target_net.predict(array([state]) )[0]
    quick_check[state2]=v
    return v

class Bird:
    def __init__(self,canvas,colour,score,old_states=None):#old failing states LOL
        self.speed=0.1
        self.deceleration=30
        self.canvas=canvas
        self.score=score
        self.paused=False
        self.started=False
        self.press=False
        self.quit=False
        self.died=False
        self.n=False#CHANGE HERE!!!
        self.pause_text=()
        self.id=self.canvas.create_oval(40,190,60,210,fill=colour,outline=colour)
        self.canvas.bind_all('<ButtonPress-1>',self.jump)
        self.canvas.bind_all('<space>',self.jump)
        self.canvas.bind_all('<KeyPress-m>',self.pause)
        self.canvas.bind_all('<KeyPress-n>',self.nn)
        self.canvas.bind_all('<KeyPress-q>',self.end)

        if old_states==None:
            self.old_states=[]
        else:
            self.old_states=old_states#if used, stores the old states for memory...
        self.states=[]
    def nn(self,evt):
        if self.n==False:
            self.n=True
        else:
            self.n=False
    def end(self,evt):
        self.quit=True
    def game_over(self):
        #tk.update()
        #tk.update_idletasks()
        self.speed=0
        '''time.sleep(0.3)
        self.died=True
        while True:
            self.speed+=self.deceleration/100
            self.canvas.move(self.id,0,self.speed)
            coords=self.canvas.coords(self.id)
            if coords[3]>=400:
                break
            tk.update()
            tk.update_idletasks()
            time.sleep(0.01)'''
        self.score.game_over()
        self.jump(None)
    def update(self):
        self.canvas.move(self.id,0,self.speed)
        self.speed+=self.deceleration/(1/0.01)
        coords=self.canvas.coords(self.id)
        if coords[3]>400 or coords[1]<0:
            self.game_over()
    def save_states(self,obstacles):
        plc=self.canvas.coords(self.id)#player coords
        state=[self.speed]
        for o in obstacles:
            hic=self.canvas.coords(o.hi)
            loc=self.canvas.coords(o.lo)#get coords of hi and lo
            if 60<=hic[2]:#not passed yet...
                state.append(loc[2]-60)#x difference
                state.append(loc[1]-((plc[1]+plc[3])/2) )#y difference
                if len(state)>=5:
                    break#take next 2 obstacles...

        while len(state)<5:
            state.append(500)#very far away...
            state.append(0)#just assume at your height...

        state[1]/=100#make these stuff less important...
        state[3]/=100
        state[2]/=10
        state[4]/=10

        if state[1]>=2.5:#front part...
            if plc[3]>=200:#jump if below middle line...
                self.jump(None)
            return None

        if len(self.states)>=1000:
            del self.states[0]

        #self.states.append([state,0.5])
        #return None

        opt1,opt2=model.predict(array([state]) )[0]#q-value for each action...
        jumped=0

        if random.random()<=exploration_rate:#just explore
            if random.randint(1,65)==1:
                self.jump(None)
                jumped=1
        elif opt1<opt2:#jumping more likely to survive...
            self.jump(None)
            jumped=1
        self.states.append([state,jumped,opt1,opt2])
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
heights=[104, 109, 196, 161, 83, 76, 155, 60, 167, 43, 167, 103, 62, 124, 130, 119, 73, 195, 154, 197, 145, 85, 135, 33, 128, 118, 182, 4, 199, 94]
def myrand(a,b):
    global it,heights
    it+=1
    it%=len(heights)
    return a+(heights[it]%(b-a+1) )
class Obstacle:
    def __init__(self,canvas,player,score):
        self.player=player
        self.canvas=canvas
        height=myrand(85,400-85-100)#random.randint(85,400-85-100)
        self.hi=self.canvas.create_rectangle(700,0,740,height- (0.01*max(0,5000) ),fill='#228b22',outline='#228b22')
        self.lo=self.canvas.create_rectangle(700,height+100-min(30,score.score),740,400,fill='#228b22',outline='#228b22')
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
obstacles=[]
old_states=[]
cnt=40
game_cnt=0
tk.update()
tk.update_idletasks()
while True:
    if player.quit==True:
        #save the model
        model.save('attempt.h5')
        canvas.destroy()
        tk.destroy()
        break
    if player.started==False or player.paused==True:
        #tk.update()
        #tk.update_idletasks()
        time.sleep(0.05)
        player.started=True#force start, since this loop waiting for player to start...
        continue
    player.update()
    cnt+=1
    if cnt==50:
        cnt=0
        obstacles.append(Obstacle(canvas,player,score))
    i=0
    while i<len(obstacles):
        if obstacles[i].update()==False:
            del obstacles[i]
        else:
            i+=1
    player.save_states(obstacles)#save surviving states...
    #tk.update()
    #tk.update_idletasks()
    if score.over==True:
        player.press=False
        while player.press==False:
            if player.quit==True:
                canvas.destroy()
                tk.destroy()
                break
            tk.update()
            tk.update_idletasks()
            player.press=True
            time.sleep(0.05)
        if player.quit==True:
            break
        canvas.delete(player.id)
        canvas.delete(score.id)
        canvas.delete(score.end1)
        canvas.delete(score.end2)
        while len(obstacles)>0:
            canvas.delete(obstacles[0].hi)
            canvas.delete(obstacles[0].lo)
            del obstacles[0]
        #train the model...model.fit(x,y,epochs=100)

        cur_pairs=[]
        for i in range(len(player.states)):#can prolly instead do random sampling from memory, but wtv
            #train the state to give the ideal stuff
            s,a,opt1,opt2=player.states[i]
            arr=[opt1,opt2]#list(model.predict(array([s]))[0] )
            a=int(a)
            if i==len(player.states)-1:#no next state
                xx= -1000
            else:
                next_state=array(player.states[i+1][0])
                l=list(target_query(next_state))
                xx=reward+discount*max(l)#next state
            diff=abs(arr[a]-xx)
            arr[a]=xx
            #reward + next phase
            cur_pairs.append( (diff,[s,arr]) )
        cur_pairs.sort(key=lambda x:x[0],reverse=True)
        old_pairs=[]
        for i in range(len(old_states)):#can prolly instead do random sampling from memory, but wtv
            #train the state to give the ideal stuff
            s,a,opt1,opt2=old_states[i]
            arr=list(model.predict(array([s]))[0] )
            a=int(a)
            if i==len(old_states)-1:#no next state
                xx=-1000
            else:
                next_state=array(old_states[i+1][0])
                l=list(target_query(next_state) )
                xx=reward+discount*max(l)#next state
            diff=abs(arr[a]-xx)
            arr[a]=xx
            #reward + next phase
            old_pairs.append( (diff,[s,arr]) )
        old_pairs.sort(key=lambda x:x[0],reverse=True)

        pairs=[]
        for i in range(min(15,len(old_pairs))):
            pairs.append(old_pairs[i][1])
        for i in range(min(40,int(len(cur_pairs)*0.8) ) ):
            pairs.append(cur_pairs[i][1])
            #print('diff:',cur_pairs[i][0],'stuff:',cur_pairs[i][1])
        random.shuffle(pairs)
        old_states=player.states

        xx,yy=[],[]
        for p in pairs:
            state=p[0]
            xx.append(state)
            yy.append(p[1])

        xx=array(xx)
        yy=array(yy)
        print('training')
        loss=model.train_on_batch(xx,yy,return_dict=True)['loss']
        losses.append(loss)
        sf=open('losses.dat','wb')
        pickle.dump(losses,sf)
        sf.close()
        game_cnt+=1
        if game_cnt>=20:#higher = more stable
            game_cnt=0
            target_net=tf.keras.models.clone_model(model)
            quick_check={}
        print('ok trained, saving weights')
        model.save('attempt.h5')
        print('saved')
        gen_no+=1
        print('YEETUS',len(player.states),gen_no,loss)
        time.sleep(1)
        #exploration_rate-=0.0005#every 0.1 exploration rate diminishes in 200 plays
        it=0


        score=Score(canvas,'black')
        #player=Bird(canvas,'yellow',score,old_states=player.states+player.old_states)#bring old states to the new bird object...
        player=Bird(canvas,'yellow',score)
        canvas.tag_raise(score.id)
        obstacles=[]
        cnt=40
    time.sleep(0.01)