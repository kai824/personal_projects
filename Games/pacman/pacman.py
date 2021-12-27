from tkinter import*
import random
import time
import math

class Score:
    def __init__(self,canvas):
        self.score=0
        self.canvas=canvas
        self.id=self.canvas.create_text(80,32,text='0',fill='#dddddd')
    def add(self,value):
        self.score+=value
        self.canvas.itemconfig(self.id,text=str(self.score))

class Pellet:
    def __init__(self,canvas,x,y,score):
        self.score=score
        self.canvas=canvas
        self.eaten=False
        self.pb=False
        self.id=self.canvas.create_rectangle(x*16+7,y*16+7,x*16+9,y*16+9,fill='#ffb9b0',outline='#ffb9b0')
    def hide(self):
        self.canvas.itemconfig(self.id,state='hidden')
        self.eaten=True
        self.score.add(10)
    def show(self):#may be useful for restarting
        self.canvas.itemconfig(self.id,state='normal')
        self.eaten=False

class PB:#power berry:
    def __init__(self,canvas,x,y,score):
        self.score=score
        self.canvas=canvas
        self.eaten=False
        self.pb=True
        self.id=self.canvas.create_oval(x*16+2,y*16+2,x*16+14,y*16+14,fill='#febab1',outline='#febab1')
    def hide(self):
        self.canvas.itemconfig(self.id,state='hidden')
        self.eaten=True
        self.score.add(50)
    def show(self):#may be useful for restarting
        self.canvas.itemconfig(self.id,state='normal')
        self.eaten=False

