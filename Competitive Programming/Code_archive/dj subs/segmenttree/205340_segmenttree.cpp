// segmenttree.cpp 27 Apr 17, 21:35:23 0 1 Judging completed in 6.187s on AWS Ireland.
#include "segmenttree.h"
using namespace std;
int segtree[200000];
int n,original[100005];
void initialize(int a,int b,int c){
    if(a==b){
        original[a]=c;
    }else{
        initialize(a,(a+b)/2,c*2);
        initialize((a+b)/2 + 1,b,c*2 + 1);
    }
}
void init(int N) {
    n=N;
    initialize(1,n,1);
}

void update2(int a,int b){
    if(a==0)return;
    segtree[a]=min(segtree[a],b);
    update2(a/2,b);
}
void update(int P, int V) {
    segtree[original[P]]=V;
    update2(original[P]/2,V);
}
int query2(int l,int r,int l2,int r2,int e){
    if(l==l2 && r==r2){return segtree[e];
    }else if(r2<=(l+r)/2){return query2(l,(l+r)/2,l2,r2,e*2);
    }else if((l+r)/2<l2){return query2((l+r)/2 + 1,r,l2,r2,e*2 + 1);
    }else{
        return(min( query2(l,(l+r)/2,l2,(l+r)/2,e*2) , query2((l+r)/2 + 1,r,(l+r)/2 + 1,r2,e*2 + 1) ));
    }
}
int query(int A, int B) {
    return query2(1,n,A,B,1);
}