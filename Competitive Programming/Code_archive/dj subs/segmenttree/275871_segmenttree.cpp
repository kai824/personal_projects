// segmenttree.cpp 2 Dec 17, 15:58:05 0 1 Judging completed in 5.841s on AWS Oregon.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
int DEFAULT_VALUE=0;

int pro(int a,int b){
	return(min(a,b));
}

struct node{
	int v,s,e;
	node *l=nullptr,*r=nullptr;
	node(int ss,int ee){
		v=DEFAULT_VALUE;
		s=ss;
		e=ee;
	}
} *root;

void init(int N) {
    root = new node(1,N);
}

int xxx,yyy;
void update1(node *n,int p,int v){
	if(n->s==n->e){
		n->v=v;
		return;
	}
	xxx=(n->s + n->e - 1)/2;
	if(p<=xxx){
		if(n->l==nullptr){
			n->l=new node(n->s,xxx);
		}
		update1(n->l,p,v);
		if(n->r==nullptr)n->v=DEFAULT_VALUE;
		else n->v=n->r->v;
		n->v=pro(n->v,n->l->v);
	}else{
		if(n->r==nullptr){
			n->r=new node(xxx+1,n->e);
		}
		update1(n->r,p,v);
		if(n->l==nullptr)n->v=DEFAULT_VALUE;
		else n->v=n->l->v;
		n->v=pro(n->v,n->r->v);
	}
}

void update(int P, int V) {
    update1(root,P+1,V);
}

int query1(node *n,int s,int e){
	if(n->s==s && n->e==e){
		return n->v;//the node will always be relevant...
	}
	xxx=(n->s + n->e - 1)/2;
	if(e<=xxx){
		if(n->l==nullptr){
			return DEFAULT_VALUE;
		}
		return query1(n->l,s,e);
	}else if(s>xxx){
		if(n->r==nullptr){
			return DEFAULT_VALUE;
		}
		return query1(n->r,s,e);
	}else{
		//the middle is in the range...
		if(n->l==nullptr){
			yyy=DEFAULT_VALUE;
		}else{
			yyy=query1(n->l,s,xxx);
		}
		if(n->r==nullptr){
			return(pro(yyy,DEFAULT_VALUE));
		}else{
			return(pro(yyy,query1(n->r,xxx+1,e)));
		}
	}
}

int query(int a, int b){
    query1(root,a+1,b+1);
}