class Pacman:
    def __init__(self,canvas,score):
        self.canvas=canvas
        self.score=score
        self.eaten=0#counts number of stuff I ate
        self.id=self.canvas.create_oval(212,412,235,435,fill='#fffd38',outline='#fffd38')
        self.mouths=[]
        self.mouths.append(self.canvas.create_polygon(212,418,212,429,223,423,fill='#000000',outline='#000000',state='hidden'))#left
        self.mouths.append(self.canvas.create_polygon(218,412,229,412,223,423,fill='#000000',outline='#000000',state='hidden'))#up
        self.mouths.append(self.canvas.create_polygon(235,418,235,429,223,423,fill='#000000',outline='#000000',state='hidden'))#right
        self.mouths.append(self.canvas.create_polygon(218,435,229,435,223,423,fill='#000000',outline='#000000',state='hidden'))#down
        self.open=False
        self.started=False
        self.last_change=0
        self.dir=0
        self.last_dir=0
        self.next_dir=None
        self.over=False#not finished the level
        self.paused=False
        self.pause_time=None
        self.high=False#high after eating power berry
        f=open('mymap.txt')
        self.mymap=f.readlines()
        f.close()
        self.pellets=[]
        for x in range(len(self.mymap)):#row
            if self.mymap[x][-1]=='\n':#column
                self.mymap[x]=self.mymap[x][:-1]

        for x in range(len(self.mymap[0])):#column, x-value, should be 28
            self.pellets.append([])
            for y in range(len(self.mymap)):#row, y-value, should be 36
                if self.mymap[y][x]=='.':
                    self.pellets[x].append(Pellet(canvas,x,y,self.score))
                elif self.mymap[y][x]=='$':
                    self.pellets[x].append(PB(canvas,x,y,self.score))
                else:
                    self.pellets[x].append('-')
        self.canvas.bind_all('<KeyPress-Left>',self.left)
        self.canvas.bind_all('<KeyPress-Right>',self.right)
        self.canvas.bind_all('<KeyPress-Up>',self.up)
        self.canvas.bind_all('<KeyPress-Down>',self.down)
        self.canvas.bind_all('<KeyPress-q>',self.end)
        self.canvas.bind_all('<KeyPress-p>',self.pause)
        self.canvas.bind_all('<ButtonPress-1>',self.get_started)

    def get_started(self,evt):
        self.started=True
    def pause(self,evt):
        self.paused=not self.paused
    def end(self,evt):
        self.end=True
    def left(self,evt):
        self.next_dir=0
    def right(self,evt):
        self.next_dir=2
    def up(self,evt):
        self.next_dir=1
    def down(self,evt):
        self.next_dir=3
    def update(self):
        if self.paused==True:
            return False
        if self.dir!=None and self.next_dir!=None:
            if abs(self.dir-self.next_dir)==2:#opposite directions
                self.dir=self.next_dir
                self.next_dir=None
        if self.dir==None:
            if self.next_dir==None:
                xx,yy=0,0
            else:
                self.dir=self.next_dir
                self.next_dir=None
        if self.dir==None:
            xx,yy=0,0
        elif self.dir==0:#l
            xx,yy=-1,0
        elif self.dir==2:#r
            xx,yy=1,0
        elif self.dir==1:#u
            xx,yy=0,-1
        else:#'d',3
            xx,yy=0,1
        if self.next_dir==None:
            nx,ny=0,0
        elif self.next_dir==0:#l
            nx,ny=-1,0
        elif self.next_dir==2:#r
            nx,ny=1,0
        elif self.next_dir==1:#u
            nx,ny=0,-1
        else:#d
            nx,ny=0,1
        pos=self.canvas.coords(self.id)
        if (pos[0]%16)==12 and (pos[1]%16)==12:#perfectly on a grid
            x,y=int((pos[0]+4)/16),int((pos[1]+4)/16)#time to check based on grid
            if y==17 and x>=27:
                if x==33:
                    #go to (-3,17) but + 2
                    self.canvas.move(self.id,2-(16*39),0)
                    for x in range(4):
                        self.canvas.move(self.mouths[x],2-(16*39),0)
            elif y==17 and x<0:
                if x==-6:
                    #go to (30,17) but -2
                    self.canvas.move(self.id,16*39-2,0)
                    for x in range(4):
                        self.canvas.move(self.mouths[x],(16*39)-2,0)
            else:
                if self.mymap[y+yy][x+xx]=='x':
                    self.dir=None#can't continue moving...
                    xx,yy=0,0
                if self.next_dir!=None and self.mymap[y+ny][x+nx]!='x':#can use next_dir
                    xx,yy=nx,ny
                    self.dir=self.next_dir
                    self.next_dir=None
                if self.pellets[x][y]!='-' and self.pellets[x][y].eaten==False:
                    if self.pellets[x][y].pb==True:#eaten power berry
                        self.high=True
                    self.pellets[x][y].hide()
                    self.eaten+=1
        if self.dir!=None:#moved
            self.last_dir=self.dir#last direction moved...
        self.canvas.move(self.id,xx*2,yy*2)
        for x in range(4):
            self.canvas.move(self.mouths[x],xx*2,yy*2)
        if self.eaten>=244:
            self.over=True
        self.last_change+=1
        if self.last_change==5:
            self.last_change=0
            self.open=not self.open
        if self.dir!=None:#check regardless in case of change in direction
            for x in range(4):
                if self.open==True and x==self.dir:#only this makes the mouth open
                    self.canvas.itemconfig(self.mouths[x],state='normal')#open the mouth
                else:
                    self.canvas.itemconfig(self.mouths[x],state='hidden')
    def get_grid_coords(self):
        pos=self.canvas.coords(self.id)
        return(math.floor((pos[0]+4+8)/16),math.floor((pos[1]+4+8)/16))#+8 so that it takes from centre of pacman, increase accuracy...
    def go_home(self):
        self.dir=0
        self.high=False
        self.next_dir=None
        self.last_dir=0
        self.update()
        pos=self.canvas.coords(self.id)
        self.canvas.move(self.id,212-pos[0],412-pos[1])
        for x in range(4):
            self.canvas.move(self.mouths[x],212-pos[0],412-pos[1])
            self.canvas.itemconfig(self.mouths[x],state='hidden')
            self.open=False
    def reset(self):
        self.go_home()
        self.eaten=0
        for x in range(len(self.pellets)):#should be 28
            for y in range(len(self.pellets[0])):#should be 36
                if self.pellets[x][y]!='-':#pellet or power berry...
                    self.pellets[x][y].show()

