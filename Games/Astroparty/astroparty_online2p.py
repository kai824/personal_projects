from tkinter import*
import math
import time
import random
import socket as a_socket
from socket import AF_INET, socket, SOCK_STREAM
from threading import Thread

#NOT DONE:
#rematching?

received=False
link=None
host=False
def send(msg,event=None):#since evt is passed by the binder
    global link#where link is the name of the socket
    link.send(bytes(msg,'utf8'))
def get_msg():
    global link
    r=link.recv(128).decode('utf8')
    received=True
    return r


def area(points):
    x1,y1,x2,y2,x3,y3=points
    return abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)

def point_in_tri(xx,yy,sprite):
    points=canvas.coords(sprite)
    if round(area(points),3)==round(area(points[:4]+[xx,yy]) + area([xx,yy]+points[-4:]) + area(points[:2]+[xx,yy]+points[-2:]),3):
        return True
    return False

def find_angle(x,y,anchor_x,anchor_y):
    x-=anchor_x
    y-=anchor_y
    try:
        basic_angle=math.degrees(math.atan(abs(y)/abs(x)))
        if y>=0:#1st or 2nd quadrant
            if x>=0:#1st
                angle=basic_angle
            else:#2nd
                angle=180-basic_angle
        else:#3rd 4th quadrant
            if x>=0:#4th
                angle=360-basic_angle
            else:#3rd
                angle=180+basic_angle
    except ZeroDivisionError:#x-coord is 0, clicked on y-axis
        if y>0:
            angle=90
        else:
            angle=270
    return angle
def rotate(x,y,ax,ay,angle):#rotates point(x,y) about the point (ax,ay) by angle(degrees)
    x-=ax
    y-=ay
    s=math.sin(angle/180*math.pi)
    c=math.cos(angle/180*math.pi)
    xnew=x*c-y*s
    ynew=x*s+y*c
    x=xnew+ax
    y=ynew+ay
    return (x,y)
def assign(x,y,anchor_x,anchor_y,angle):#assume anchor is (x,y), so need to translate
    angle+=find_angle(x,y,anchor_x,anchor_y)
    angle=angle%360
    ratio=math.tan(angle/180*math.pi)
    to_multiply=math.sqrt(pow(x-anchor_x,2) + pow(y-anchor_y,2))/math.sqrt(ratio*ratio+1)
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
    answer[0]+=anchor_x
    answer[1]+=anchor_y
    return answer
    #returns the resultant point
def out_of_canvas(canvas,sprite):
    pos=canvas.coords(sprite)
    it=0
    while it<len(pos):
        if not ( (pos[it]<0 or pos[it]>500) or (pos[it+1]<0 or pos[it+1]>500) ):#point in canvas
            return False#in canvas, not out of canvas
        it+=2
    return True#indeed, point is outside the canvas

class Score:
    def __init__(self,canvas,player_no,fill):
        x,y=rotate(30,10,250,250,player_no*90)
        self.canvas=canvas
        self.id=self.canvas.create_text(x,y,text='Score:0',fill=fill)
        self.score=0
    def add(self):
        self.score+=1
        self.canvas.itemconfig(self.id,text='Score:'+str(self.score))

class Bullet:
    def __init__(self,canvas):
        self.canvas=canvas
        self.bullets=[]#id, direction
    def check_all(self,opponent):#checks if all any opponents are dead
        killed=False
        for ii in range(len(self.bullets)):
            i=self.bullets[ii]
            pos=self.canvas.coords(i[0])
            for x in range(4):
                if point_in_tri(pos[x*2],pos[x*2+1],opponent):
                    killed=True
            if killed:
                self.canvas.delete(self.bullets[ii][0])
                del self.bullets[ii]
                return True
    def move_all(self):
        it=0
        while it<len(self.bullets):
            x=self.bullets[it]
            angle=x[1]
            ratio=math.tan(angle/180*math.pi)
            to_multiply=7/math.sqrt(ratio*ratio+1)
            answer=[ratio*to_multiply,to_multiply]
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
            self.canvas.move(x[0],answer[0],answer[1])
            if out_of_canvas(canvas,x[0]):#wtv check
                self.canvas.delete(x[0])
                del self.bullets[it]
            else:
                it+=1
    def shoot(self,start_x,start_y,direction):
        p1=assign(start_x-2,start_y-1,start_x,start_y,direction)
        p2=assign(start_x+2,start_y-1,start_x,start_y,direction)
        p3=assign(start_x+2,start_y+1,start_x,start_y,direction)
        p4=assign(start_x-2,start_y+1,start_x,start_y,direction)
        b=self.canvas.create_polygon(p1[0],p1[1],p2[0],p2[1],p3[0],p3[1],p4[0],p4[1],fill='#ffffff',outline='#ffffff')
        #self.canvas.move(b,start_x,start_y)
        self.bullets.append([b,direction])
    def restart(self):
        for b in self.bullets:
            self.canvas.delete(b[0])
        self.bullets=[]

