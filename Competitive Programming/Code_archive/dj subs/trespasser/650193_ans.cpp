// ans.cpp 16 Dec 19, 12:44:08 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
#include "trespasser.h"
using namespace std;

int l,o,cur,R;

bool dfs(int depth){
    if(depth>=R)return;
    for(int x=0;x<2*N;x++){
        if(ring_move(depth,1)==l)return true;
        if(dfs(depth+1))return true;
    }
    return false;
}

void trespasser(int S, int r, int n, int L, int M){
    if(S==1){
        R=r;
        dfs(0);
        return;
    }
	l=L;o=0;
	while(o<l){
    	for(int x=r-1;x>=0;x--){
    	    o=ring_move(0,0);
    		for(int i=0;i<2*n;i++){
    			cur=ring_move(x,1);
    			if(cur==L)return;
    			if(cur>o){
    				break;
    			}
    		}
    	}
	}
	return;
}