class Ghost:
    def __init__(self,canvas,color,it,player):
        self.canvas=canvas
        self.player=player#to use the map mainly
        self.dir=None#0 l, 2 r, 1 u, 3 d
        self.frightened=False
        self.over=False
        self.color=color
        self.target=[0,0]
        #self.target_tile=self.canvas.create_rectangle(0,0,16,16,fill=self.color)
        self.directions=[[-1,0],[0,-1],[1,0],[0,1]]#left, up, right, down
        self.x=0
        self.y=0
        self.id=self.canvas.create_oval(182+(it*30),268,206+(it*30),292,fill=color,outline=color)#30 'cause size 24 every ghost and 6 pixels between ghosts...
        self.remove=self.canvas.create_rectangle(182+(it*30),281,206+(it*30),292,fill='#000000',outline='#000000')
        self.float=self.canvas.create_polygon(182+(it*30),280,182+(it*30),292,186+(it*30),288,190+(it*30),292,194+(it*30),\
                                              288,198+(it*30),292,202+(it*30),288,206+(it*30),292,206+(it*30),280,fill=color,outline=color)
    def get_grid_coords(self):
        pos=self.canvas.coords(self.id)
        return(math.floor((pos[0]+12)/16),math.floor((pos[1]+12)/16))#+12 to take centre of ghost...
    def fill(self,color):
        self.canvas.itemconfig(self.id,fill=color)
        self.canvas.itemconfig(self.id,outline=color)
        self.canvas.itemconfig(self.float,fill=color)
        self.canvas.itemconfig(self.float,outline=color)
    def frighten(self):
        self.frightened=True
        self.fill('green')
    def normal(self):
        self.frightened=False
        self.fill(self.color)
    def update(self):
        if self.dir==None:
            return False
        #self.canvas.delete(self.target_tile)
        #self.target_tile=self.canvas.create_rectangle(self.target[0]*16,self.target[1]*16,self.target[0]*16+16,self.target[1]*16+16,fill=self.color)
        pos=self.canvas.coords(self.id)
        if (pos[0]%16)==12 and (pos[1]%16)==12:#perfectly on a grid, time to perform checks
            xx,yy=int((pos[0]+4)/16),int((pos[1]+4)/16)
            if yy==17 and xx>=27:
                if xx==33:
                    #go to (-3,17) but + 2
                    self.canvas.move(self.id,2-(16*39),0)
                    self.canvas.move(self.remove,2-(16*39),0)
                    self.canvas.move(self.float,2-(16*39),0)
                    self.x,self.y=self.directions[self.dir][0],self.directions[self.dir][1]
            elif yy==17 and xx<0:
                if xx==-6:
                    #go to (30,17) but -2
                    self.canvas.move(self.id,16*39-2,0)
                    self.canvas.move(self.remove,16*39-2,0)
                    self.canvas.move(self.float,16*39-2,0)
                    self.x,self.y=self.directions[self.dir][0],self.directions[self.dir][1]
            else:#since being in the portal won't need a change in direction
                choices=[]
                for x in range(4):
                    if abs(x-self.dir)==2:
                        continue
                    elif x==1 and yy in [14,26] and xx in [12,15]:#in places you can't go up
                        continue
                    if self.player.mymap[yy+self.directions[x][1]][xx+self.directions[x][0]]!='x':#can go there
                        choices.append(x)
                if self.frightened==False:
                    best_it=-1
                    best_dist=1000000000#impossible
                    for x in range(len(choices)):
                        dist=math.sqrt(pow(xx+self.directions[choices[x]][0]-self.target[0],2)+pow(yy+self.directions[choices[x]][1]-self.target[1],2))
                        if dist<best_dist:
                            best_dist=dist
                            best_it=x
                    self.x,self.y=self.directions[choices[best_it]][0],self.directions[choices[best_it]][1]
                    self.dir=choices[best_it]
                else:
                    self.dir=random.choice(choices)
                    self.x,self.y=self.directions[self.dir][0],self.directions[self.dir][1]
        speed=2
        self.canvas.move(self.id,self.x*speed,self.y*speed)#same speed as pacman
        self.canvas.move(self.remove,self.x*speed,self.y*speed)
        self.canvas.move(self.float,self.x*speed,self.y*speed)
    def activate(self):#if move left goes to grid (14,13), move right to grid (14,14)
        l_dist=math.sqrt(pow(13-self.target[0],2)+pow(14-self.target[1],2))
        r_dist=math.sqrt(pow(14-self.target[0],2)+pow(14-self.target[1],2))
        if l_dist<r_dist:
            self.dir=0
            self.x,self.y=-1,0
        else:
            self.dir=2
            self.x,self.y=1,0
        pos=self.canvas.coords(self.id)
        self.canvas.move(self.id,212-pos[0],220-pos[1])
        self.canvas.move(self.float,212-pos[0],220-pos[1])
        self.canvas.move(self.remove,212-pos[0],220-pos[1])
    def deactivate(self,it):#used for restart
        self.dir=None
        self.normal()
        self.x,self.y=0,0
        pos=self.canvas.coords(self.id)
        self.canvas.move(self.id,182+(it*30)-pos[0],268-pos[1])
        self.canvas.move(self.float,182+(it*30)-pos[0],268-pos[1])
        self.canvas.move(self.remove,182+(it*30)-pos[0],268-pos[1])
    def change_direction(self):
        if self.dir==None:
            return False
        if self.frightened==True:
            return False
        self.dir=(self.dir+2)%4
        self.x,self.y=self.directions[self.dir][0],self.directions[self.dir][1]

