// ans.cpp 16 Dec 19, 12:36:55 20 0.02 Judging completed in 5.624s on AWS Oregon.
#include <bits/stdc++.h>
#include "trespasser.h"
using namespace std;

int l,o,cur;

void trespasser(int S, int r, int n, int L, int M){
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