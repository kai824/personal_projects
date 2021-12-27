#Shooting
print("What is your name?")
q=input()
from tkinter import*
import random
import time
import math
import pickle
class Shooter: #Player
    def __init__(self,canvas,planes,score):
        self.canvas=canvas
        self.x=0
        self.score=score
        self.planes=planes
        self.bullets=[]
        self.b=99999999999999999999999
        self.a=0#number of bullets
        self.paused=False
        self.id=canvas.create_polygon(250,400,230,440,270,440,fill='green')
        self.score.shooter_set(self)
        self.canvas.bind_all('<KeyPress-Left>',self.left)
        self.canvas.bind_all('<KeyPress-Right>',self.right)
        self.canvas.bind_all('<KeyPress-Up>',self.shoot)
        self.canvas.bind_all('<KeyPress-a>',self.stop)
        self.canvas.bind_all('<KeyPress-y>',self.cheat)
    def pause(self):
        if self.paused==True:
            self.paused=False
        else:
            self.paused=True
        for x in range(len(self.planes)):
            self.planes[x].pause()
    def stop(self,evt):
        self.x=0
    def left(self,evt):
        self.x=-4
    def right(self,evt):
        self.x=4
    def draw(self,planes):
        self.planes=planes
        p_pos=self.canvas.coords(self.id)
        if (not ((p_pos[2]<=0 and self.x<=0) or (p_pos[4]>=500 and self.x>=0))) and self.paused==False:
            self.canvas.move(self.id,self.x,0)
            
        for x in range(0,len(self.bullets)):
            if self.paused==True:
                continue
            if self.bullets!=[]:
                pos=self.canvas.coords(self.bullets[x])
                if pos[0]<=0:
                    del self.bullets[x]
                else:
                    self.canvas.move(self.bullets[x],0,-3)
                for y in range(len(self.planes)):
                    e_pos=self.canvas.coords(self.planes[y].id)
                    if e_pos!=[]:
                        e_pos=[(e_pos[0]+e_pos[2])/2,(e_pos[1]+e_pos[3])/2]
                        if math.sqrt(pow(abs(pos[0]-e_pos[0]),2)+pow(abs(pos[1]-e_pos[1]),2))<=25:
                            self.planes[y].hide()
                            self.score.hit()
                        elif math.sqrt(pow(abs(pos[2]-e_pos[0]),2)+pow(abs(pos[1]-e_pos[1]),2))<=25:
                            self.planes[y].hide()
                            self.score.hit()
                        elif math.sqrt(pow(abs(pos[0]-e_pos[0]),2)+pow(abs(pos[3]-e_pos[1]),2))<=25:
                            self.planes[y].hide()
                            self.score.hit()
                        elif math.sqrt(pow(abs(pos[2]-e_pos[0]),2)+pow(abs(pos[3]-e_pos[1]),2))<=25:
                            self.planes[y].hide()
                            self.score.hit()
    def shoot(self,evt):
        p_pos=self.canvas.coords(self.id)
        if self.a<100:
            self.a += 1
            self.bullets.append(canvas.create_rectangle(p_pos[0],400,p_pos[0]+5,415,fill='yellow'))
        elif time.time()-self.b>=3:
            self.a=0
            self.b=99999999999999999999999
        elif self.b==99999999999999999999999:
            self.b=time.time()
    def reset(self):
        p_pos=self.canvas.coords(self.id)
        self.x=0
        self.canvas.move(self.id,250-p_pos[0],0)
        for x in range(len(self.bullets)):#Deletes all the on-screen bullets
            self.canvas.delete(self.bullets[x])
        self.bullets=[]
    def cheat(self,evt):
        for x in range(len(self.planes)):
            self.planes[x].hide()
            self.score.hit()
class Plane:#Enemy
    def __init__(self,canvas,color):
        self.y=2
        self.starts=[-4,-3,3,4]
        self.x=random.choice(self.starts)
        if self.x<0:
            self.change=[random.randint(0,175),-1]
        else:
            self.change=[random.randint(275,450),1]
        self.canvas=canvas
        self.ended=False
        self.defeated=False
        self.paused=False
        self.id=canvas.create_oval(225,0,275,50,fill=color)
    def pause(self):
        if self.paused==False:
            self.paused=True
        else:
            self.paused=False
    def draw(self):
        if self.paused==False:
            self.canvas.move(self.id,self.x,self.y)
            pos=self.canvas.coords(self.id)
            try:
                if pos[3]>=480:
                    self.ended=True
                if self.change[1]==-1 and pos[0]<=self.change[0]:
                    self.x=abs(random.choice(self.starts))
                    self.change=[random.randint(pos[0]+50,450),1]
                elif self.change[1]==1 and pos[0]>=self.change[0]:
                    self.x=0-abs(random.choice(self.starts))
                    self.change=[random.randint(0,pos[0]-50),-1]
            except IndexError:
                pass
    def hide(self):
        self.canvas.delete(self.id)
        self.defeated=True
