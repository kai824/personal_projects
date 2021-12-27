// segmenttree.cpp 14 Jan 18, 00:14:58 0 0 Compilation failed on AWS Oregon.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
#define DEFAULT_VALUE 0//IMPT
#define ONE 2e9//IMPT
//if you are using this for another problem, please take not of all the comments marked as IMPT using command f

int process(int a,int b){
    return(min(a,b));//IMPT
}
struct node{
	int v=DEFAULT_VALUE;
	//x is the one telling top or bottom
	//y is the one telling left or right
	node *tl=NULL,*tr=NULL,*bl=NULL,*br=NULL;//quad tree...
	node(){}
	void update(int sx,int sy,int ex, int ey,   int x,int y,int add){
		if(sx==ex && sy==ey){
			v+=add;
			return;
		}
		
		if(x<=((sx+ex)/2)){//top
			if(y<=((sy+ey)/2)){//left
				if(tl==NULL)tl=new node();
				tl->update(sx,sy,((sx+ex)/2),((sy+ey)/2),x,y,add);
			}else{//right
				if(tr=NULL)tr=new node();
				tr->update(sx,((sy+ey)/2)+1,((sx+ex)/2),ey,x,y,add);
			}
		}else{//bottom
			if(y<=((sy+ey)/2)){//left
				if(bl==NULL)bl=new node();
				bl->update(((sx+ex)/2)+1,sy,ex,((sy+ey)/2),x,y,add);
			}else{//right
				if(br==NULL)br=new node();
				br->update(((sx+ex)/2)+1,((sy+ey)/2)+1,ex,ey,x,y,add);
			}
		}
		//update the value...
		add=ONE;//now used as ans...
		if(tl!=NULL)add=process(add,tl->v);
		if(tr!=NULL)add=process(add,tr->v);
		if(bl!=NULL)add=process(add,bl->v);
		if(br!=NULL)add=process(add,br->v);
		//IMPT:in other cases where ONE is not the same as DEFAULT_VALUE, the if-statements need to have an else add=process(add,DEFAULT_VALUE);
		v=add;
		if(add==ONE)add=DEFAULT_VALUE
	}
	int query(int sx,int sy,int ex,int ey,     int tx,int ty,int bx,int by){
		if(tx<=sx && ex<=bx && ty<=sy && ey<=by)return v;
		int ans=ONE;
		//tl
		if(tx<=((sx+ex)/2) && ty<=((sy+ey)/2)){
			if(tl==NULL)ans=DEFAULT_VALUE;
			else ans=tl->query(sx,sy,((sx+ex)/2),((sy+ey)/2),tx,ty,bx,by);
		}
		//tr
		if(tx<=((sx+ex)/2) && ((sy+ey)/2)<by){
			if(tr==NULL)ans=process(ans,DEFAULT_VALUE);//IMPT:in some cases of DEFAULT_VALUE, you might need like exponentiation(range multiplication) or multiplication(range sum)
			else ans=process(ans,tr->query(sx,((sy+ey)/2)+1,((sx+ex)/2),ey,tx,ty,bx,by));
		}
		//bl
		if(((sx+ex)/2)<bx && ty<=((sy+ey)/2)){
			if(bl==NULL)ans=process(ans,DEFAULT_VALUE);
			else ans=process(ans,bl->query(((sx+ex)/2)+1,sy,ex,((sy+ey)/2),tx,ty,bx,by));
		}
		//br
		if(((sx+ex)/2)<bx && ((sy+ey)/2)<by){
			if(br==NULL)ans=process(ans,DEFAULT_VALUE);
			else ans=process(ans,br->query(((sx+ex)/2)+1,((sy+ey)/2)+1,ex,ey,tx,ty,bx,by));
		}
		return ans;
	}
} *root;
int n;
void init(int N) {
    root=new node();
}

void update(int P, int V) {
    root->update(0,0,1e9,1e9,rand()%1e9,p,v);
}

int query(int a, int b){
    return root->query(0,0,1e9,1e9,0,a,1e9,b);
}