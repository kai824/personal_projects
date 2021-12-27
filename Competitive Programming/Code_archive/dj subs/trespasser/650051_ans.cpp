// ans.cpp 16 Dec 19, 12:24:22 0 0 Judging completed in 5.379s on AWS Oregon.
#include <bits/stdc++.h>
#include "trespasser.h"
using namespace std;

int l,o,cur;

void trespasser(int S, int r, int n, int L, int M){
	l=L;
	o=ring_move(0,0);
	for(int x=0;x<r;x++){
		for(int i=0;i<2*n;i++){
			cur=ring_move(x,1);
			if(cur==L)return;
			if(cur>o){
				break;
			}else if(cur==o-1){
				o=ring_move(x,-1);
				break;
			}else o=cur;
		}
	}
	return;
}