from tkinter import*
import random
#for this code, I'll try to make it playable infinitely(code ends but well yeah...)
#Red circle for flagging


gs=20#Grid Size
print("Please input your choice of difficulty(easy, intermediate, hard, custom)")
i=input()
h,w,m=0,0,0#height, width, mines
if i=="easy":
    h=9
    w=9
    m=10
elif i=='intermediate':
    h,w,m=16,16,40
elif i=='hard':
    h,w,m=16,30,99
else:
    print("Please input height, width, and the number of mines")
    i=input()
    i=i.split()
    h=int(i[0])
    w=int(i[1])
    m=int(i[2])
    if h*w<m:
        raise Exception("Invalid customisation")

tk=Tk()
tk.title("Minesweeper")
tk.resizable(0,0)
tk.wm_attributes("-topmost",1)
canvas=Canvas(tk,width=w*gs,height=(h+3)*gs,bd=0,highlightthickness=0)
canvas.pack()
for x in range(3,h+3):#horizontal lines
    canvas.create_line(0,x*gs,w*gs,x*gs)
for y in range(1,w):#vertical lines
    canvas.create_line(y*gs,3*gs,y*gs,(h+3)*gs)


class Game:
    def __init__(self,canvas,gs,mines):
        self.gs=gs
        self.canvas=canvas
        self.m=mines
        self.windows=[]
        self.arr=[]
        self.map=[]
        self.clicks=0
        self.ended=False
        for x in range(h*w):
            if x<mines:
                self.map.append('x')
            else:
                self.map.append('-')
        random.shuffle(self.map)
        for x in range(3,h+3):
            a=[]
            to_arr=[]
            for y in range(w):
                to_arr.append(False)
                a.append(canvas.create_rectangle(y*gs,x*gs,(y+1)*gs,(x+1)*gs,fill='blue'))
            self.windows.append(a)
            self.arr.append(to_arr)
        self.canvas.bind_all('<ButtonPress-1>',self.Left)
        self.canvas.bind_all('<ButtonPress-2>',self.Right)
    def analyse(self,x,y):#Based on the x and y coordinates, analyse which grid is being clicked
        y-=3*self.gs
        if x<0 or x>w*self.gs:
            return None
        if y<0 or y>h*self.gs:
            return None
        x-=x%self.gs
        y-=y%self.gs
        x/=self.gs
        y/=self.gs
        return(int(x),int(y))
    def end(self):
        self.ended=True
    def Left(self,evt):#INCOMPLETE: BFS
        if self.ended==True:
            return None
        x=self.analyse(evt.x,evt.y)
        if x==None:
            return None
        else:
            x,y=x
        if self.windows[y][x]==None:
            return None
        self.canvas.delete(self.windows[y][x])
        self.windows[y][x]=None
        self.clicks+=1
        if self.map[(y*w)+x]=='x':
            self.canvas.create_text(w*self.gs/2,1.5*self.gs,text="You lost")
            self.end()
        else:
            x_vals=[-1,-1,-1,0,0,1,1,1]
            y_vals=[-1,0,1,-1,1,-1,0,1]
            ans=0
            for i in range(8):
                x2=x+x_vals[i]
                y2=y+y_vals[i]
                if x2<0 or y2<0 or x2>=h or y2>=w:
                    continue
                elif self.map[(y2*w)+x2]=='x':
                    ans+=1
            if ans==0:
                #BFS INCOMPLETE
                self.canvas.create_text((x+0.5)*gs,(y+3.5)*gs,text='n')
            else:
                self.canvas.create_text((x+0.5)*gs,(y+3.5)*gs,text=str(ans))
            if self.clicks+self.m==h*w:
                self.canvas.create_text(w*self.gs/2,1.5*self.gs,text="You won! :)")
                self.end()
    def Right(self,evt):
        if self.ended==True:
            return 0
        x=self.analyse(evt.x,evt.y)
        if x==None:
            return None
        else:
            x,y=x
        if self.arr[x][y]==False:
            y+=3
            self.arr[x][y-3]=self.canvas.create_oval(x*self.gs,y*self.gs,(x+1)*self.gs,(y+1)*self.gs,fill='red')
        else:
            self.canvas.delete(self.arr[x][y])
            self.arr[x][y]=False
    
g=Game(canvas,gs,m)
#0.0 0.1 0.2 0.3
#1.0 1.1 1.2 1.3
#2.0 2.1 2.3 2.3
#3.0 3.1 3.2 3.3
