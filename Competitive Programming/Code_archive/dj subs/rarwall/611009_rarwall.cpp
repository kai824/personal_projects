// rarwall.cpp 19 Nov 19, 19:06:58 14 1.46 Judging completed in 9.532s on AWS Oregon.
#include "rarwall.h"
#include<bits/stdc++.h>
using namespace std;

#define ONE LLONG_MIN


typedef long long ll;
struct node{
	ll v=0,lazy=0;
	node *l=NULL,*r=NULL;
	node(){}
	ll query(ll s,ll e,ll a,ll b){
		if(a<=s && e<=b)return v;
		ll lv=ONE,rv=ONE;
		if(a<=((s+e)/2)){//left child involved
			if(l==NULL){
				lv=lazy;
			}else{
				lv=l->query(s,(s+e)/2,a,b)+lazy;
			}
		}
		if((s+e)/2<b){
			if(r==NULL){
				rv=lazy;
			}else{
				rv=r->query((s+e)/2 + 1,e,a,b)+lazy;
			}
		}
		return max(lv,rv);
	}
	void update(ll s,ll e,ll a,ll b,ll add){
		if(a<=s && e<=b){
			if(s!=e)lazy+=add;
			v+=add;
			return;
		}
		if(a<=((s+e)/2)){//left child involved
			if(l==NULL){
				l=new node();
			}
			l->update(s,(s+e)/2,a,b,add);
		}
		if((s+e)/2<b){
			if(r==NULL){
				r=new node();
			}
			r->update((s+e)/2 + 1,e,a,b,add);
		}
		v=ONE;
		if(l!=NULL)v=max(v,l->v);
		if(r!=NULL)v=max(v,r->v);
		v+=lazy;
	}

	void copy(node* n,int s,int e,int a,int b,ll add){
		v=n->v;lazy=n->lazy;
		l=n->l;r=n->r;
		if(a<=s && e<=b){
			if(s!=e)lazy+=add;
			v+=add;
			return;
		}
		if(a<=((s+e)/2)){//left child involved
			if(l==NULL){
				l=new node();
				l->update(s,(s+e)/2,a,b,add);
			}else{
				l=new node();
				l->copy(n->l,s,(s+e)/2,a,b,add);
			}
		}
		if((s+e)/2<b){
			if(r==NULL){
				r=new node();
				r->update((s+e)/2 + 1,e,a,b,add);
			}else{
				r=new node();
				r->copy(n->r,(s+e)/2 + 1,e,a,b,add);
			}
		}
		v=ONE;
		if(l!=NULL)v=max(v,l->v);
		if(r!=NULL)v=max(v,r->v);
		v+=lazy;
	}
} *st[100005];//1 root node for each version...

ll cur_version=0;

void init(int L, int M, int Q){st[0]=new node();}//meh...

void proposal(int n, int k, int a, int b, int c){
	st[n]=new node();
	st[n]->copy(st[k],0,1e9,a,b,c);
}

long long max_height(int P, int X, int Y) {
    return st[P]->query(0,1e9,X,Y);
}