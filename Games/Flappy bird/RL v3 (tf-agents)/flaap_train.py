from fake_tkinter import*
import time
import random
import pickle
import random

import tensorflow as tf
import numpy as np
from tf_agents.environments import *
from tf_agents.specs import array_spec
from tf_agents.trajectories import time_step as ts
from numpy import array

total_gen=1000
gen_no=1

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

        self.q=[]
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
        self.score.game_over()
        self.jump(None)
    def update(self):
        self.canvas.move(self.id,0,self.speed)
        self.speed+=self.deceleration/(1/0.01)
        coords=self.canvas.coords(self.id)
        if coords[3]>400 or coords[1]<0:
            self.game_over()
    def save_states(self,obstacles,jump=False):
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
            state.append(1000)#very far away...
            state.append(0)#just assume at your height...

        if state[1]>=250:#front part...
            if plc[3]>=200:#jump if below middle line...
                self.jump(None)
            return "No state"#front part, which we will manually handle...

        if len(self.states)>=3000:#man, if only...
            del self.states[0]

        # opt1,opt2=model.predict(array([state]) )[0]#q-value for each action...
        # jumped=0
        #
        # if random.random()<=exploration_rate:#just explore
        #     if random.randint(1,45)==1:
        #         self.jump(None)
        #         jumped=1
        # elif opt1<opt2:#jumping more likely to survive...
        #     self.jump(None)
        #     jumped=1
        # self.q.append(max(opt1,opt2))
        if jump:self.jump(None)
        self.states.append(state)
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

def myrand(a,b):
    return random.randint(a,b)
class Obstacle:
    def __init__(self,canvas,player,score):
        self.player=player
        self.canvas=canvas
        height=myrand(85,400-85-100)#random.randint(85,400-85-100)
        self.hi=self.canvas.create_rectangle(700,0,740,height- ((50/total_gen)*max(0,total_gen-gen_no) ),fill='#228b22',outline='#228b22')
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


tk=canvas=score=player=obstacles=cnt=None
def start_game():
    global tk,canvas,score,player,obstacles,cnt
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
    cnt=40
def reset_game():
    global tk,canvas,score,player,obstacles,cnt
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
    # if player.quit==True:
    #     break
    canvas.delete_all()
    obstacles=[]

    score=Score(canvas,'black')
    #player=Bird(canvas,'yellow',score,old_states=player.states+player.old_states)#bring old states to the new bird object...
    player=Bird(canvas,'yellow',score)
    canvas.tag_raise(score.id)
    obstacles=[]
    cnt=40

class FlappyEnv(py_environment.PyEnvironment):
    def __init__(self):
        self._action_spec = array_spec.BoundedArraySpec(
            shape=(), dtype=np.int32, minimum=0, maximum=1, name='jump')#jump or nah
        self._observation_spec = array_spec.BoundedArraySpec(
            shape=(5,), dtype=np.float32, minimum=[-25.0,0,-400,0,-400], maximum=[25.0,700,400,700,400], name='game_state')
        self._state = [0, 1000,0,1000,0]#speed, and x, y difference of both in initial stage...
        self._episode_ended = False

        start_game()
    def action_spec(self):
        return self._action_spec
    def observation_spec(self):
        return self._observation_spec
    def _reset(self):#restart...
        self._state=[0, 1000,0,1000,0]#initial state...
        self._episode_ended=False
        reset_game()
        return ts.restart(np.array(self._state,dtype=np.float32))
    def inc(self,delta):
        global gen_no
        gen_no+=delta

    def _step(self,action):
        global tk,canvas,score,player,obstacles,cnt
        last="Keep going"
        while last!=None:
            player.started=True
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
            last=player.save_states(obstacles,jump=(action==1) )#save surviving states...
        self._state=player.states[-1]
        if score.over:
            return ts.termination(np.array(self._state,dtype=np.float32),-100)#state, reward...
        return ts.transition(np.array(self._state,dtype=np.float32),reward=0.05,discount=0.9)