class Score:
    def __init__(self,canvas,q):
        self.score=0
        self.canvas=canvas
        self.q=q
        self.id=canvas.create_text(450,10,text=('Score: %s' % self.score),fill='Green')
        self.canvas.bind_all('<KeyPress-p>',self.pause)
    def shooter_set(self,shooter):
        self.shooter=shooter
    def pause(self,evt):
        self.shooter.pause()
    def hit(self):
        self.score += 1
        self.canvas.itemconfig(self.id,text=('Score: %s' % self.score))
    def helpa(self):
        load_file=open('shooting_high score','rb')
        a=pickle.load(load_file)
        load_file.close()
        load_file=open('shooting_name','rb')
        b=pickle.load(load_file)
        load_file.close()
        if self.score>=a[0]:
            c=[self.score,a[0],a[1]]
            sf=open('shooting_high score','wb')
            pickle.dump(c,sf)
            sf.close()
            c=[self.q,b[0],b[1]]
            sf=open('shooting_name','wb')
            pickle.dump(c,sf)
            sf.close()
            self.canvas.create_text(250,250,text='Hooray, you achieved a high score!')
            self.canvas.create_text(250,260,text=('2. %s' % a[0]))
            self.canvas.create_text(250,270,text=('(by %s)' % b[0]))
            self.canvas.create_text(250,280,text=('3. %s' % a[1]))
            self.canvas.create_text(250,290,text=('(by %s)' % b[1]))
        elif self.score>=a[1]:
            c=[a[0],self.score,a[1]]
            sf=open('shooting_high score','wb')
            pickle.dump(c,sf)
            sf.close()
            c=[b[0],self.q,b[1]]
            sf=open('shooting_name','wb')
            pickle.dump(c,sf)
            sf.close()
            self.canvas.create_text(250,250,text='Hooray,you achieved a second highest score!')
            self.canvas.create_text(250,260,text=('1. %s' % a[0]))
            self.canvas.create_text(250,270,text=('(by %s)' % b[0]))
            self.canvas.create_text(250,280,text=('3. %s' % a[1]))
            self.canvas.create_text(250,290,text=('(by %s)' % b[1]))
        elif self.score>=a[2]:
            c=[a[0],a[1],self.score]
            sf=open('shooting_high score','wb')
            pickle.dump(c,sf)
            sf.close()
            c=[b[0],b[1],self.q]
            sf=open('shooting_name','wb')
            pickle.dump(c,sf)
            sf.close()
            self.canvas.create_text(250,250,text='Hooray,you achieved a third highest score!')
            self.canvas.create_text(250,260,text=('1. %s' % a[0]))
            self.canvas.create_text(250,270,text=('(by %s)' % b[0]))
            self.canvas.create_text(250,280,text=('2. %s' % a[1]))
            self.canvas.create_text(250,290,text=('(by %s)' % b[1]))
        else:
            self.canvas.create_text(250,250,text='Game Over')
            self.canvas.create_text(250,260,text=('1. %s' % a[0]))
            self.canvas.create_text(250,270,text=('(by %s)' % b[0]))
            self.canvas.create_text(250,280,text=('2. %s' % a[1]))
            self.canvas.create_text(250,290,text=('(by %s)' % b[1]))
            self.canvas.create_text(250,300,text=('3. %s' % a[2]))
            self.canvas.create_text(250,310,text=('(by %s)' % b[2]))
tk=Tk()
tk.title("Pew Pew!!!")
tk.resizable(0,0)
tk.wm_attributes("-topmost",1)
canvas=Canvas(tk,width=500,height=500,bd=0,highlightthickness=0)
canvas.pack()
tk.update()
canvas.create_text(250,10,text='Protect your base from invaders',fill='red')
canvas.create_rectangle(0,300,500,500,fill='orange')
canvas.create_text(250,385,text='Danger Zone',fill='white')
canvas.create_rectangle(0,475,500,500,fill='red')
canvas.create_text(250,487,text='Base',fill='white')
score=Score(canvas,q)
planes=[Plane(canvas,'Blue')]
shooter=Shooter(canvas,planes,score)
level=1
level_text=canvas.create_text(390,10,text=('Level: %s' % level),fill='orange')
def defeated(planes):
    defeated_planes=0
    for z in range(len(planes)):
        if planes[z].defeated==True:
            defeated_planes += 1
    if defeated_planes==len(planes):
        return True
    else:
        return False
def ended(planes):
    ended=False
    for z in range(len(planes)):
        if planes[z].ended==True:
            ended=True
            break
    return ended
time.sleep(3)
for x in range(2,100000000000000000000001):
    while 1:
        shooter.draw(planes)
        for y in range(len(planes)):
            planes[y].draw()
        if ended(planes)==True:
            break
        elif defeated(planes)==True:
            break
        tk.update()
        tk.update_idletasks()
        time.sleep(0.01)
    if ended(planes)==True:
        break
    level += 1
    canvas.itemconfig(level_text,text=('Level: %s' % level))
    shooter.reset()
    for y in range(x):
        planes.append(Plane(canvas,'Blue'))
    tk.update()
    tk.update_idletasks()
    time.sleep(1)
score.helpa()
