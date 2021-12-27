// segmenttree.cpp 11 Jan 18, 21:04:48 100 0.4 Judging completed in 6.597s on AWS Oregon.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
#define DEFAULT_VALUE 0
#define ONE 2e9

int process(int a,int b){
    return(min(a,b));
}

struct node{
	int v;
	node *l=NULL,*r=NULL;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
	}
	
	void update(int p,int new_val,int s,int e){
	    if(p==s && p==e){
	        v=new_val;
	        return;
	    }
	    if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node(s,(s+e)/2);
	        l->update(p,new_val,s,(s+e)/2);
	        if(r==NULL){
	            v=process(l->v,DEFAULT_VALUE);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }else{
	        //update the right...
	        if(r==NULL)r=new node(((s+e)/2) + 1,e);
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
} *root;
int n;
void init(int N) {
    n=N;
    root=new node(0,(1<<30));
}

void update(int P, int V) {
    root->update(P,V,0,(1<<30));
}

int query(int a, int b){
    return root->query(a,b,0,(1<<30));
}