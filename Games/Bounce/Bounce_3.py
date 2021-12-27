from tkinter import*
import time
import random
class Score:
    def __init__(self,canvas,y_pos,color):
        self.canvas=canvas
        self.score=0
        self.id=canvas.create_text(50,y_pos,text=('Score: %s ' % self.score),fill=color)
    def add(self):
        self.score += 1
        self.canvas.itemconfig(self.id,text=('Score: %s ' % self.score))
    def check(self):
        if self.score==10:
            return True
        return False
class Ball:
    def __init__(self,p1,p2,canvas,score1,score2):
        self.canvas=canvas
        self.p1=p1
        self.p2=p2
        self.score1=score1
        self.score2=score2
        self.id=canvas.create_oval(243,243,257,257,fill='yellow')
        starts=[-2,-1,1,2]
        self.x=random.choice(starts)
        starts=[-3,3]
        self.y=random.choice(starts)
    def tp1(self,pos):
        pos=self.canvas.coords(self.id)
        pos1=self.canvas.coords(self.p1.id)
        if pos[0]>=pos1[0] and pos[2]<=pos1[2]:
            if pos[3]>=pos1[1] and pos[3]<=pos1[3]:
                self.x+=self.p1.x
                return True
        return False
    def tp2(self,pos):
        pos=self.canvas.coords(self.id)
        pos1=self.canvas.coords(self.p2.id)
        if pos[0]>=pos1[0] and pos[2]<=pos1[2]:
            if pos[3]>=pos1[1] and pos[3]<=pos1[3]:
                self.x+=self.p2.x
                return True
        return False
    def move(self):
        for x in range(1):
            self.canvas.move(self.id,self.x,self.y)
            pos=self.canvas.coords(self.id)
            if self.tp1(pos)==True or self.tp2(pos)==True:
                self.y=self.y*-1
            if pos[1]<=0:
                self.score1.add()
                self.canvas.move(self.id,120-pos[0],245-pos[1])
                starts=[-2,-1,1,2]
                self.x=random.choice(starts)
                self.y=-3
                self.p1.r()
                self.p2.r()
                time.sleep(1)
            if pos[3]>=500:
                self.score2.add()
                self.canvas.move(self.id,120-pos[0],245-pos[1])
                starts=[-2,-1,1,2]
                self.x=random.choice(starts)
                self.y=3
                self.p1.r()
                self.p2.r()
                time.sleep(1)
            if pos[0]<=0:
                self.x=3
            if pos[2]>=500:
                self.x=-3
class Paddle:
    def __init__(self,player_no,canvas):
        self.x=0
        self.canvas=canvas
        if player_no==1:
            self.canvas.bind_all('<KeyPress-Up>',self.stop)
            self.canvas.bind_all('<KeyPress-Down>',self.faster)
            self.canvas.bind_all('<KeyPress-Left>',self.left)
            self.canvas.bind_all('<KeyPress-Right>',self.right)
            self.id=self.canvas.create_rectangle(200,450,300,460,fill='blue')
        elif player_no==2:
            self.canvas.bind_all('<KeyPress-w>',self.stop)
            self.canvas.bind_all('<KeyPress-s>',self.faster)
            self.canvas.bind_all('<KeyPress-a>',self.left)
            self.canvas.bind_all('<KeyPress-d>',self.right)
            self.id=self.canvas.create_rectangle(200,40,300,50,fill='red')
    def left(self,evt):
        self.x=-4
    def right(self,evt):
        self.x=4
    def stop(self,evt):
        self.x=0
    def faster(self,evt):
        self.x=(self.x)*2
    def move(self):
        self.canvas.move(self.id,self.x,0)
        pos=self.canvas.coords(self.id)
        if pos[0]<=0 or pos[2]>=500:
            self.x=0
    def r(self):
        pos=self.canvas.coords(self.id)
        self.canvas.move(self.id,200-pos[0],0)
        self.x=0
tk=Tk()
tk.title("BOUNCE  3")
tk.resizable(0,0)
tk.wm_attributes("-topmost",1)
canvas=Canvas(tk,width=500,height=500,bd=0,highlightthickness=0)
canvas.pack()
score1=Score(canvas,450,'blue')
score2=Score(canvas,50,'red')
p1=Paddle(1,canvas)
p2=Paddle(2,canvas)
ball=Ball(p1,p2,canvas,score1,score2)
time.sleep(1)
while True:
    ball.move()
    p1.move()
    p2.move()
    if score1.check()==True:
        canvas.create_text(250,125,text='The winner is player 1!!! Congratulations!')
        break
    if score2.check()==True:
        canvas.create_text(250,125,text='The winner is player 2!!! Congratulations!')
        break
    ball.move()
    tk.update_idletasks()
    tk.update()
    time.sleep(0.01)