#
#
#
#
#
#
#
#
#
#
# tk=Tk()
# tk.title("Flappy bird")
# tk.resizable(0,0)
# #tk.wm_attributes("-topmost",1)
# canvas=Canvas(tk,width=700,height=400,bd=0,highlightthickness=0)
# canvas.pack()
# tk.lift()
# tk.update()
# canvas.create_rectangle(0,0,700,400,fill='#87CEFF',outline='#87CEFF')
# score=Score(canvas,'black')
# player=Bird(canvas,'yellow',score)
# canvas.tag_raise(score.id)
# obstacles=[]
# cnt=40
# game_cnt=0
# tk.update()
# tk.update_idletasks()
# while True:
#     if player.quit==True:
#         #save the model
#         canvas.destroy()
#         tk.destroy()
#         break
#     if player.started==False or player.paused==True:
#         #tk.update()
#         #tk.update_idletasks()
#         time.sleep(0.05)
#         player.started=True#force start, since this loop waiting for player to start...
#         continue
#     player.update()
#     cnt+=1
#     if cnt==50:
#         cnt=0
#         obstacles.append(Obstacle(canvas,player,score))
#     i=0
#     while i<len(obstacles):
#         if obstacles[i].update()==False:
#             del obstacles[i]
#         else:
#             i+=1
#     player.save_states(obstacles)#save surviving states...
#     #tk.update()
#     #tk.update_idletasks()
#     if score.over==True:
#         player.press=False
#         while player.press==False:
#             if player.quit==True:
#                 canvas.destroy()
#                 tk.destroy()
#                 break
#             tk.update()
#             tk.update_idletasks()
#             player.press=True
#             time.sleep(0.05)
#         if player.quit==True:
#             break
#         canvas.delete(player.id)
#         canvas.delete(score.id)
#         canvas.delete(score.end1)
#         canvas.delete(score.end2)
#         while len(obstacles)>0:
#             canvas.delete(obstacles[0].hi)
#             canvas.delete(obstacles[0].lo)
#             del obstacles[0]
#         #train the model...model.fit(x,y,epochs=100)
#
#         # for i in range(len(player.states)):#can prolly instead do random sampling from memory, but wtv
#         #     if i+1<len(player.states):
#         #         memory.append([abs(player.q[i]-player.q[i+1]),player.states[i],player.states[i+1] ] )
#         #     else:
#         #         memory.append([abs(player.q[i]-(-1000) ),player.states[i],None] )
#         #     memory[-1][0]*=1.005**gen_no
#         #     RngTree.nodes[nex_it].update(memory[-1][0])#update the TD-error into segtree
#         #     nex_it+=1
#         #     nex_it%=len(memory)
#         # while len(memory)>REPLAY_SIZE:
#         #     memory.popleft()
#         #
#         # batch=[]
#         # xx,yy=[],[]
#         # for i in range(BATCH_SIZE):
#         #     l=[]
#         #     T.sample(l)
#         #     node=l[0]
#         #     true_it=(node.s-nex_it+len(memory))%len(memory)
#         #     error,state,nex_state=memory[true_it]
#         #
#         #     s,a=state
#         #
#         #     arr=list(model.predict(array([s]))[0] )
#         #     a=int(a)
#         #     if nex_state==None:
#         #         neww=-1000
#         #     else:
#         #         s2=array(nex_state[0])
#         #         l=list(target_query(s2) )
#         #         neww=reward+(discount*max(l) )
#         #     memory[true_it][0]=abs(arr[a]-neww) * (1.005**gen_no)#update the error
#         #     node.update(memory[true_it][0])
#         #     arr[a]=neww
#         #
#         #     xx.append(s)
#         #     yy.append(arr)
#         #
#         # xx=array(xx)
#         # yy=array(yy)
#         # print('training')
#         # loss=model.train_on_batch(xx,yy,return_dict=True)['loss']
#         # losses.append(loss)
#         # sf=open('losses.dat','wb')
#         # pickle.dump(losses,sf)
#         # sf.close()
#         # sf=open('cache.dat','wb')
#         # pickle.dump(memory,sf)
#         # sf.close()
#         #
#         # game_cnt+=1
#         # if game_cnt>=20:#higher = more stable
#         #     game_cnt=0
#         #     target_net=tf.keras.models.clone_model(model)
#         #     quick_check={}
#         # print('ok trained, saving weights')
#         # model.save('attempt.h5')
#         # print('saved')
#         # gen_no+=1
#         # print('YEETUS',len(player.states),gen_no,loss)
#         #time.sleep(1)
#         exploration_rate-=(1/total_gen)#linear annealing
#         it=0
#
#
#         score=Score(canvas,'black')
#         #player=Bird(canvas,'yellow',score,old_states=player.states+player.old_states)#bring old states to the new bird object...
#         player=Bird(canvas,'yellow',score)
#         canvas.tag_raise(score.id)
#         obstacles=[]
#         cnt=40
#     time.sleep(0.01)