class Player:
    def __init__(self,canvas,colour,player_no):
        p=[30,30,60,30,45,70]
        self.player_no=player_no
        for x in range(player_no):
            for i in range(3):
                (i,p)=(p,i)
                i[p*2]-=250
                i[p*2+1]-=250
                i[p*2],i[p*2+1]=i[p*2+1],i[p*2]
                i[p*2]*=-1
                i[p*2]+=250
                i[p*2+1]+=250
                (i,p)=(p,i)
        self.colour=colour
        self.id=canvas.create_polygon(p[0],p[1],p[2],p[3],p[4],p[5],fill=self.colour,outline='white')
        self.direction=(player_no+1)*90
        self.canvas=canvas
        self.bullets=Bullet(canvas)#for shooting
        self.last_generated=time.time()
        self.b_count=3#no. of available bullets
        self.last_shot=-1
        self.opponent=None
        self.movements=[]#direction, amplitude, number of times left
    def restart(self):
        self.canvas.itemconfig(self.id,state='normal')
        self.canvas.delete(self.id)
        p=[30,30,60,30,45,70]
        player_no=self.player_no
        for x in range(player_no):
            for i in range(3):
                (i,p)=(p,i)
                i[p*2]-=250
                i[p*2+1]-=250
                i[p*2],i[p*2+1]=i[p*2+1],i[p*2]
                i[p*2]*=-1
                i[p*2]+=250
                i[p*2+1]+=250
                (i,p)=(p,i)
        self.id=canvas.create_polygon(p[0],p[1],p[2],p[3],p[4],p[5],fill=self.colour,outline='white')
        self.direction=(self.player_no+1)*90
        self.bullets.restart()
        self.last_generated=time.time()
        self.b_count=3#no. of available bullets
        self.last_shot=-1
        self.movements=[]#direction, amplitude, number of times left
    def die(self):
        self.canvas.itemconfig(self.id,state='hidden')
    def move(self,amplitude,direction):
        direction%=360
        angle=direction
        ratio=math.tan(angle/180*math.pi)
        to_multiply=amplitude/math.sqrt(ratio*ratio+1)
        answer=[ratio*to_multiply,to_multiply]
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
        pos=canvas.coords(self.id)
        for i in range(3):
            answer[0]=min(answer[0],500-pos[i*2])
            answer[0]=max(answer[0],0-pos[i*2])
            answer[1]=min(answer[1],500-pos[i*2+1])
            answer[1]=max(answer[1],0-pos[i*2+1])
        self.canvas.move(self.id,answer[0],answer[1])
        if time.time()-self.last_generated>=2:
            self.last_generated+=2
            self.b_count=min(3,self.b_count+1)
    def update_pos(self):
        x=0
        while x<len(self.movements):
            i=self.movements[x]
            self.move(i[1],i[0])
            i[2]-=1
            if i[2]==0:
                del self.movements[x]
                x-=1
            x+=1
                
        self.direction%=360
        self.move(4,self.direction)
        self.bullets.move_all()
    def check_all(self):
        if self.bullets.check_all(self.opponent.id):
            self.opponent.die()
            return True
    def shoot(self):
        if self.b_count<=0 or self.last_shot+0.1>time.time():
            return False
        self.last_shot=time.time()
        self.b_count-=1
        pos=self.canvas.coords(self.id)
        self.bullets.shoot(pos[4],pos[5],self.direction)
    def turn(self,angle):
        st=time.time()
        p=canvas.coords(self.id)
        midpoint=[(p[0]+p[2]+p[4])/3,(p[1]+p[3]+p[5])/3]
        for i in range(3):
            p[i*2],p[i*2+1]=rotate(p[i*2],p[i*2+1],midpoint[0],midpoint[1],angle)
            continue
            i,p=p,i
            i[p*2]-=midpoint[0]
            i[p*2+1]-=midpoint[1]
            s=math.sin(angle/180*math.pi)
            c=math.cos(angle/180*math.pi)
            xnew=i[p*2]*c-i[p*2+1]*s
            ynew=i[p*2]*s+i[p*2+1]*c
            i[p*2]=xnew+midpoint[0]
            i[p*2+1]=ynew+midpoint[1]
            p,i=i,p
        canvas.delete(self.id)
        self.id=canvas.create_polygon(p[0],p[1],p[2],p[3],p[4],p[5],fill=self.colour,outline='white')
        self.direction+=angle
