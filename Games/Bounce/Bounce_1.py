from tkinter import*
import random
import time
import pickle
print("What is your name?")
q=input()
b=0
class Ball:
    def __init__(self,canvas,paddle,score,color):
        self.canvas=canvas
        self.paddle=paddle
        self.score=score
        self.speed=1
        self.id=canvas.create_oval(10,10,25,25, fill=color)
        self.canvas.move(self.id,245,100)
        starts=[-3,-2,-1,1,2,3]
        random.shuffle(starts)
        self.x=starts[0]
        self.y=-3
        self.canvas_height=self.canvas.winfo_height()
        self.canvas_width=self.canvas.winfo_width()
        self.hit_bottom=False
        self.paused=False
        self.cheating=False
        self.spin=0 #in clockwise direction
        self.canvas.bind('<KeyPress-p>',self.pause)
        self.canvas.bind_all('<KeyPress-q>',self.cheat)
    def pause(self,evt):
        if self.paused==False:
            self.x_2=self.x
            self.y_2=self.y
            self.x=0
            self.y=0
            self.paused=True
        else:
            self.x=self.x_2
            self.y=self.y_2
            self.paused=False
        self.paddle.pause()
    def hit_paddle(self,pos):
        if self.paused==False:
            paddle_pos=self.canvas.coords(self.paddle.id)
            if pos[2]>=paddle_pos[0] and pos[0]<=paddle_pos[2]:
                if pos[3]>=paddle_pos[1] and pos[3]<=paddle_pos[3]:
                    self.x+=self.paddle.x
                    self.score.hit()
                    self.spin -= self.paddle.x
                    return True
            return False
    def draw(self):
        self.canvas.move(self.id, (self.x*self.speed), (self.y*self.speed))
        pos=self.canvas.coords(self.id)
        if pos[1]<= 0:
            self.y=1
            self.x -= self.spin
            self.spin=self.spin/10
        if pos[3] >= self.canvas_height:
            self.hit_bottom=True
        if self.hit_paddle(pos)==True:
            self.y=-3
            if self.x==0 and self.cheating==False:
                starts=[-1,1]
                random.shuffle(starts)
                self.x=starts[0]
        if pos[0] <= 0:
            self.x=3
            self.y += self.spin
            self.spin = self.spin/10
        if pos[2] >= self.canvas_width:
            self.x=-3
            self.y -= self.spin
            self.spin = self.spin/10
    def level_up(self):
        self.speed += 0.5
    def cheat(self,evt):
        if self.cheating==True:
            self.cheating=False
        else:
            self.cheating=True
            self.x=0
            self.spin=0
            
class Paddle:
    def __init__(self,canvas,color):
        self.canvas=canvas
        self.id=canvas.create_rectangle(0,0,100,10,fill=color)
        self.canvas.move(self.id,200,300)
        self.x=0
        self.canvas_width=self.canvas.winfo_width()
        self.paused_2=False
        self.speed=1
        self.canvas.bind_all('<KeyPress-Left>',self.turn_left)
        self.canvas.bind_all('<KeyPress-Right>',self.turn_right)
        self.canvas.bind_all('<KeyPress-s>',self.faster)
        self.canvas.bind_all('<KeyPress-a>',self.stop)
    def draw(self):
        if self.paused_2==False:
            self.canvas.move(self.id,(self.x*self.speed),0)
            pos=self.canvas.coords(self.id)
            if pos[0] <= 0:
                self.x=0
            elif pos[2] >= self.canvas_width:
                self.x=0
    def turn_left(self,evt):
        if self.paused_2==False:
            self.x=-2
    def turn_right(self,evt):
        if self.paused_2==False:
            self.x=2
    def faster(self,evt):
        self.x=(self.x)*2
    def pause(self):
        if self.paused_2==False:
            self.x_2=self.x
            self.x=0
            self.paused_2=True
        else:
            self.x=self.x_2
            self.paused_2=False
    def stop(self,evt):
        self.x=0
    def level_up(self):
        self.speed += 0.5
