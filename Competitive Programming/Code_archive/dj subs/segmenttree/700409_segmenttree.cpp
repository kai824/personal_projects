// segmenttree.cpp 15 Feb 20, 12:46:05 100 0.53 Judging completed in 8.968s on AWS Oregon.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
//trying to speed code a segtree lol
//3.5 minutes

struct node{
    int s,e,v=0;
    node *l,*r;
    node(int ss,int ee){
        s=ss;e=ee;
        if(s==e){
            l=r=NULL;
        }else{
            l=new node(s,(s+e)/2);
            r=new node((s+e)/2+1,e);
        }
    }
    void update(int p,int nv){
        if(s==e){
            v=nv;
            return;
        }
        if(p<=(s+e)/2){
            l->update(p,nv);
        }else{
            r->update(p,nv);
        }
        v=min(l->v,r->v);
    }
    int query(int ll,int rr){
        if(ll<=s && e<=rr){
            return v;
        }
        int ans=INT_MAX;
        if(ll<=(s+e)/2){
            ans=min(ans,l->query(ll,rr));
        }
        if((s+e)/2<rr){
            ans=min(ans,r->query(ll,rr));
        }
        return ans;
    }
} *root;

void init(int N) {
    root=new node(0,N);
}

void update(int P, int V) {
    root->update(P,V);
}

int query(int A, int B) {
    return root->query(A,B);
}