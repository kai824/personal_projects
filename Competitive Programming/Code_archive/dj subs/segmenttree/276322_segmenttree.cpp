// segmenttree.cpp 3 Dec 17, 13:21:33 0 0 Compilation failed on AWS Oregon.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
#define DEFAULT_VALUE 0
#define ONE 2e9

int process(int a,int b){
    return(min(a,b));
}

struct node{
	int v,s,e;
	node *l=NULL,*r=NULL;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
		s=ss;
		e=ee;
	}
	
	void update(int p,int new_val){
	    if(p==s && p==e){
	        v=new_val;
	        return;
	    }
	    if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node(s,(s+e)/2);
	        l->update(p,new_val);
	        if(r==NULL){
	            v=process(l->v,DEFAULT_VALUE);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }else{
	        //update the right...
	        if(r==NULL)r=new node(((s+e)/2) + 1,e);
	        r->update(p,new_val);
	        if(l==NULL){
	            v=process(DEFAULT_VALUE,r->v);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }
	    delete p;
	    delete new_val;
	}
	
	int query(int a,int b){
	    if(a<=s&&e<=b)return v;
	    int v_left,v_right;
	    if( ( (s+e)/2 )<a ){//left child not relevant
	        v_left=ONE;
	    }else{//left child relevant;
	        if(l==NULL)v_left=DEFAULT_VALUE;
	        else v_left=l->query(a,b);
	    }
	    if(b<=( (s+e)/2 ) ){//right child irrelvant
	        v_right=ONE;
	    }else{
	        if(r==NULL)v_right=DEFAULT_VALUE;
	        else v_right=r->query(a,b);
	    }
	    delete a;
	    delete b;
	    v_left=process(v_left,v_right);
	    delete v_right;
	    return v_left;
	}
} *root;

void init(int N) {
    root=new node(0,N-1);
}

void update(int P, int V) {
    root->update(P,V);
    delete P;
    delete V;
}

int query(int a, int b){
    return root->query(a,b);
}