class Score:
    def __init__(self,canvas,color):
        self.score=0
        self.high=0
        self.q=q # q is the name of the player
        self.canvas=canvas
        self.id=canvas.create_text(450,10,text=('Score: %s ' % self.score), \
                                   fill=color)
    def hit(self):
        self.score +=1
        self.canvas.itemconfig(self.id,text=('Score: %s ' % self.score))
        if self.score/10==int(self.score/10):
            ball.level_up()
            paddle.level_up()
            level.level_up()
    def increase(self):
        self.score +=(random.randint(10000000,20000000))
        self.canvas.itemconfig(self.id,text=('Score: %s ' % self.score))
    def helpa(self):
        load_file=open('bounce_high score','rb')
        a=pickle.load(load_file)
        load_file.close()
        load_file=open('bounce_name','rb')
        b=pickle.load(load_file)
        load_file.close()
        if self.high>=(a[0]):
            print('Hooray,you achieved a high score of %s!' % (self.high))
            save_file=open('bounce_high score','wb')
            self.hi=[]
            self.hi.append(self.high)
            self.hi.append(a[0])
            self.hi.append(a[1])
            pickle.dump(self.hi,save_file)
            save_file.close()
            self.h=[]
            self.h.append(self.q)
            self.h.append(b[0])
            self.h.append(b[1])
            save_file=open('bounce_name','wb')
            pickle.dump(self.h,save_file)
            save_file.close()
            print('2. %s' % a[0])
            print('(by %s)' % b[0])
            print('3. %s' % a[1])
            print('(by %s)' % b[1])
        elif self.high>=(a[1]):
            print('Hooray,you achieved a second highest score of %s!' % (self.high))
            save_file=open('bounce_high score','wb')
            self.hi=[]
            self.hi.append(a[0])
            self.hi.append(self.high)
            self.hi.append(a[1])
            pickle.dump(self.hi,save_file)
            save_file.close()
            self.h=[]
            self.h.append(b[0])
            self.h.append(self.q)
            self.h.append(b[1])
            save_file=open('bounce_name','wb')
            pickle.dump(self.h,save_file)
            save_file.close()
            print('1. %s' % a[0])
            print('(by %s)' % b[0])
            print('3. %s' % a[1])
            print('(by %s)' % b[1])
        elif self.high>=(a[2]):
            print('Hooray,you achieved a third highest score of %s!' % (self.high))
            save_file=open('bounce_high score','wb')
            self.hi=[]
            self.hi.append(a[0])
            self.hi.append(a[1])
            self.hi.append(self.high)
            pickle.dump(self.hi,save_file)
            save_file.close()
            self.h=[]
            self.h.append(b[0])
            self.h.append(b[1])
            self.h.append(self.q)
            save_file=open('bounce_name','wb')
            pickle.dump(self.h,save_file)
            save_file.close()
            print('1. %s' % a[0])
            print('(by %s)' % b[0])
            print('2. %s' % a[1])
            print('(by %s)' % b[1])
        else:
            print('You achieved a score of %s' % self.score)
            print("That's %s points away from achieving a high score" % (a[2]-self.score))
            print('High Scores:')
            print('1. %s' % a[0])
            print('(by %s)' % b[0])
            print('2. %s' % a[1])
            print('(by %s)' % b[1])
            print('3. %s' % a[2])
            print('(by %s)' % b[2])
    def compare(self):
        if self.score>self.high:
            self.high=self.score
class Level:
    def __init__(self,canvas,color):
        self.level=1
        self.canvas=canvas
        self.id=canvas.create_text(390,10,text=('Level: %s ' % self.level), \
                                   fill=color)
    def level_up(self):
        self.level += 1
        self.canvas.itemconfig(self.id,text=('Level: %s ' % self.level))
tk=Tk()
tk.title("Best Game Ever!!!!!!!!")
tk.resizable(0,0)
tk.wm_attributes("-topmost", 1)
canvas=Canvas(tk, width=500, height=350, bd=0, highlightthickness=0)
canvas.pack()
tk.update()
level=Level(canvas,'orange')
score=Score(canvas,'green')
paddle=Paddle(canvas,'blue')
ball=Ball(canvas,paddle,score,'red')
game_over_text=canvas.create_text(250,200,text='Game over, please refer to the top right corner to know your score' ,\
                                  state='hidden')
ball.draw()
paddle.draw()
canvas.bind('<ButtonPress-1>',ball.pause)
time.sleep(3)
w=False
while w==False:
    while 1:
        if ball.hit_bottom==False:
            ball.draw()
            paddle.draw()
        if ball.hit_bottom==True:
            canvas.itemconfig(game_over_text,state='normal')
            print("Would you like to play again?")
            i=input()
            if i=='irockA!irockB!irockC!irockD!irockE!irockF!':
                score.increase()
                w=True
            break
        tk.update_idletasks()
        tk.update()
        time.sleep(0.01)
    score.compare()
    if i=='no':
        break
    tk=Tk()
    tk.title("Best Game Ever!!!!!!!!")
    tk.resizable(0,0)
    tk.wm_attributes("-topmost", 1)
    canvas=Canvas(tk, width=500, height=350, bd=0, highlightthickness=0)
    canvas.pack()
    tk.update()
    level=Level(canvas,'orange')
    score=Score(canvas,'green')
    paddle=Paddle(canvas,'blue')
    ball=Ball(canvas,paddle,score,'red')
    game_over_text=canvas.create_text(250,200,text='Game over, please refer to the top right corner to know your score' ,\
                                          state='hidden')
score.helpa()