class GhostManager:
    def __init__(self,canvas,player):
        self.chasing=False
        self.over=False
        self.paused_time=None
        self.game_over_text=None
        self.high_score_text=None
        self.canvas=canvas
        self.player=player
        self.chase_time,self.scatter_time=5,7
        self.frightened_time=10
        self.eaten_ghosts=0
        self.blinky=Ghost(canvas,'#dd0000',-1,player)#red
        self.pinky=Ghost(canvas,'#ee9999',0,player)#pink
        self.inky=Ghost(canvas,'#0000dd',1,player)#blue
        self.clyde=Ghost(canvas,'orange',2,player)#orange
        self.lives=[self.canvas.create_oval(80,545,104,569,fill='#fffd38',outline='#fffd38'),self.canvas.create_oval(50,545,74,569,fill='#fffd38',outline='#fffd38')]
        self.canvas.create_polygon(104,551,104,563,92,557,fill='blue',outline='blue')#make pacman look realistic
        self.canvas.create_polygon(74,551,74,563,62,557,fill='blue',outline='blue')
        self.blinky.target=[27,0]
        self.blinky.activate()
        tk.update()
        tk.update_idletasks()
        while self.player.started==False:
            time.sleep(0.05)
            tk.update()
            tk.update_idletasks()
        time.sleep(2)
        self.pause_time=0
        self.activate_time=[time.time(),time.time()+5,time.time()+10,time.time()+15]
        self.start_time=time.time()#this round's start time
        self.becoming_high=None#recording the time where
        self.eaten_ghosts=0
        self.canvas.bind_all('<KeyPress-space>',self.restart)
    def restart(self,evt):
        if self.over==False:
            return False#can't restart
        self.over=False
        self.paused_time=None
        self.canvas.delete(self.game_over_text)
        self.canvas.delete(self.high_score_text)
        self.game_over_text=None
        self.high_score_text=None
        self.chasing=False
        self.lives=[self.canvas.create_oval(80,545,104,569,fill='#fffd38',outline='#fffd38'),self.canvas.create_oval(50,545,74,569,fill='#fffd38',outline='#fffd38')]
        self.canvas.create_polygon(104,551,104,563,92,557,fill='blue',outline='blue')#make pacman look realistic
        self.canvas.create_polygon(74,551,74,563,62,557,fill='blue',outline='blue')
        self.chase_time,self.scatter_time=5,7
        self.frightened_time=10
        self.pause_time=0
        self.eaten_ghosts=0
        self.player.score.score=0
        self.player.score.add(0)
        self.blinky.deactivate(-1)
        self.pinky.deactivate(0)
        self.inky.deactivate(1)
        self.clyde.deactivate(2)
        self.blinky.target=[27,0]
        self.blinky.activate()
        self.player.reset()
        tk.update()
        tk.update_idletasks()
        time.sleep(2)
        self.activate_time=[time.time(),time.time()+5,time.time()+10,time.time()+15]
        self.start_time=time.time()
        self.becoming_high=None
        self.eaten_ghosts=0
    def update(self):
        if self.player.paused==True:
            if self.paused_time==None:
                self.paused_time=time.time()
            return False
        else:
            if self.paused_time!=None:
                self.pause_time+=time.time()-self.paused_time#paused for timing when paused, pause for duration paused
                self.paused_time=None
        if self.player.over==True:
            #restart everything xxx
            self.chase_time*=2
            self.scatter_time/=2#make the level harder
            self.frightened_time/=2
            tk.update()
            tk.update_idletasks()
            time.sleep(1.5)
            self.blinky.deactivate(-1)
            self.blinky.activate()
            self.pinky.deactivate(0)
            self.inky.deactivate(1)
            self.clyde.deactivate(2)
            self.player.reset()
            tk.update()
            tk.update_idletasks()
            time.sleep(1.5)
            self.player.reset()
            self.pause_time=0
            self.start_time=time.time()
            self.player.over=False
            self.activate_time=[time.time(),time.time()+5,time.time()+10,time.time()+15]
            return True
        if self.player.high==True:
            self.player.high=False
            self.becoming_high=time.time()
            self.eaten_ghosts=0
            ghosts=(self.blinky,self.pinky,self.inky,self.clyde)
            for x in ghosts:
                if x.dir!=None:#activated
                    x.change_direction()
                    x.frighten()
        if self.becoming_high!=None and time.time()-self.pause_time-self.becoming_high>self.frightened_time:
            self.blinky.normal()
            self.pinky.normal()
            self.inky.normal()
            self.clyde.normal()
            self.pause_time+=time.time()-self.becoming_high
            self.becoming_high=None
        else:
            ghosts=(self.blinky,self.pinky,self.inky,self.clyde)
            for x in ghosts:
                if x.frightened==True:
                    time_left=self.frightened_time-(time.time()-self.pause_time-self.becoming_high)
                    if 0.25<=time_left<=0.5 or 0.75<=time_left<=1 or 1.25<=time_left<=1.5:
                        x.fill('#dddddd')
                    else:
                        x.fill('green')
                        

        timing=time.time()-self.pause_time
        self.blinky.update()
        if timing>self.activate_time[0] and self.blinky.dir==None:
            self.blinky.activate()
        if timing>self.activate_time[1] and self.pinky.dir==None:#direction as indicator of activation
            self.pinky.activate()
        if timing>self.activate_time[2] and self.inky.dir==None:
            self.inky.activate()
        if timing>self.activate_time[3] and self.clyde.dir==None:
            self.clyde.activate()
        self.pinky.update()
        self.inky.update()
        self.clyde.update()
        #check for change mode
        if self.chasing==False:#check time for scatter
            if (time.time()-self.pause_time-self.start_time)%(self.scatter_time+self.chase_time)>self.scatter_time:
                self.chasing=True
                self.last_change=time.time()
                self.blinky.change_direction()
                self.pinky.change_direction()
                self.inky.change_direction()
                self.clyde.change_direction()
        else:
            if (time.time()-self.pause_time-self.start_time)%(self.scatter_time+self.chase_time)<self.scatter_time:
                self.chasing=False
                self.last_change=time.time()
                self.last_change=time.time()
                self.blinky.change_direction()
                self.pinky.change_direction()
                self.inky.change_direction()
                self.clyde.change_direction()
        #update target tiles
        if self.chasing==False:
            self.blinky.target=[27,0]
            self.pinky.target=[0,0]
            self.inky.target=[27,34]
            self.clyde.target=[0,34]
        else:
            p_coords=self.player.get_grid_coords()
            self.blinky.target=[p_coords[0],p_coords[1]]
            self.pinky.target=[p_coords[0]+(4*self.pinky.directions[self.player.last_dir][0]),p_coords[1]+(4*self.pinky.directions[self.player.last_dir][1])]#4 tiles ahead of pacman
            f_coords=(p_coords[0]+(2*self.inky.directions[self.player.last_dir][0]),p_coords[1]+(2*self.inky.directions[self.player.last_dir][1]))#2 tiles ahead of pacman
            b_coords=self.blinky.get_grid_coords()#since it's needed for inky
            self.inky.target=[f_coords[0]*2-b_coords[0],f_coords[1]*2-b_coords[1]]
            o_coords=self.clyde.get_grid_coords()
            if math.sqrt(pow(p_coords[0]-o_coords[0],2)+pow(p_coords[1]-o_coords[1],2))>=8:#checking distance
                self.clyde.target=[p_coords[0],p_coords[1]]
            else:
                self.clyde.target=[0,34]
        ghost_coords=[]
        ghost_coords.append(self.blinky.get_grid_coords())
        ghost_coords.append(self.pinky.get_grid_coords())
        ghost_coords.append(self.inky.get_grid_coords())
        ghost_coords.append(self.clyde.get_grid_coords())
        ghosts=(self.blinky,self.pinky,self.inky,self.clyde)
        for x in range(4):
            if ghost_coords[x]==self.player.get_grid_coords():
                if ghosts[x].frightened==True:#ate the ghost
                    self.eaten_ghosts+=1
                    self.player.score.add(100*(2**self.eaten_ghosts))
                    self.canvas.itemconfig(ghosts[x].id,state='hidden')
                    self.canvas.itemconfig(ghosts[x].float,state='hidden')
                    self.canvas.itemconfig(ghosts[x].remove,state='hidden')
                    tmp=self.canvas.create_text(ghost_coords[x][0]*16+8,ghost_coords[x][1]*16+4,text=str(100*(2**self.eaten_ghosts)),fill='#dddddd')
                    tk.update()
                    tk.update_idletasks()
                    time.sleep(1.5)
                    self.pause_time+=1.5
                    self.canvas.delete(tmp)
                    self.canvas.itemconfig(ghosts[x].id,state='normal')
                    self.canvas.itemconfig(ghosts[x].float,state='normal')
                    self.canvas.itemconfig(ghosts[x].remove,state='normal')
                    ghosts[x].deactivate((self.eaten_ghosts-1)%3)
                    self.activate_time[x]=time.time()-self.pause_time+2.5#current timing + 2.5
                else:#got eaten xxx
                    tk.update()
                    tk.update_idletasks()
                    time.sleep(1.5)
                    if len(self.lives)==0:
                        self.over=True
                        self.game_over_text=self.canvas.create_text(224,328,text='GAME OVER',fill='#dddddd')
                        try:
                            f=open('pac_highscore.txt','r')
                            a=f.read()
                            f.close()
                        except FileNotFoundError:
                            a='0'
                        if a[-1]=='\n':
                            a=a[:-1]
                        a=int(a)
                        if p.score.score>a:
                            f=open('pac_highscore.txt','w+')
                            f.write(str(self.player.score.score))
                            f.close()
                        a=max(a,p.score.score)
                        self.high_score_text=canvas.create_text(224,136,text='HIGH SCORE: '+str(a),fill='#dddddd')
                        return False
                    self.blinky.deactivate(-1)
                    self.blinky.activate()
                    self.pinky.deactivate(0)
                    self.inky.deactivate(1)
                    self.clyde.deactivate(2)
                    self.player.go_home()
                    canvas.delete(self.lives[0])
                    del self.lives[0]
                    tk.update()
                    tk.update_idletasks()
                    time.sleep(2)
                    self.player.go_home()
                    #self.player.go_home
                    self.pause_time=0
                    self.start_time=time.time()
                    self.activate_time=[time.time(),time.time()+5,time.time()+10,time.time()+15]
                    
