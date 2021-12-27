
class Tk:#useless
    def __init__(self):
        self.canvas=None
    def lift(self):pass
    def update(self):pass
    def update_idletasks(self):pass
    def resizable(self,*args,**kwargs):pass
    def lift(self,*args,**kwargs):pass
    def title(self,*args,**kwargs):pass
    def destroy(self):#used to delete the canvas, so useless too
        pass

class Canvas:#not useless...
    def __init__(self,*args,**kwargs):
        self.sprites={}#maps id to coords of sprite...
        self.nex=1#next id...
    def pack(self,*args,**kwargs):pass
    def tag_raise(self,*args,**kwargs):pass
    def destroy(self,*args,**kwargs):pass
    def bind_all(self,*args,**kwargs):pass
    def itemconfig(self,*args,**kwargs):pass
    def tag_raise(self,*args,**kwargs):pass

    def create_text(self,*args,**kwargs):return -1

    def create_sprite(self,x,y,x2,y2,**kwargs):
        self.sprites[self.nex]=[x,y,x2,y2]
        self.nex+=1
        return self.nex-1
    def create_oval(self,x,y,x2,y2,**kwargs):
        return self.create_sprite(x,y,x2,y2)
    def create_rectangle(self,x,y,x2,y2,**kwargs):
        return self.create_sprite(x,y,x2,y2)
    def move(self,id,x,y,**kwargs):
        self.sprites[id][0]+=x
        self.sprites[id][2]+=x
        self.sprites[id][1]+=y
        self.sprites[id][3]+=y
    def coords(self,id,**kwargs):
        return self.sprites[id]
    def delete(self,id,**kwargs):
        if id==-1:return None
        else: del self.sprites[id]
