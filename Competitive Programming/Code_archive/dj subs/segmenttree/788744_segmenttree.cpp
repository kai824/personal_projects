// segmenttree.cpp 19 Nov 20, 11:20:43 0 0 Compilation failed on AWS Oregon.
#include "segmenttree.h"
using namespace std;

struct node{
    int s,e,v=0;
    node *l,*r;
    new node(int ss,int ee){
        s=ss;e=ee;
        if(s==e)l=r=NULL;
        else{
            l=new node(s,(s+e)/2);
            r=new node((s+e)/2+1,e);
        }
    }
    void update(int p,int nv){//new value
        if(s==e){
            v=nv;
            return;
        }
        if(p<=(s+e)/2){
            l->update(p,nv);
        }else r->update(p,nv);
        v=min(l->v,r->v);
    }
    int query(int a,int b){
        if(a<=s && e<=b){
            return v;
        }
        int ans=INT_MAX;
        if(a<=(s+e)/2){
            ans=l->query(a,b);
        }
        if((s+e)/2<b)ans=min(ans,r->query(a,b) );
        
        return ans;
    }
} *root;

void init(int N) {
    root=new node(0,N);
    return;
}

void update(int P, int V) {
    root->update(P,V);
}

int query(int A, int B) {
    return root->query(A,B);
}