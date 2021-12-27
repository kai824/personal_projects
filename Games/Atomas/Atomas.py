#centre of ring is (175,275)
from tkinter import*
import random
import time
import math
#fixed bug of being able to change random stuff into + if not used on the minus
#added achievements, and score rewards
#Added antimatter
#fixed bug if you go through the full cycle
print('Press q to quit')
print('Press r to restart')
print('Press z to undo')
print('Press a to use antimatter')
print('Progress is automatically saved')
input('Press enter to continue')
class Sprite:#parent class of every other thing so that they can all move to any angle of the circle...
    def move(self,angle):#element_id, the angle from North... Returns [x,y], which are coords of the new position
        angle=angle%360
        ratio=math.tan(angle/180*math.pi)
        to_multiply=145/math.sqrt(ratio*ratio+1)
        answer=[ratio*to_multiply,(to_multiply)]
        if angle<90:
            if answer[1]>0:
                answer[1]*=-1
        elif angle<180:
            if answer[0]<0:
                answer[0]*=-1
        elif angle>180:
            if answer[0]>0:
                answer[0]*=-1
            else:
                answer[1]*=-1
        answer[0],answer[1]=-answer[1],answer[0]#swap 2 variables to change bearing to ASTC
        answer[0]+=175
        answer[1]+=275
        return answer

class Element(Sprite):#any of those on the circle...
    def __init__(self,canvas,value,colour):#derive the element and colour later...
        self.canvas=canvas
        self.value=value
        value=str(value)
        self.id=self.canvas.create_oval(0,0,40,40,fill=colour,outline=colour)#radius of 20
        self.textid=self.canvas.create_text(20,20,text=str(value),fill='#eee5e3',justify='center',activefill='#222222')
    def go_to(self,x,y):
        pos=self.canvas.coords(self.id)
        pos[0]=(pos[0]+pos[2])/2
        pos[1]=(pos[1]+pos[3])/2
        del pos[2]
        del pos[2]
        self.canvas.move(self.id,x-pos[0],y-pos[1])
        self.canvas.move(self.textid,x-pos[0],y-pos[1])
    def delete(self):
        self.canvas.delete(self.id)
        self.canvas.delete(self.textid)
    def increase(self,newvalue):
        self.value=newvalue
        self.canvas.itemconfig(self.textid,text=str(newvalue))
    