class Game:
    def __init__(self,canvas,start='#ffff00',end='#ff0000'):#the main stuff, plus collecting input
        self.players=[Player(canvas,'green',0),Player(canvas,'blue',2)]
        self.scores=[Score(canvas,0,'green'),Score(canvas,2,'blue')]
        self.players[0].opponent=self.players[1]
        self.players[1].opponent=self.players[0]
        self.inactive=True
        '''self.players=[]
        n=int(input("No. of players:"))
        n=min(n,4)
        for x in range(n):
            while True:
                print("Colour of player",x+1)
                try:
                    xx=x
                    if n==2 and xx==1:
                        xx=2
                    players.append(Player(canvas,input().lower(),xx))
                    break
                except TclError:
                    print('Invalid colour. Try again. Hex code allowed, with #')'''#maybe? for optional no. of players
        self.canvas=canvas
        self.text=canvas.create_text(250,250,text='3...',fill='#ffffff',font=('Times New Roman',20))
        self.bg_lines=[]
        start_combi=[]
        end_combi=[]
        differences=[]
        for x in range(0,3):
            start_combi.append(int(start[(x*2 + 1):(x*2+3)],16))
            end_combi.append(int(end[(x*2+1):(x*2+3)],16))
            differences.append((end_combi[x]-start_combi[x])/500)
        cur_combi=start_combi
        prev=time.time()
        sumi=[0,0]
        for x in range(0,500):
            start=time.time()
            hex_code='#'
            for y in range(3):
                a=hex(int(cur_combi[y])).split('x')[-1]
                a=('0'*(2-len(a)))+a
                hex_code+=a
            self.bg_lines.append(canvas.create_line(0,x,500,x,fill=hex_code))
            canvas.tag_raise(self.players[0].id)
            canvas.tag_raise(self.players[1].id)
            canvas.tag_raise(self.scores[0].id)
            canvas.tag_raise(self.scores[1].id)
            canvas.tag_raise(self.text)
            if x==166:
                canvas.itemconfig(self.text,text='2...')
            elif x==332:
                canvas.itemconfig(self.text,text='1...')
            if (x%2)==0:
                tk.update()
                if (x%10)==0:
                    send('`')
                    get_msg()#makes the faster code slow down for the slow dude
            for y in range(3):
                cur_combi[y]+=differences[y]
        #print(sumi[0]/sumi[1]) average wait time
        canvas.itemconfig(self.text,state='hidden')
        canvas.bind_all('<KeyPress>',self.press)
        canvas.bind_all('<KeyRelease>',self.release)
        self.seq=''
        self.dict={}
        self.inactive=False
    def restart(self,start='#ffff00',end='#ff0000'):
        for p in self.players:
            p.restart()
        for l in self.bg_lines:
            self.canvas.delete(l)
        self.canvas.itemconfig(self.text,text='3...',fill='#ffffff',state='normal')
        self.bg_lines=[]
        start_combi=[]
        end_combi=[]
        differences=[]
        for x in range(0,3):
            start_combi.append(int(start[(x*2 + 1):(x*2+3)],16))
            end_combi.append(int(end[(x*2+1):(x*2+3)],16))
            differences.append((end_combi[x]-start_combi[x])/500)
        cur_combi=start_combi
        prev=time.time()
        sumi=[0,0]
        for x in range(0,500):
            start=time.time()
            hex_code='#'
            for y in range(3):
                a=hex(int(cur_combi[y])).split('x')[-1]
                a=('0'*(2-len(a)))+a
                hex_code+=a
            self.bg_lines.append(canvas.create_line(0,x,500,x,fill=hex_code))
            canvas.tag_raise(self.players[0].id)
            canvas.tag_raise(self.players[1].id)
            canvas.tag_raise(self.text)
            canvas.tag_raise(self.scores[0].id)
            canvas.tag_raise(self.scores[1].id)
            if x==166:
                canvas.itemconfig(self.text,text='2...')
            elif x==332:
                canvas.itemconfig(self.text,text='1...')
            if (x%2)==0:
                tk.update()
                if (x%10)==0:
                    send('`')
                    get_msg()
            for y in range(3):
                cur_combi[y]+=differences[y]
        canvas.itemconfig(self.text,state='hidden')
        self.seq=''
        self.dict={}
        self.inactive=False
    def simulated_press(self,char):
        #print('Pressed',char)
        e=char
        '''if e in ['r',' ']:
            self.restart()
            return False'''
        if self.inactive==True:
            return 'meh'
        if e in self.dict and self.dict[e][0]==True:#it's just held there
            return 'weird'
        if e in self.dict:
            delay=time.time()-self.dict[e][1]
            if 0.01<delay and delay<0.15 and self.dict[e][2]<0.1:#ensure previous press was quick press
                self.dict[e]=(True,time.time())#since old value can now be discarded
                if e =='s':
                    self.players[0].turn(70)
                    self.players[0].movements.append([self.players[0].direction,5,20])
                    self.dict[e]=(True,time.time()-50)#so that press time too huge, avoid counting in another double dash
                elif e =='l':
                    self.players[1].turn(70)
                    self.players[1].movements.append([self.players[1].direction,5,20])
                    self.dict[e]=(True,time.time()-50)
            else:
                if time.time()-self.dict[e][1]<0.02:#questionable
                    self.dict[e]=(True,self.dict[e][1]-self.dict[e][2])#if you algebra, second one gives the first press time
                else:
                    self.dict[e]=(True,time.time())
        else:
            self.dict[e]=(True,time.time())
    def press(self,evt):
        global host
        if host==True and evt.char in ['k','l']:
            return False#opponent keys
        if host==False and evt.char in ['a','s']:
            return False#opponent keys
        if evt.char in ['a','s']:
            print(host)
        if evt.char in ['k','a']:#shoot
            self.seq+='1'
        elif evt.char in ['l','s']:#turn
            self.seq+='2'
        self.simulated_press(evt.char)
    def simulated_release(self,char):
        #print("Released",char)
        e=char
        if e in self.dict and self.dict[e][0]==False:#it's just held there
            return 'weird'
        if not e in self.dict:
            self.dict[e]=(False,time.time(),0.01)
            return 'weird'
        self.dict[e]=(False,time.time(),time.time()-self.dict[e][1])#false, release time, press time
    def release(self,evt):
        if host==True and evt.char in ['k','l']:
            return False#opponent keys
        if host==False and evt.char in ['a','s']:
            return False#opponent keys
        if evt.char in ['k','a']:#shoot
            self.seq+='3'
        elif evt.char in ['l','s']:#turn
            self.seq+='4'
        self.simulated_release(evt.char)
    def overlap(self,p1,p2):
        pos1=self.canvas.coords(p1.id)
        pos2=self.canvas.coords(p2.id)
        for x in range(3):
            if point_in_tri(pos1[x*2],pos1[x*2+1],p2.id):
                return True
        for x in range(3):
            if point_in_tri(pos2[x*2],pos2[x*2+1],p1.id):
                return True
        return False
    def cross_check(self,p1,p2):
        #check bullets
        if p1.check_all()==True:
            self.canvas.itemconfig(self.text,text='Player 1 won!')
            self.canvas.itemconfig(self.text,fill=self.canvas.itemcget(p1.id,'fill'))
            self.canvas.itemconfig(self.text,state='normal')
            self.scores[0].add()
            return True
        elif p2.check_all()==True:
            self.canvas.itemconfig(self.text,text='Player 2 won!')
            self.canvas.itemconfig(self.text,fill=self.canvas.itemcget(p2.id,'fill'))
            self.canvas.itemconfig(self.text,state='normal')
            self.scores[1].add()
            return True

        #then check overlap
        while self.overlap(p1,p2):
            pos1=self.canvas.coords(p1.id)
            pos2=self.canvas.coords(p2.id)
            mid1=[(pos1[0]+pos1[2]+pos1[4])/3,(pos1[1]+pos1[3]+pos1[5])/3]
            mid2=[(pos2[0]+pos2[2]+pos2[4])/3,(pos2[1]+pos2[3]+pos2[5])/3]
            bearing=find_angle(mid1[0],mid1[1],mid2[0],mid2[1])
            #print(bearing)
            
            '''total_dist=math.sqrt((mid1[0]-mid2[0])**2+(mid1[1]-mid2[1])**2)
            mid1[0],mid1[1]=rotate(mid1[0],mid1[1],mid2[0],mid2[1],360-bearing)
            p1_dist=0
            for x in range(3):
                pos1[x*2],pos1[x*2+1]=rotate(pos1[x*2],pos1[x*2+1],mid2[0],mid2[1],360-bearing)#should now be on the right
                p1_dist=max(p1_dist,mid1[0]-pos1[x*2])#find leftmost point first'''
            p1.move(1,bearing)
            p2.move(1,(bearing+180)%360)
        return False
    def mainloop(self):
        char_id=0
        while True:
            if self.inactive:
                time.sleep(0.1)
                if 'q' in self.dict:
                    self.canvas.destroy()
                    tk.destroy()
                    break
                tk.update()
                continue
            #if self.seq!='':
            #    print(chr(97+char_id)+self.seq)
            send(chr(97+char_id)+self.seq+';')#sync, and also do what opponent did...
            self.seq=''
            char_id=((char_id+1)%26)
            s=get_msg()#need to be executed...
            #if len(s)>2:
            #    print(s)
            for ii in range(1,len(s)-1):
                i=s[ii]
                if host==True:
                    if i=='1':
                        self.simulated_press('k')
                    if i=='2':
                        self.simulated_press('l')
                    if i=='3':
                        self.simulated_release('k')
                    if i=='4':
                        self.simulated_release('l')
                else:
                    if i=='1':
                        self.simulated_press('a')
                    if i=='2':
                        self.simulated_press('s')
                    if i=='3':
                        self.simulated_release('a')
                    if i=='4':
                        self.simulated_release('s')
                        
            if 'a' in self.dict and self.dict['a'][0]==True:
                self.players[0].shoot()
            if 's' in self.dict and self.dict['s'][0]==True:
                self.players[0].turn(5)
            if 'k' in self.dict and self.dict['k'][0]==True:
                self.players[1].shoot()
            if 'l' in self.dict and self.dict['l'][0]==True:
                self.players[1].turn(5)
            if 'q' in self.dict:
                self.canvas.destroy()
                tk.destroy()
                break
            for x in range(len(self.players)):
                p=self.players[x]
                p.update_pos()
            if self.cross_check(self.players[0],self.players[1]):
                self.inactive=True
                tk.update()
                continue
            tk.update()

