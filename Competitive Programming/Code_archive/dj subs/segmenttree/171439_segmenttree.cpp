// segmenttree.cpp 16 Dec 16, 15:12:04 0 1 Judging completed in 9.09s on AWS Ireland.
#include"segmenttree.h"
#include<bits/stdc++.h>
using namespace std;
vector<int> tree;
int n,additional=0;
/*I am a tree
Like you I breathe
But you need me
But I don't need you*/
bool ilog(int a){
    double x=a;
    x=log2(x);
    return(x==floor(x));
}
void init(int N) {
	int lo;
	if(ilog(N*2)){
		tree.assign(N*2,0);
		n=N;
		return;
	}
    for(int x=N+1;x<=N*3;x++){
        if(ilog(x)){
        	lo=x;
        	break;
        }
    }
    tree.assign(lo*2,0);
    for(int x=tree.size()-1;x>tree.size()-1-(lo-N);x--){
        tree[x]=INT_MAX;
        additional++;
    }
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
    int a=tree.size()-(n-P)-additional-1;
    tree[a]=V;
    a=a/2;
    update2(a);
}
int query2(int first,int last,int it,int a,int b){
    if(a==b){
    	return tree[tree.size()-(n-a)-additional-1];
    }if(first==a && last==b){
    	return tree[it];
    }if(a>last-(last-first+1)/2)return query2(last-(last-first+1)/2,last,it*2+1,a,b);
    else if(b<=last-(last-first+1)/2)return query2(first,last-(last-first+1)/2,it*2,a,b);
    else{
        return(min(query2(first,last-(last-first+1)/2,
        it*2,a,last-(last-first+1)/2),
        query2(last-(last-first+1)/2+1,last,it*2+1,
        last-(last-first+1)/2+1,b)));
    }
}
int query(int A, int B) {
    return query2(1,n+additional,1,A,B);
}