class InputCollector:#collects input as the name suggests...
    def __init__(self,canvas,client):
        self.canvas=canvas
        self.client=client
        #self.canvas.create_rectangle(290,5,350,25,fill='#d0d0d0')
        self.canvas.create_text(320,15,text='UNDO',font=('Helvetica',20),fill='#d0d0d0',activefill='#d00000')
        self.canvas.create_oval(10,5,30,25,fill='#452729',outline='#d0d0d0',activefill='#d00000')#centre at text centre (20,15), radius of 10
        self.canvas.create_text(20,15,text='i',font=('Ariel',20),fill='#d0d0d0',state='disabled')
        self.achievement_info=[]#id of all the sprites used to show achievements
        self.achieved=self.client.achieved#bitmask
        self.antimatter=self.client.antimatter
        self.lines=[0,1,2,3,5,7,8,9,11,13,14]#lines to put the checkboxes
        self.achieve_names=['pH2','pH7','pH12','Risk taker I','Risk taker II','High scorer I','Exact scorer','Big reaction I','Big reaction II','Positivity','Emptiness']
        self.quit=False
        self.showing_info=False
        self.running=False#when making achievements
        self.canvas.create_oval(20,35,30,45,fill='#888888888',outline='#888888888',activefill='#eee000000')#centre in 25, 40, radius of 5
        self.antimatter_text=self.canvas.create_text(10,40,text=str(self.antimatter),fill='#ffffff')
        self.last_click=-100
        self.canvas.bind_all('<ButtonPress-1>',self.click)
        self.canvas.bind_all('<KeyPress-q>',self.end)
        self.canvas.bind_all('<KeyPress-m>',self.minus)
        self.canvas.bind_all('<KeyPress-r>',self.restart)
        self.canvas.bind_all('<KeyPress-z>',self.undo)
        self.canvas.bind_all('<KeyPress-a>',self.use_antimatter)
    
    def achieve(self,achievement_it):
        if (self.achieved&(1<<achievement_it))==0:
            self.achieved|=(1<<achievement_it)
            self.client.score.add(300)
            self.antimatter+=1#not done here with this antimatter
            self.client.antimatter=self.antimatter
            self.canvas.itemconfig(self.antimatter_text,text=str(self.antimatter))
            time.sleep(0.2)
            msg=self.canvas.create_text(65,70,justify='center',fill='#dddddd',text=self.achieve_names[achievement_it]+'\nachieved!',font=('Helvetica',20))
            tk.update()
            tk.update_idletasks()
            time.sleep(0.5)
            cur_colour=[221,221,221]#hexadecimal for dd
            end_colour=[int('45',16),int('27',16),int('29',16)]
            changes=[]
            for x in range(3):
                changes.append((end_colour[x]-cur_colour[x])/10)
            for x in range(10):
                for y in range(3):
                    cur_colour[y]+=changes[y]
                hex_code='#'+hex(int(cur_colour[0])).split('x')[-1]+hex(int(cur_colour[1])).split('x')[-1]+hex(int(cur_colour[2])).split('x')[-1]
                self.canvas.itemconfig(msg,fill=hex_code)
                tk.update()
                tk.update_idletasks()
                time.sleep(0.03)
            self.canvas.delete(msg)
    def check_achievements(self):
        self.client.running=True#so that it won't do other stuff
        self.running=True#so that it knows it can't quit
        #check HCl, check H2O and KOH
        l=len(self.client.atoms)
        for x in range(l):
            if (self.client.atoms[x][2]==1 and self.client.atoms[(x+1)%l][2]==17) or (self.client.atoms[x][2]==17 and self.client.atoms[(x+1)%l][2]==1):
                self.achieve(0)
            if self.client.atoms[x][2]==1 and self.client.atoms[(x+1)%l][2]==8 and self.client.atoms[(x+2)%l][2]==1:#proton number, H2O
                self.achieve(1)
            if (self.client.atoms[x][2]==19 and self.client.atoms[(x+1)%l][2]==8 and self.client.atoms[(x+2)%l][2]==1) or\
               (self.client.atoms[x][2]==1 and self.client.atoms[(x+1)%l][2]==8 and self.client.atoms[(x+2)%l][2]==19):#KOH, or the reverse
                self.achieve(2)
        #check long reactions
        if self.client.longest_reaction>=14:
            self.achieve(3)
        if self.client.longest_reaction>=16:
            self.achieve(4)
        #check score
        if self.client.score.score>=25000:
            self.achieve(5)
        if self.client.score.score==10000:
            self.achieve(6)
        #number of pluses used?
        if self.client.pluses_used>=4:
            self.achieve(7)
        if self.client.pluses_used>=6:
            self.achieve(8)
        #number of pluses in play
        p=0
        for x in range(l):
            if self.client.atoms[x][2]=='+':
                p+=1
        if p>=12 and (self.achieved&(1<<9))==0:
            self.achieve(9)
        #number of atoms in play (is it empty)
        if l==0:
            self.achieve(10)
        self.client.achieved=self.achieved
        self.client.save_progress()
        self.client.running=False
        self.running=False
        if self.quit==True:
            self.end(0)
    def minus(self,evt):
        self.client.moves=19
    def end(self,evt):
        if self.running==True:
            self.quit=True
            return False
        self.quit=True
        self.canvas.destroy()
        tk.destroy()
    def restart(self,evt):
        if self.client.running==False:
            self.achieved=0
            self.antimatter=0
            self.canvas.itemconfig(self.antimatter_text,text=str(self.antimatter))
            self.client.score.restart()
            self.client.restart()
    def undo(self,evt):
        if self.client.over==True:
            return False
        if self.client.running==False and self.showing_info==False:
           self.client.undo(evt)
           self.achieved=self.client.achieved
           self.antimatter=self.client.antimatter
           self.canvas.itemconfig(self.antimatter_text,text=str(self.antimatter))
    def use_antimatter(self,evt):
        if self.client.running==True or self.showing_info==True or self.client.over==True:
            return False
        if self.antimatter<=0:#no antimatter left to use
            return False
        if self.client.middle[1]=='a':#already using antimatter
            return False
        self.antimatter-=1
        self.client.antimatter=self.antimatter
        self.canvas.itemconfig(self.antimatter_text,text=str(self.antimatter))
        self.client.middle=(self.client.middle[0],'a')
        self.canvas.itemconfig(self.client.middle[0].id,fill='#888888',outline='#888888')
        self.canvas.itemconfig(self.client.middle[0].textid,text='')
        self.client.save_progress()
    def click(self,event):#produces the angle, based on ASTC, passes to manager
        if self.showing_info==True:
            for x in self.achievement_info:
                self.canvas.delete(x)
            self.showing_info=False
            self.achievement_info=[]
            return True#stop the stuff from moving
        if self.client.running==True:
            return False
        if math.sqrt((event.x-25)**2 + (event.y-40)**2)<5:#antimatter clicked
            self.use_antimatter(event)
        if math.sqrt((event.x-20)**2 + (event.y-15)**2)<=10:#info clicked
            self.achievement_info.append(self.canvas.create_rectangle(0,100,350,450,fill='#452729',outline='#452729'))
            self.achievement_info.append(canvas.create_text(175,100,text='Each achievement rewards an antimatter and 300 points',\
                                                            font=('Helvetica',17),fill='#00dd00',width=350))
            self.achievement_info.append(canvas.create_text(20,125,text='pH2:Create HCl\npH7: Create H2O\npH12: Create KOH\nRisk taker I: create a chain reaction with 14++ atoms\
\nRisk taker II: create a chain reaction with 16++ atoms\nHigh scorer: Score 25000++\nExact scorer: Score 10000 exactly\nBig reaction I: Use up \
at least 4 red pluses in a move\nBig reaction II: Use up at least 6 red pluses in a move\nPositivity: Have 12 red pluses in playing area\
\nEmptiness: Clear the whole game field',fill='#999999',width=330,anchor='nw',font=('Times New Roman', 17)))
            for x in range(11):
                shift=(20*self.lines[x])
                if (self.achieved&(1<<x))==0:#not achieved yet
                    self.achievement_info.append(canvas.create_rectangle(5,130+shift,15,140+shift,fill='#eeeeee'))
                else:
                    self.achievement_info.append(canvas.create_rectangle(5,130+shift,15,140+shift,fill='#0000ff'))
                    self.achievement_info.append(canvas.create_polygon(5,135+shift,10,140+shift,15,130+shift,10,138+shift,outline='#000000'))#tick
            self.showing_info=True
            return True
        if self.client.over==True:
            if 150<event.x<200 and 395<event.y<415:
                self.restart(None)
            return False
        if 290<=event.x<=350 and 5<=event.y<=25:#undo button clicked
            if self.client.running==False:
                self.client.undo(event)
            return True
        event.x-=175#make it relative to centre
        event.y-=275
        self.client.longest_reaction=0
        self.client.pluses_used=0
        if math.sqrt((event.x*event.x)+(event.y*event.y))<=30:#atom clicked
            try:
                if self.client.taken==True:#so that if invalid atom click, it is ignored
                    self.client.middle_click()
                    self.client.undone=False
                    self.check_achievements()
            except TclError:
                return False#application was quit...
            return True
        if math.sqrt((event.x*event.x)+(event.y*event.y))>170:#outside the circle
            if time.time()-self.last_click<=0.2:
                self.client.clear()
            self.last_click=time.time()#ensure double-click outside circle
            return False
        try:
            basic_angle=math.degrees(math.atan(abs(event.y)/abs(event.x)))
            if event.y>=0:#1st or 2nd quadrant
                if event.x>=0:#1st
                    angle=basic_angle
                else:#2nd
                    angle=180-basic_angle
            else:#3rd 4th quadrant
                if event.x>=0:#4th
                    angle=360-basic_angle
                else:#3rd
                    angle=180+basic_angle
        except ZeroDivisionError:#x-coord is 0, clicked on y-axis
            if event.y>0:
                angle=90
            else:
                angle=270
        try:
           self.client.click(angle)
           self.client.undone=False
        except TclError:
            return False
        tk.update()
        tk.update_idletasks()
        self.client.end()
        if self.client.over==False:#still alive
            self.check_achievements()
        return True