tk=Tk()
tk.title('Pacman')
tk.wm_attributes("-topmost",1)
canvas=Canvas(tk,width=448,height=576,bg='#000000',highlightthickness=0,bd=0)
canvas.pack()

#Background
def r(a,b,c,d,canvas):
    canvas.create_rectangle(a,b,c,d,fill='blue',outline='blue')
r(0,0,448,56,canvas)
r(218,56,230,116,canvas)
r(0,0,8,256,canvas)
r(440,0,448,256,canvas)

r(44,92,84,116,canvas)
r(124,92,180,116,canvas)
r(268,92,324,116,canvas)
r(364,92,404,116,canvas)

r(44,156,84,164,canvas)
r(172,156,276,164,canvas)
r(364,156,404,164,canvas)

r(124,156,132,260,canvas)
r(218,156,230,212,canvas)
r(316,156,324,260,canvas)

r(0,200,84,260,canvas)
r(124,200,180,208,canvas)
r(268,200,324,208,canvas)
r(364,200,448,260,canvas)

r(168,248,280,312,canvas)
canvas.create_rectangle(208,248,240,256,fill='black',outline='black')
canvas.create_rectangle(208,250,240,254,fill='pink',outline='pink')
canvas.create_rectangle(176,256,272,304,fill='black',outline='black')

