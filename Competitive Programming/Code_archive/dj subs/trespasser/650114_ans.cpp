// ans.cpp 16 Dec 19, 12:34:03 0 0 Judging completed in 5.513s on AWS Oregon.
#include <bits/stdc++.h>
#include "trespasser.h"
using namespace std;

int l,o,cur;

void trespasser(int S, int r, int n, int L, int M){
	l=L;
	for(int x=1;x<r;x++){
	    o=ring_move(0,0);
		for(int i=0;i<2*n;i++){
			cur=ring_move(x,1);
			if(cur==L)return;
			if(cur>o){
				break;
			}
		}
	}
	return;
}