class Manager:#manage the elements
    def __init__(self,canvas,score):
        self.score=score
        self.endgame=[]#sort of sprites that forecast doom
        self.atoms=[]
        self.next_few=[]#ensure 1 in 5
        #2d array [Element, angle, proton number]
        self.destinations=[]#an angle
        self.canvas=canvas
        self.lo,self.hi=1,3#range
        self.moves=0#no. of moves
        self.middle=None#(element,proton number)
        self.taken=False#if true, atom sourced from minus, so can change to plus
        self.running=False
        self.undone=True#so that cannot undo one more time first
        self.over=False
        self.t3=[canvas.create_oval(140,85,150,95,fill='#00cc00',outline='#00cc00',state='hidden'),\
                 canvas.create_oval(170,85,180,95,fill='#00cc00',outline='#00cc00',state='hidden'),\
                 canvas.create_oval(200,85,210,95,fill='#00cc00',outline='#00cc00',state='hidden')]
        self.t2=[canvas.create_oval(155,85,165,95,fill='#cccc00',outline='#cccc00',state='hidden'),\
                 canvas.create_oval(185,85,195,95,fill='#cccc00',outline='#cccc00',state='hidden')]
        self.t1=[canvas.create_oval(170,85,180,95,fill='#cc0000',outline='#cc0000',state='hidden')]
        
        f=open('colour.txt','r')
        self.d=f.readlines()
        f.close()
        for x in range (len(self.d)):
            if self.d[x][-1]=='\n':
                self.d[x]=self.d[x][:-1]
            self.d[x]=self.d[x].split()
            del self.d[x][0]
            #each section is now [symbol, full name, colour]
        self.d=['null']+self.d#make it one-indexed

        self.longest_reaction=0#used to check achievements
        self.pluses_used=0#used to check achievements
        self.achieved=0
        self.antimatter=0

    def save_progress(self):
        #move progress to prev_state
        try:
            f2=open('.progress.txt','r')
            f=open('.prev_state.txt','w+')
            f.write(f2.read())
            f.close()
            f2.close()
        except FileNotFoundError:
            #no current progress anyway
            f=open('.prev_state.txt','w+')
            f.write('none')
            f.close()
        f=open('.progress.txt','w+')
        f.write('cached\n'+str(self.middle[1]))
        if self.taken==True:
            f.write(' 1\n')
        else:
            f.write(' 0\n')
        f.write(str(self.lo)+' '+str(self.hi)+' '+str(self.moves)+' '+str(self.score.score)+' '+str(self.score.best)+' '+str(self.achieved)+' '+str(self.antimatter)+'\n')
        for x in range(len(self.next_few)):
            f.write(str(self.next_few[x]))
            if x+1<len(self.next_few):#more to output in same line
                f.write(' ')
            else:
                f.write('\n')
        for x in self.atoms:
            f.write(str(x[1])+' '+str(x[2])+'\n')
        f.close()
    def clear(self):
        for x in self.atoms:
            x[0].delete()
        self.atoms=[]
        self.destinations=[]
        self.running=False
    def getname(self,pn):
        if pn+1<=len(self.d):
            return self.d[pn][1]
        else:
            return self.d[(pn-1)%(len(self.d)-1)+1][1]+' '+str( int( (pn-1)/(len(self.d)-1) ) )
    def getsymbol(self,pn):
        if pn+1<=len(self.d):
            return self.d[pn][0]
        else:
            return self.d[(pn-1)%(len(self.d)-1)+1][0]+str( int( (pn-1)/(len(self.d)-1) ) )
    def warn(self):
        for x in range(3):
            if len(self.atoms)==17:
                self.canvas.itemconfig(self.t3[x],state='normal')
            else:
                self.canvas.itemconfig(self.t3[x],state='hidden')
        for x in range(2):
            if len(self.atoms)==18:
                self.canvas.itemconfig(self.t2[x],state='normal')
            else:
                self.canvas.itemconfig(self.t2[x],state='hidden')
        if len(self.atoms)==19:
            self.canvas.itemconfig(self.t1[0],state='normal')
        else:
            self.canvas.itemconfig(self.t1[0],state='hidden')
    def use_variables(self,mid,atoms,lo,hi,moves,achieved,antimatter,score,bestest,future):#continue past progress
        self.next_few=future
        self.lo,self.hi,self.moves,self.achieved,self.antimatter=lo,hi,moves,achieved,antimatter
        self.score.add(score)
        self.score.update(bestest,self.getname(bestest),self.d[(bestest-1)%(len(self.d)-1)+1][2])
        if type(mid[0])==type(8):#integer proton number
            self.middle=[Element(self.canvas,self.getsymbol(mid[0])+'\n'+str(mid[0]),self.d[(mid[0]-1)%(len(self.d)-1)+1][2]),mid[0]]
        elif mid[0]=='+':
            self.middle=[Element(self.canvas,'+','#ff0000'),'+']
        elif mid[0]=='-':
            self.middle=[Element(self.canvas,'-','#0070ff'),'-']
        elif mid[0]=='++':
            self.middle=[Element(self.canvas,'+','#000000'),'++']
        elif mid[0]=='n':
            self.middle=(Element(self.canvas,'','#ffffff'),'n')
        elif mid[0]=='a':
            self.middle=(Element(self.canvas,'','#888888'),'a')
        self.taken=mid[1]
        self.middle[0].go_to(175,275)
        self.atoms=[]
        self.destinations=[]
        for x in atoms:
            if type(x[1])==type(8):#integer proton number
                new_atom=Element(self.canvas,self.getsymbol(x[1])+'\n'+str(x[1]),self.d[(x[1]-1)%(len(self.d)-1)+1][2])
            elif x[1]=='+':
                new_atom=Element(self.canvas,'+','#ff0000')
            elif x[1]=='-':
                new_atom=Element(self.canvas,'-','#0070ff')
            elif x[1]=='++':
                new_atom=Element(self.canvas,'+','#000000')
            elif x[1]=='n':
                new_atom=Element(self.canvas,'','#ffffff')
            new_coords=new_atom.move(x[0])
            new_atom.go_to(new_coords[0],new_coords[1])
            self.atoms.append([new_atom,x[0],x[1]])#element, angle, proton number
            self.destinations.append(x[0])
        self.undone=False
    def start_from(self,filename):
        try:
            f=open(filename,'r')
            a=f.readlines()
            f.close()
            for x in range(len(a)):
                if a[x][-1]=='\n':
                    a[x]=a[x][:-1]
            if a[0]=='none':
                return -1
            else:
                mid=a[1].split()
                try:
                    mid[0]=int(mid[0])
                except ValueError:
                    pass#proton number just the + or sth
                if mid[1]=='0':
                    mid[1]=False
                else:
                    mid[1]=True
                tmp=a[2].split()
                lo,hi,moves,score,best,achieved,antimatter=int(tmp[0]),int(tmp[1]),int(tmp[2]),int(tmp[3]),int(tmp[4]),int(tmp[5]),int(tmp[6])
                future=a[3].split()
                for x in range(len(future)):
                    if future[x]=='0':
                        future[x]=0
                b=[]#list of stuff to pass to m
                for x in range(4,len(a)):
                    to_add=a[x].split()
                    to_add[0]=float(to_add[0])#angle
                    try:
                        to_add[1]=int(to_add[1])#proton number
                    except ValueError:
                        pass
                    b.append((to_add))
                self.use_variables(mid,b,lo,hi,moves,achieved,antimatter,score,best,future)
                return 1
        except FileNotFoundError:
            return -1
    def undo(self,evt):
        if self.running==True:
            return False
        f=open('.progress.txt','w+')
        f.write('cached\n'+str(self.middle[1]))
        if self.taken==True:
            f.write(' 1\n')
        else:
            f.write(' 0\n')
        f.write(str(self.lo)+' '+str(self.hi)+' '+str(self.moves)+' '+str(self.score.score)+' '+str(self.score.best)+' '+str(self.achieved)+' '+str(self.antimatter)+'\n')
        for x in range(len(self.next_few)):
            f.write(str(self.next_few[x]))
            if x+1<len(self.next_few):#more to output in same line
                f.write(' ')
            else:
                f.write('\n')
        for x in self.atoms:
            f.write(str(x[1])+' '+str(x[2])+'\n')
        f.close()
        if self.undone==True:
            return False
        self.undone=True
        for x in self.atoms:
            self.canvas.delete(x[0].id)
            self.canvas.delete(x[0].textid)
        self.canvas.delete(self.middle[0].id)
        self.canvas.delete(self.middle[0].textid)
        self.middle=None
        self.score.restart()
        if self.start_from('.prev_state.txt')==-1:
            self.start_from('.progress.txt')
            return False#cannot undo
        else:#need to write to prev_state
            self.save_progress()
            f=open('.prev_state.txt','w+')
            f.write('none')
            f.close()
    def generate(self):
        self.running=True
        self.moves+=1
        if (self.moves%5)==1:#first in the cycle of 5...
            self.next_few=['+',0,0,0,0]
            random.shuffle(self.next_few)
            if (self.moves%20)==16:#will become minus...
                del self.next_few[4]#do it after, allow for possibility of 3/4 pluses
        self.middle=None
        bestest=-1
        if (self.moves%40)==0:
            self.lo+=1
            self.hi+=1
            self.moves=0
        if (self.moves%20)==0:#minus
            self.middle=(Element(self.canvas,'-','#0070ff'),'-')
            self.middle[0].go_to(175,275)
        elif self.next_few[(self.moves%5)-1]=='+':#plus
            self.middle=(Element(self.canvas,'+','#ff0000'),'+')
            self.middle[0].go_to(175,275)
        else:
            if self.score.score>=750:
                chance=random.randint(1,180)
                if chance<=2:#1/90 chance of spawning dark plus
                    self.middle=(Element(self.canvas,'+','#000000'),'++')
                    self.middle[0].go_to(175,275)
                elif chance<=5 and self.score.score>=1500:#1/60 chance of spawning neutrino
                    self.middle=(Element(self.canvas,'','#ffffff'),'n')#neutrino
                    self.middle[0].go_to(175,275)
            if self.middle==None:
                chance=random.choice(self.atoms)
                if type(chance[2])==type(8) and chance[2]<self.lo:#If you have atoms below this range in the circle they can still spawn with a chance of 1/(Amount of atoms in circle).
                    new=chance[2]
                else:
                    new=random.randint(self.lo,self.hi)#new proton number
                new_atom=Element(self.canvas,self.getsymbol(new)+'\n'+str(new),self.d[(new-1)%(len(self.d)-1)+1][2])
                new_atom.go_to(175,275)
                self.middle=(new_atom,new)
                self.bestest=new
        self.running=False
        for x in range(len(self.atoms)):
            if type(self.atoms[x][2])==type('a'):
                continue
            bestest=max(bestest,self.atoms[x][2])
        self.score.update(bestest,self.getname(bestest),self.d[(bestest-1)%(len(self.d)-1)+1][2])#proton number, full name, colour
    def start_game(self):
        angle=0
        for x in range(6):
            pn=random.randint(self.lo,self.hi)#proton number
            new=Element(self.canvas,self.getsymbol(pn)+'\n'+str(pn),self.d[pn][2])
            dest=new.move(angle)
            new.go_to(dest[0],dest[1])
            self.atoms.append([new,angle,pn])
            self.destinations.append(angle)
            angle+=360/6
    def move_all(self):#moves all atoms to new destination
        for x in range(len(self.atoms)):
            self.destinations[x]=self.destinations[x]-self.atoms[x][1]
            if self.destinations[x]>180:#since angle won't be 180
                self.destinations[x]-=360
            if self.destinations[x]<-180:
                self.destinations[x]+=360
            self.destinations[x]/=7
        for x in range(7):
            for y in range(len(self.atoms)):
                self.atoms[y][1]+=self.destinations[y]
                to_move=self.atoms[y][0].move(self.atoms[y][1])
                self.atoms[y][0].go_to(to_move[0],to_move[1])
            tk.update()
            tk.update_idletasks()
        for x in range(len(self.atoms)):
            self.atoms[x][1]%=360
            if self.atoms[x][1]<0:
                self.atoms[x][1]+=360
            self.destinations.append(self.atoms[x][1])
    def nex(self,it):
        return (it+1)%len(self.atoms)
    def prev(self,it):
        if it==0:
            return len(self.atoms)-1
        else:
            return it-1
    def analyse(self,it):#iterator to start from, check for reactions
        start=self.atoms[it][0].id#since can't be the same
        first=True
        r=1
        while first==True or start!=self.atoms[it][0].id:
            first=False
            antimatter=False
            limit=0
            if self.atoms[it][2]=='a':
                limit=len(self.atoms)//2
                antimatter=True
                maxi=-1
            if self.atoms[it][2] in ['+','++','a'] and ( (self.atoms[self.prev(it)][2]==self.atoms[self.nex(it)][2] and \
               type(self.atoms[self.nex(it)][2])==type(8)) or self.atoms[it][2]in ['++','a']) and self.nex(it)!=self.prev(it):
                #react, possibly chain react, and score...
                first=True
                reaction_length=0
                while (self.atoms[self.prev(it)][2]==self.atoms[self.nex(it)][2] \
                       and type(self.atoms[self.nex(it)][2])==type(8)) or self.atoms[it][2]=='++' or (antimatter==True and limit>0):#can react
                    if self.nex(it)==self.prev(it):
                        break#same thing, can't react
                    time.sleep(0.5)
                    self.destinations=[]
                    for x in range(len(self.atoms)):
                        self.destinations.append(self.atoms[x][1])
                    self.destinations[self.nex(it)]=self.atoms[it][1]
                    self.destinations[self.prev(it)]=self.atoms[it][1]
                    self.move_all()
                    reaction_length+=2
                    if self.atoms[it][2]=='+':
                        self.pluses_used+=1
                        increment=1
                        self.atoms[it][2]=self.atoms[self.nex(it)][2]
                        self.score.add(int(1.5*(self.atoms[it][2]+1)))
                    elif self.atoms[it][2]=='++':
                        increment=3
                        a=self.atoms[self.nex(it)][2]
                        b=self.atoms[self.prev(it)][2]
                        if a in ['+','++','a']:
                            a=1
                        if b in ['+','++','a']:
                            b=1
                        self.atoms[it][2]=max(a,b)
                        self.score.add(int(1.5*(self.atoms[it][2]+1)))
                    elif antimatter==True:
                        increment=3
                        a=self.atoms[self.nex(it)][2]
                        b=self.atoms[self.prev(it)][2]
                        if a in ['+','++','a']:
                            a=1
                        if b in ['+','++','a']:
                            b=1
                        maxi=max(a,b,maxi)
                        self.atoms[it][2]=maxi
                        self.score.add(int( ((r/2)+1)*(self.atoms[it][2]+1) ))
                        limit-=2
                    else:
                        m=(r/2)+1
                        self.score.add(int(m*(self.atoms[it][2]+1)))
                        if self.atoms[it][2]<=self.atoms[self.nex(it)][2]:
                            self.score.add(2*m*(self.atoms[self.nex(it)][2]-self.atoms[it][2]+1))
                            if 2*m*(self.atoms[self.nex(it)][2]-self.atoms[it][2]+1)<0:
                                print(self.atoms[it][2],self.atoms[self.nex(it)][2])
                            increment=2
                            self.atoms[it][2]=self.atoms[self.nex(it)][2]
                        else:
                            increment=1
                    self.atoms[it][2]+=increment
                    self.atoms[it][0].increase(self.getsymbol(self.atoms[it][2])+'\n'+str(self.atoms[it][2]))
                    self.canvas.itemconfig(self.atoms[it][0].id,fill=self.d[(self.atoms[it][2]-1)%(len(self.d)-1)+1][2])
                    self.canvas.itemconfig(self.atoms[it][0].id,outline=self.d[(self.atoms[it][2]-1)%(len(self.d)-1)+1][2])
                    self.atoms[self.nex(it)][0].delete()
                    self.atoms[self.prev(it)][0].delete()
                    a,b=self.prev(it),self.nex(it)
                    if a>b:
                        a,b=b,a
                    del self.atoms[b]
                    del self.destinations[b]
                    del self.atoms[a]
                    del self.destinations[a]
                    if b<it:
                        it-=1
                    if a<it:
                        it-=1
                    tk.update()
                    tk.update_idletasks()
                    r+=1#used to calculate score
                self.longest_reaction=max(self.longest_reaction,reaction_length)
                cur=self.nex(it)
                current_angle=(self.atoms[it][1]+(360/len(self.atoms)))%360
                while cur!=it:
                    self.destinations[cur]=current_angle
                    current_angle+=(360/len(self.atoms))
                    current_angle%=360
                    cur=self.nex(cur)
                self.destinations[it]=self.atoms[it][1]
                self.move_all()
                first=False
                start=self.atoms[it][0].id
            it=self.prev(it)#favours counter clockwise direction
    def click(self,angle):
        if self.middle==None:#happens if player clicks before the atom is generated
            if self.running==True:
                return False
            else:
                self.generate()
                return False
        if self.running==True:
            return False
        self.running=True
        if self.middle[1]=='-':
            min_diff=360#not possible
            min_it=-1#not possible
            for x in range(len(self.atoms)):#[Element, angle, no. of protons]
                diff=abs(angle-self.atoms[x][1])%360
                if diff>180:
                    diff=abs(diff-360)
                if diff<min_diff:
                    min_diff=diff
                    min_it=x
            #move that stupid thing to the centre...
            pos=self.canvas.coords(self.atoms[min_it][0].id)
            pos[0]=(pos[0]+pos[2])/2
            pos[1]=(pos[1]+pos[3])/2
            del pos[2]
            del pos[2]
            xx,yy=(175-pos[0])/7,(275-pos[1])/7
            for x in range(7):
                self.canvas.move(self.atoms[min_it][0].id,xx,yy)
                self.canvas.move(self.atoms[min_it][0].textid,xx,yy)
                tk.update()
                tk.update_idletasks()
            self.middle[0].delete()
            self.middle=(self.atoms[min_it][0],self.atoms[min_it][2])
            prev=self.atoms[min_it][1]
            del self.atoms[min_it]
            del self.destinations[min_it]
            if len(self.atoms)!=0:#since if there's nothing, then nothing to move, nothing to analyse
                min_it%=len(self.atoms)
                it=min_it
                first=True
                while it!=min_it or first:
                    if first==True:
                        self.destinations[it]=(prev+(180/len(self.atoms)))%360
                        first=False
                    else:
                        self.destinations[it]=(prev+(360/len(self.atoms)))%360
                    prev=self.destinations[it]
                    it=self.nex(it)
                self.move_all()
                self.taken=True
                self.analyse(min_it)
        elif self.middle[1]=='n':
            min_diff=360#not possible
            min_it=-1#not possible
            for x in range(len(self.atoms)):#[Element, angle, no. of protons]
                diff=abs(angle-self.atoms[x][1])%360
                if diff>180:
                    diff=abs(diff-360)
                if diff<min_diff:
                    min_diff=diff
                    min_it=x
            #move that stupid thing to the centre...
            self.middle=(self.middle[0],self.atoms[min_it][2])
            self.middle[0].increase(self.atoms[min_it][0].value)
            self.canvas.itemconfig(self.middle[0].id,fill   =self.canvas.itemcget(self.atoms[min_it][0].id,'fill'))
            self.canvas.itemconfig(self.middle[0].id,outline=self.canvas.itemcget(self.atoms[min_it][0].id,'fill'))
        else:
            #move it in, then analyse
            self.taken=False
            for x in range(len(self.atoms)):
                if (self.atoms[x][1]<angle<=self.atoms[self.nex(x)][1]) or ((self.atoms[x][1]<angle or \
                                                            angle<self.atoms[(x+1)%len(self.atoms)][1]) and self.atoms[x][1]>=self.atoms[(x+1)%len(self.atoms)][1]):
                    if self.atoms[x][1]==self.atoms[(x+1)%len(self.atoms)][1]:
                        new_angle=(self.atoms[x][1]+180)%360
                    else:
                        new_angle=(self.atoms[(x+1)%len(self.atoms)][1]-self.atoms[x][1])
                        if new_angle<0:
                            new_angle+=360
                        new_angle/=2
                        new_angle+=self.atoms[x][1]
                        new_angle%=360
                    self.atoms.insert(x+1,[self.middle[0],new_angle,self.middle[1]])
                    self.destinations.insert(x+1,new_angle)
                    dest=self.middle[0].move(new_angle)
                    pos=self.canvas.coords(self.middle[0].id)
                    pos[0]=(pos[0]+pos[2])/2
                    pos[1]=(pos[1]+pos[3])/2
                    del pos[2]
                    del pos[2]
                    xx,yy=(dest[0]-pos[0])/7,(dest[1]-pos[1])/7
                    for y in range(7):
                        self.canvas.move(self.middle[0].id,xx,yy)
                        self.canvas.move(self.middle[0].textid,xx,yy)
                        tk.update()
                        tk.update_idletasks()
                    it=(x+2)%len(self.atoms)
                    current_angle=(new_angle+(360/len(self.atoms)))%360
                    while it!=x+1:
                        self.destinations[it]=current_angle
                        current_angle+=360/len(self.atoms)
                        current_angle%=360
                        it+=1
                        it%=len(self.atoms)
                    self.move_all()
                    self.middle=None
                    self.analyse(x)
                    break
            if len(self.atoms)==0:
                self.atoms.append([self.middle[0],int(angle),self.middle[1]])
                self.destinations.append(int(angle))
                dest=self.middle[0].move(int(angle))
                xx,yy=(dest[0]-175)/7,(dest[1]-275)/7
                for y in range(7):
                    self.canvas.move(self.middle[0].id,xx,yy)
                    self.canvas.move(self.middle[0].textid,xx,yy)
                    tk.update()
                    tk.update_idletasks()
                self.middle=None
                #since only 1 element in circle, nothing to analyse, nothing to move
            self.generate()
        self.warn()
        #check for highest atom
        bestest=-1
        for x in range(len(self.atoms)):
            if type(self.atoms[x][2])==type('+'):
                continue
            bestest=max(bestest,self.atoms[x][2])
        self.score.update(bestest,self.getname(bestest),self.d[(bestest-1)%(len(self.d)-1)+1][2])#proton number, full name, colour
        self.running=False
    def middle_click(self):
        self.running=True
        if self.taken==True:
            self.taken=False
            self.middle[0].value='+'
            self.canvas.itemconfig(self.middle[0].textid,text='+')
            self.canvas.itemconfig(self.middle[0].id,fill='#ff0000')
            self.canvas.itemconfig(self.middle[0].id,outline='#ff0000')
            self.middle=(self.middle[0],'+')
        self.running=False
    def restart(self):
        for x in range(len(self.endgame)):
            self.canvas.delete(self.endgame[x])
        self.endgame=[]
        for x in self.atoms:
            x[0].delete()
        self.atoms=[]
        self.destinations=[]
        self.lo,self.hi=1,3
        self.achieved=0
        self.antimatter=0
        self.moves=0
        if self.middle!=None:
            self.middle[0].delete()
        self.taken=False
        self.running=False
        self.over=False
        self.undone=True
        self.warn()
        self.start_game()
        self.generate()
    def end(self):
        if len(self.atoms)>=20:
            self.running=True
            min_it=-1
            min_angle=370#not possible...
            for x in range(len(self.atoms)):
                if self.atoms[x][1]<min_angle:
                    min_it=x
                    min_angle=self.atoms[x][1]
            for x in range(len(self.atoms)):
                self.atoms[min_it][1]=-1
                pos=self.canvas.coords(self.atoms[x][0].id)
                pos[0]=(pos[0]+pos[2])/2
                pos[1]=(pos[1]+pos[3])/2
                del pos[2]
                del pos[2]
                xx=(175-pos[0])/7
                yy=(275-pos[1])/7
                for y in range(45):
                    self.canvas.tag_raise(self.atoms[x][0].id)
                for y in range(45):
                    self.canvas.tag_raise(self.atoms[x][0].textid)
                for y in range(7):
                    self.canvas.move(self.atoms[x][0].id,xx,yy)
                    self.canvas.move(self.atoms[x][0].textid,xx,yy)
                    tk.update()
                    tk.update_idletasks()
                a=self.atoms[x][2]
                if a=='+':
                    a=1
                self.score.add(a)
                time.sleep(0.1)
            time.sleep(0.3)
            self.endgame.append(self.canvas.create_rectangle(0,100,350,450,fill='#452729',outline='#452729'))
            self.endgame.append(self.canvas.create_text(175,155,text='Game over :(',font=('Helvetica',50),fill='#dddddd'))

            try:
                f=open('highscore.txt','r+')
                a=f.readlines()#score, highest pn
                f.close()
                if a[0][-1]=='\n':
                    a[0]=a[0][:-1]
                if a[1][-1]=='\n':
                    a[1]=a[1][:-1]
            except FileNotFoundError:
                a=['0','0']
            a[0]=int(a[0])
            a[1]=int(a[1])
            a[0]=max(a[0],self.score.score)
            a[1]=max(a[1],self.score.best)
            self.endgame.append(self.canvas.create_text(175,245,text='High score:\n'+str(a[0]),justify='center',font=('Helvetica',50),fill='#dddddd'))
            self.endgame.append(self.canvas.create_text(175,330,text=self.getname(a[1]),justify='center',font=('Helvetica',50),fill=self.d[(a[1]-1)%(len(self.d)-1)+1][2]))
            f=open('highscore.txt','w+')
            f.write(str(a[0])+'\n'+str(a[1]))
            f.close()

            self.endgame.append(self.canvas.create_rectangle(150,395,200,415,fill='#00dddd'))
            self.endgame.append(self.canvas.create_text(175,405,text='Restart',fill='#000099',activefill='#dddddd'))
            f=open('.progress.txt','w+')
            f.write('none')
            f.close()
            f=open('.prev_state.txt','w+')
            f.write('none')
            f.close()
            self.over=True
            self.running=False
            return True