r(0,300,84,356,canvas)
r(124,300,132,356,canvas)
r(316,300,324,356,canvas)
r(364,300,448,356,canvas)
r(172,348,276,356,canvas)
r(218,350,230,404,canvas)

r(44,396,84,404,canvas)
r(124,396,180,404,canvas)
r(268,396,324,404,canvas)
r(364,396,404,404,canvas)

r(76,396,84,452,canvas)
r(364,396,372,452,canvas)
r(0,444,36,452,canvas)
r(172,444,276,452,canvas)
r(412,444,448,452,canvas)

r(218,444,230,500,canvas)
r(124,444,132,500,canvas)
r(316,444,324,500,canvas)
r(44,492,180,500,canvas)
r(268,492,404,500,canvas)

r(0,320,8,576,canvas)
r(440,320,448,576,canvas)
r(0,536,448,576,canvas)
#End of background code

score=Score(canvas)
p=Pacman(canvas,score)
g=GhostManager(canvas,p)
try:
    while True:
        if p.end==True:
            canvas.destroy()
            tk.destroy()
            break
        if g.over==True:
            tk.update()
            tk.update_idletasks()
            time.sleep(0.05)
            continue
        p.update()
        g.update()
        tk.update()
        tk.update_idletasks()
        time.sleep(0.01)
except TclError:
    print('Why click x when you can just press q to quit, or press space bar to play again...')
