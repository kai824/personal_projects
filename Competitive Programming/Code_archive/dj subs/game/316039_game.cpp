// game.cpp 14 Jan 18, 13:08:18 0 0.04 Judging completed in 5.411s on AWS Oregon.
#include "game.h"
#include<bits/stdc++.h>
using namespace std;
long long gcd2(long long X, long long Y) {
    if(X<Y)swap(X,Y);
    long long tmp;
    while (X != Y && Y != 0) {
        tmp = X;
        X = Y;
        Y = tmp % Y;
    }
    return X;
}

#define DEFAULT_VALUE 0LL//IMPT
#define ONE 0//IMPT
//if you are using this for another problem, please take not of all the comments marked as IMPT using command f
typedef long long ll;
ll process(ll a,ll b){
    return(gcd2(a,b));//IMPT
}
struct node{
	long long v=DEFAULT_VALUE;
	//x is the one telling top or bottom
	//y is the one telling left or right
	node *tl=NULL,*tr=NULL,*bl=NULL,*br=NULL;//quad tree...
	node(){}
	void update(int sx,int sy,int ex, int ey,   int x,int y,ll add){
		if(sx==ex && sy==ey){
			v=add;
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
		return;
		//update the value...
		add=ONE;//now used as ans...
		if(tl!=NULL)add=process(add,tl->v);
		if(tr!=NULL)add=process(add,tr->v);
		if(bl!=NULL)add=process(add,bl->v);
		if(br!=NULL)add=process(add,br->v);
		//IMPT:in other cases where ONE is not the same as DEFAULT_VALUE, the if-statements need to have an else add=process(add,DEFAULT_VALUE);
		v=add;
	}
	ll query(int sx,int sy,int ex,int ey,     int tx,int ty,int bx,int by){
		if(tx<=sx && ex<=bx && ty<=sy && ey<=by)return v;
		ll ans=ONE;
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
int r,c;
void init(int R, int C) {
    r=R;
    c=C;
    root=new node();
}

void update(int p, int q, long long k) {
    root->update(0,0,r,c,p,q,k);
}

long long calculate(int P, int Q, int U, int V) {
    return(root->query(0,0,r,c,P,Q,U,V) );
}