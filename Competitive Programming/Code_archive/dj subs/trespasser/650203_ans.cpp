// ans.cpp 16 Dec 19, 12:44:57 5 0.02 Judging completed in 5.402s on AWS Oregon.
#include <bits/stdc++.h>
#include "trespasser.h"
using namespace std;

int l,o,cur,rr,nn;

bool dfs(int depth){
    if(depth>=rr)return false;
    for(int x=0;x<nn;x++){
		cur=ring_move(depth,1);
        if(cur==l)return true;
        if(dfs(depth+1))return true;
    }
    return false;
}

void trespasser(int S, int r, int n, int L, int M){
    l=L;
    if(S==1 || true){
        rr=r;nn=2*n;
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