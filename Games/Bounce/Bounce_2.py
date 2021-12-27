from tkinter import*
import random
import time
import pickle
print('What is your name?')
q=input()
class Ball:
    def __init__(self,canvas,paddle,score,color,paddle_2):
        self.canvas=canvas
        self.paddle=paddle
        self.paddle_2=paddle_2
        self.score=score
        self.id=canvas.create_oval(10,10,25,25, fill=color)
        self.canvas.move(self.id,245,100)
        starts=[-3,-2,-1,1,2,3]
        random.shuffle(starts)
        self.x=starts[0]
        self.y=-3
        self.canvas_height=self.canvas.winfo_height()
        self.canvas_width=self.canvas.winfo_width()
        self.hit_bottom=False
        self.speed=1
    def hit_paddle(self,pos):
        paddle_pos=self.canvas.coords(self.paddle.id)
        if pos[2]>=paddle_pos[0] and pos[0]<=paddle_pos[2]:
            if pos[3]>=paddle_pos[1] and pos[3]<=paddle_pos[3]:
                self.x+=self.paddle.x
                self.score.hit()
                return True
        return False
    def hit_paddle_2(self,pos):
        paddle_pos_2=self.canvas.coords(self.paddle_2.id)
        if pos[2]>=paddle_pos_2[0] and pos[0]<=paddle_pos_2[2]:
            if pos[3]>=paddle_pos_2[1] and pos[3]<=paddle_pos_2[3]:
                self.x+=self.paddle_2.x
                self.score.hit()
                return True
        return False
    def draw(self):
        self.canvas.move(self.id, (self.x * self.speed), (self.y * self.speed))
        pos=self.canvas.coords(self.id)
        if pos[1] <= 0:
            self.y=1
        if pos[3] >= self.canvas_height:
            self.hit_bottom=True
        if self.hit_paddle(pos)==True:
            self.y=-3
            if self.x==0:
                starts=[-1,1]
                random.shuffle(starts)
                self.x=starts[0]
        if self.hit_paddle_2(pos)==True:
            self.y=-3
            if self.x==0:
                starts=[-1,1]
                random.shuffle(starts)
                self.x=starts[0]
        if pos[0] <= 0:
            self.x=3
        if pos[2] >= self.canvas_width:
            self.x=-3
    def level_up(self):
        self.speed += 0.5
class Paddle:
    def __init__(self,canvas,color,a,b,c,d):
        self.canvas=canvas
        self.id=canvas.create_rectangle(0,0,100,10,fill=color)
        self.canvas.move(self.id,200,300)
        self.x=0
        self.canvas_width=self.canvas.winfo_width()
        self.speed=1
        self.canvas.bind_all(a,self.turn_left)
        self.canvas.bind_all(b,self.turn_right)
        self.canvas.bind_all(c,self.stop)
        self.canvas.bind_all(d,self.faster)
    def draw(self):
        self.canvas.move(self.id,self.x,0)
        pos=self.canvas.coords(self.id)
        if pos[0] <= 0:
            self.x=0
        elif pos[2] >= self.canvas_width:
            self.x=0
    def turn_left(self,evt):
        self.x=(-2 * self.speed)
    def turn_right(self,evt):
        self.x=(2 * self.speed)
    def stop(self,evt):
        self.x=0
    def faster(self,evt):
        self.x=(self.x)*2
    def level_up(self):
        self.speed += 0.5
class Score:
    def __init__(self,canvas,color):
        self.score=0
        self.high=0
        self.q=q
        self.canvas=canvas
        self.id=canvas.create_text(450,10,text=('Score: %s ' % self.score), \
                                   fill=color)
    def hit(self):
        self.score +=1
        self.canvas.itemconfig(self.id,text=('Score: %s ' % self.score))
        if self.score/10 == int(self.score/10):
            ball.level_up()
            ball_2.level_up()
            paddle.level_up()
            paddle_2.level_up()
            level.level_up()
    def increase(self):
        self.score +=(random.randint(10000000,20000000))
        self.canvas.itemconfig(self.id,text=self.score)
    def write(self):
        f.write("This player's score is %s \n" % (self.score))
    def help(self):
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
            self.hi=[]
            self.hi.append(self.q)
            self.hi.append(b[0])
            self.hi.append(b[1])
            save_file=open('bounce_name','wb')
            pickle.dump(self.hi,save_file)
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
            self.hi=[]
            self.hi.append(b[0])
            self.hi.append(self.q)
            self.hi.append(b[1])
            save_file=open('bounce_name','wb')
            pickle.dump(self.hi,save_file)
            save_file.close()
            print('1. %s' % a[0])
            print('(by %s)' % b[0])
            print('3. %s' % a[1])
            print('(by %s)' % b[1])
        elif self.high>=(a[2]):
            print('Hooray,you achieved a high score of %s!' % (self.high))
            save_file=open('bounce_high score','wb')
            self.hi=[]
            self.hi.append(a[0])
            self.hi.append(a[1])
            self.hi.append(self.high)
            pickle.dump(self.hi,save_file)
            save_file.close()
            self.hi=[]
            self.hi.append(b[0])
            self.hi.append(b[1])
            self.hi.append(self.q)
            save_file=open('bounce_name','wb')
            pickle.dump(self.hi,save_file)
            save_file.close()
            print('1. %s' % a[0])
            print('(by %s)' % b[0])
            print('2. %s' % a[1])
            print('(by %s)' % b[1])
        else:
            print('You achieved a score of %s' % self.score)
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
while True:
    tk=Tk()
    tk.title("Best Game Ever!!!!!!!!")
    tk.resizable(0,0)
    tk.wm_attributes("-topmost", 1)
    canvas=Canvas(tk, width=500, height=400, bd=0, highlightthickness=0)
    canvas.pack()
    tk.update()
    level=Level(canvas,'orange')
    score=Score(canvas,'green')
    paddle=Paddle(canvas,'purple','<KeyPress-Left>','<KeyPress-Right>','<KeyPress-Up>','<KeyPress-Down>')
    paddle_2=Paddle(canvas,'white','<KeyPress-a>','<KeyPress-d>','<KeyPress-w>','<KeyPress-s>')
    ball=Ball(canvas,paddle,score,'blue',paddle_2,)
    ball_2=Ball(canvas,paddle,score,'black',paddle_2,)
    game_over_text=canvas.create_text(250,200,text='Game over, please refer to the top right corner to know your score' ,\
                                      state='hidden')
    ball.draw()
    ball_2.draw()
    paddle.draw()
    paddle_2.draw()
    over=0
    over_2=0
    time.sleep(3)
    while 1:
        if ball.hit_bottom==False:
            ball.draw()
            paddle.draw()
            paddle_2.draw()
        if ball_2.hit_bottom==False:
            ball_2.draw()
            paddle.draw()
            paddle_2.draw()
        if ball.hit_bottom==True:
            canvas.itemconfig(ball,state='hidden')
            over=over+1
        if ball_2.hit_bottom==True:
            canvas.itemconfig(ball_2,state='hidden')
            over_2=over_2+1
        if over!=0 and over_2!=0:
            canvas.itemconfig(game_over_text,state='normal')
            break
        tk.update_idletasks()
        tk.update()
        time.sleep(0.01)
    score.compare()
    print("Would you like to play again?")
    i=input()
    if i=='irockA!irockB!irockC!irockD!irockE!irockF!':
        score.increase()
        break
    if i=='no':
        break
score.help()
