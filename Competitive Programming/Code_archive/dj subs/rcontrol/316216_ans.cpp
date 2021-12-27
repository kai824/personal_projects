// ans.cpp 14 Jan 18, 21:27:48 1 0.94 Judging completed in 7.669s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#define DEFAULT_VALUE 0
#define ONE 0

int process(int a,int b){
    return(a+b);
}

struct node{
	int v=DEFAULT_VALUE;
	node *l=NULL,*r=NULL;
	node(){}
	
	void update(int p,int new_val,int s,int e){
	    if(p==s && p==e){
	        v+=new_val;
	        return;
	    }
	    if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node();
	        l->update(p,new_val,s,(s+e)/2);
	        if(r==NULL){
	            v=process(l->v,DEFAULT_VALUE);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }else{
	        //update the right...
	        if(r==NULL)r=new node();
	        r->update(p,new_val,((s+e)/2) + 1,e);
	        if(l==NULL){
	            v=process(DEFAULT_VALUE,r->v);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }
	}
	
	int query(int a,int b,int s,int e){
	    if(a<=s&&e<=b)return v;
	    int v_left,v_right;
	    if( ( (s+e)/2 )<a ){//left child not relevant
	        v_left=ONE;
	    }else{//left child relevant;
	        if(l==NULL)v_left=DEFAULT_VALUE;
	        else v_left=l->query(a,b,s,(s+e)/2);
	    }
	    if(b<=( (s+e)/2 ) ){//right child irrelvant
	        v_right=ONE;
	    }else{
	        if(r==NULL)v_right=DEFAULT_VALUE;
	        else v_right=r->query(a,b,((s+e)/2) + 1,e);
	    }
	    return process(v_left,v_right);
	}
} *m;
int xd[4]={-1,1,0,0};//horizontal, maximum of x is r
int yd[4]={0,0,-1,1};//vertical, maximum of y is c
map<int,typeof(m)>xnums,ynums;
void xupdate(int row,int s,int e){
	if(xnums[row]==NULL){
		//time to create one(segment tree)...
		m=new node();
		xnums[row]=m;
	}
	m->update(s,1,1,1e9);
	if(e+1>1e9)return;
	m->update(e+1,-1,1,1e9);
}
void yupdate(int column,int s,int e){
	if(ynums[column]==NULL){
		m=new node();
		ynums[column]=m;
	}
	m->update(s,1,1,1e9);
	if(e+1>1e9)return;
	m->update(e+1,-1,1,1e9);
}
int xquery(int row,int column){
	if(xnums[row]==NULL)return 0;
	return xnums[row]->query(1,column,1,1e9);
}
int yquery(int row,int column){
	if(ynums[column]==NULL)return 0;
	return ynums[column]->query(1,row,1,1e9);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int r,c,n,k,q,it,currentx=1,currenty=1,nx,ny,ai,bi;
	cin>>r>>c>>n>>k>>q;
	string a;
	cin>>a;
	for(int x=0;x<n;x++){
		if(a[x]=='U')it=0;
        else if(a[x]=='D')it=1;
        else if(a[x]=='L')it=2;
        else if(a[x]=='R')it=3;
        if(currentx+xd[it]<1 || currentx+xd[it]>r){
        	continue;
        }
        //in both of these, if you can't even move on step, there is nothing to update...
        if(currenty+yd[it]<1 || currenty+yd[it]>c){
        	continue;
        }
        nx=currentx+(k*xd[it]);
        ny=currenty+(k*yd[it]);
        if(nx<1)nx=1;
        if(nx>r)nx=r;
        if(ny<1)ny=1;
        if(ny>c)ny=c;
        currentx+=xd[it];
        currenty+=yd[it];
        if(nx==currentx){//horizontal
        	xupdate(nx,min(ny,currenty),max(ny,currenty));
        }else{
        	yupdate(ny,min(nx,currentx),max(nx,currentx));
        }
        currentx=nx;
        currenty=ny;
	}
	for(int x=0;x<q;x++){
		cin>>ai>>bi;
		cout<<xquery(ai,bi)+yquery(ai,bi)<<'\n';
	}
	return 0;
}