class Score(Sprite):
    def __init__(self,canvas):
        self.canvas=canvas
        self.score=0
        self.best=-1
        self.bestid=self.canvas.create_text(175,20,text='',font=('Helvetica',40),fill='white')
        self.id=self.canvas.create_text(175,65,text='0',font=('Helvetica',40),fill='#dddddd')#avoiding pure white to reduce eye restraint
    def add(self,value):
        self.score+=int(value)
        self.canvas.itemconfig(self.id,text=str(self.score))
    def update(self,pn,name,color):
        if self.best<pn:
            self.best=pn
            self.canvas.itemconfig(self.bestid,text=name)
            self.canvas.itemconfig(self.bestid,fill=color)
    def restart(self):
        self.score=0
        self.best=-1
        self.canvas.itemconfig(self.id,text='0')
#create canvas
tk=Tk()
tk.title("atomas")
tk.resizable(0,0)
canvas=Canvas(tk,width=350,height=450,bd=0,highlightthickness=0)
canvas.pack()

canvas.create_rectangle(0,0,350,450,fill='#452729',outline='#452729')#background
canvas.create_oval(5,105,345,445,outline='#4C302E',width=2)#ring, with radius of 150 pixels

s=Score(canvas)

##canvas.create_rectangle(5,130,15,140,fill='#eeeeee')
##canvas.create_polygon(5,135,10,140,15,130,10,138,outline='#000000')#tick
#each line 20 pixels

m=Manager(canvas,s)
if m.start_from('.progress.txt')==-1:#can't start
    m.start_game()
    m.generate()
    m.warn()
i=InputCollector(canvas,m)

##format of .progress.txt: (hidden file)
##none/cached ->whether have info
##middle proton number, 0/1 for self.taken
##self.lo,self.hi, self.moves, score, best atom, achievement bitmask
##self.next_few
##for rest of the lines,
##angle, proton number