#connection stuff
if input('Host game? Input y/n:')=='y':
    #host
    host=True
    print('You\'ll be the green player 1. s to turn, a to shoot...')
    print('Hosted game. Your IP address is',a_socket.gethostbyname(a_socket.gethostname()))
    server=socket(AF_INET,SOCK_STREAM)
    port=7000
    while True:
        try:
            server.bind(('',port))
            break
        except OSError:
            port+=1
    print('Hosting on port',port)
    print('Waiting for connection...')
    while True:
        while True:
            server.listen(1)
            try:
                link,addr=server.accept()
                break
            except OSError:
                continue
        print('Client says:',get_msg()[:-1])#since added semi-colon to allow blank string
        received=False
        if input('Accept request? Input y/n:')=='n':
            send('n')
            link.close()
            print('Ok rejected client. Waiting for new client...')
        else:
            send('y')
            print('Accepted client :)')
            break
    
else:
    #client
    host=False
    while True:
        print("You'll be the blue player 2. l to turn, k to shoot...")
        host_ip=input('Ask host for IP address:')
        port=int(input('Ask the host the port he chose:'))
        msg=input('Message to host (for identification, can leave blank):')+';'
        try:
            addr=(host_ip,port)
            link=socket(AF_INET,SOCK_STREAM)
            link.connect(addr)
            print('Waiting for host to respond...')
            send(msg)
            r=get_msg()
            received=False
            if r=='y':
                print('Host acccepted :)')
                break
            else:
                print('You got REJECTED.')
                print('Get another host:')
        except KeyboardInterrupt:
            pass
        except ConnectionRefusedError:
            print('Host not accepting. Either wrong info, or host is busy')
    #connected
#now link should be ip address of the other person

#assume this point to be same timing...
start=time.time()

tk=Tk()
tk.title('Astroparty')
tk.resizable(0,0)
canvas=Canvas(tk,width=500,height=500,bg='#000000',bd=0,highlightthickness=0)
canvas.pack()

'''start_point=(250,250)
point_set=True

bullets=Bullet(canvas)

def click(evt):
    global point_set
    global start_point
    if point_set==False:
        point_set=True
        start_point=(evt.x,evt.y)
    else:
        point_set=False
        bullets.shoot(start_point[0],start_point[1],find_angle(evt.x,evt.y,start_point[0],start_point[1]))

canvas.bind_all('<ButtonPress-1>',click)'''

g=Game(canvas)
#time.sleep(6-(time.time()-start))
#need to sync at this line...
g.mainloop()
