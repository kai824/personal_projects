#Pacman graphics, so that no need whole chunk of code to do graphics. Like trying to create the thing just based on text file
from tkinter import*
gs=16#grid size
tk=Tk()
tk.title("Testing of creating maps.")
tk.wm_attributes("-topmost",1)
f=open('mymap.txt')
mymap=f.readlines()
f.close()
for x in range(len(mymap)):
    if mymap[x][-1]=='\n':
        mymap[x]=mymap[x][:-1]
canvas=Canvas(tk,width=len(mymap[0])*gs,height=gs*len(mymap),bg='#000000000',highlightthickness=0,bd=0)
print(len(mymap[0])*gs,len(mymap)*gs)
canvas.pack()
for x in range(len(mymap)):
    for y in range(len(mymap[0])):
        if mymap[x][y]=='x':#have work to do...
            bitmask=['0','0','0','0']
            blanks=0
            if (x>0) and mymap[x-1][y]!='x':
                bitmask[0]='1'#need to blank out on top
                blanks+=1
            if (x+1<len(mymap)) and mymap[x+1][y]!='x':
                bitmask[2]='1'#need to blank out below
                blanks+=1
            if (y>0) and mymap[x][y-1]!='x':
                bitmask[1]='1'#need to blank out on left
                blanks+=1
            if (y+1<len(mymap[0])) and mymap[x][y+1]!='x':
                bitmask[3]='1'#need to remove on right
                blanks+=1
            bitmask=bitmask[0]+bitmask[1]+bitmask[2]+bitmask[3]
            if blanks==0:
                canvas.create_rectangle(y*gs,x*gs,(y+1)*gs,(x+1)*gs,fill='blue',outline='blue')
            elif blanks==1:
                if bitmask=='1000':#top
                    canvas.create_rectangle(y*gs,x*gs+(gs/2),(y+1)*gs,(x+1)*gs,fill='blue',outline='blue')
                elif bitmask=='0100':#left
                    canvas.create_rectangle(y*gs+(gs/2),x*gs,(y+1)*gs,(x+1)*gs,fill='blue',outline='blue')
                elif bitmask=='0010':#bottom
                    canvas.create_rectangle(y*gs,x*gs,(y+1)*gs,(x+0.5)*gs,fill='blue',outline='blue')
                else:#right
                    canvas.create_rectangle(y*gs,x*gs,(y+0.5)*gs,(x+1)*gs,fill='blue',outline='blue')
            elif blanks==2:
                #the cancer part...
                if bitmask=='1100':#top left
                    canvas.create_arc((y+0.5)*gs,(x+0.5)*gs,(y+1.5)*gs,(x+1.5)*gs,start=90,extent=90,fill='blue',outline='blue')
                elif bitmask=='0110':#bottom left
                    canvas.create_arc((y+0.5)*gs,(x-0.5)*gs,(y+1.5)*gs,(x+0.5)*gs,start=180,extent=90,fill='blue',outline='blue')
                elif bitmask=='0011':#bottom right
                    canvas.create_arc((y-0.5)*gs,(x-0.5)*gs,(y+0.5)*gs,(x+0.5)*gs,start=270,extent=90,fill='blue',outline='blue')
                elif bitmask=='1001':#top right
                    canvas.create_arc((y-0.5)*gs,(x+0.5)*gs,(y+0.5)*gs,(x+1.5)*gs,start=0,extent=90,fill='blue',outline='blue')
for x in range(len(mymap)):#clearing of corners
    for y in range(len(mymap[0])):
        if mymap[x][y]!='x':
            if x>0 and y>0 and mymap[x-1][y]==mymap[x][y-1]==mymap[x-1][y-1]=='x':#top left
                canvas.create_arc((y-0.5)*gs+1,(x-0.5)*gs+1,(y+0.5)*gs,(x+0.5)*gs,start=90,extent=90,fill='black',outline='black')
            if x+1<len(mymap) and y>0 and mymap[x+1][y]==mymap[x][y-1]==mymap[x+1][y-1]=='x':#bottom left
                canvas.create_arc((y-0.5)*gs+1,(x+0.5)*gs,(y+0.5)*gs,(x+1.5)*gs-1,start=180,extent=90,fill='black',outline='black')
            if x+1<len(mymap) and y+1<len(mymap[0]) and mymap[x+1][y]==mymap[x][y+1]==mymap[x+1][y+1]=='x':#bottom right
                canvas.create_arc((y+0.5)*gs,(x+0.5)*gs,(y+1.5)*gs-1,(x+1.5)*gs-1,start=270,extent=90,fill='black',outline='black')
            if x>0 and y+1<len(mymap[0]) and mymap[x-1][y]==mymap[x][y+1]==mymap[x-1][y+1]=='x':#top right
                canvas.create_arc((y+0.5)*gs,(x-0.5)*gs+1,(y+1.5)*gs-1,(x+0.5)*gs,start=0,extent=90,fill='black',outline='black')
canvas.create_rectangle(208,248,240,256,fill='black',outline='black')
canvas.create_rectangle(208,250,240,254,fill='pink',outline='pink')
canvas.create_rectangle(176,256,272,304,fill='black',outline='black')
