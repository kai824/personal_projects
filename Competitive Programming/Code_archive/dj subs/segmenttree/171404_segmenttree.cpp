// segmenttree.cpp 16 Dec 16, 12:59:09 0 1 Judging completed in 6.777s on AWS Ireland.
#include "segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> tree;
int n;
/*I am a tree
Like you I breathe
But you need me
But I don't need you*/
void init(int N) {
    tree.assign(2*N,0);
    n=N;
}

void update2(int u){
    if(u>=1){
        tree[u]=min(tree[u*2],tree[u*2 +1]);
        u=u/2;
        update2(u);
    }
}

void update(int P, int V) {
    int a=tree.size()-(n-P);
    tree[a]=V;
    a=a/2;
    update2(a);
}
int query2(int first,int last,int it,int a,int b){
    if(a==b)return tree[it];
    if(first==a && last==b)return tree[it];
    if(a>last-(last-first+1)/2)return query2(last-(last-first+1)/2,last,it*2+1,a,b);
    else if(b<=last-(last-first+1)/2)return query2(first,last-(last-first+1)/2,it*2+1,a,b);
    else{
        return(min(query2(first,last-(last-first+1)/2,
        it*2,a,last-(last-first+1)/2),
        query2(last-(last-first+1)/2+1,last,it*2+1,
        last-(last-first+1)/2+1,b)));
    }
}
int query(int A, int B) {
    return query2(1,n,1,A,B);
}
