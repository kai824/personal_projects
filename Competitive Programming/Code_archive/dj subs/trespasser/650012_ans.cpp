// ans.cpp 16 Dec 19, 12:18:03 0 0 Judging completed in 5.671s on AWS Oregon.
#include <bits/stdc++.h>
#include "trespasser.h"
using namespace std;

int l,o,cur;

void trespasser(int S, int r, int n, int L, int M){
	l=L;
	for(int x=1;x<r;x++){
	    o=INT_MAX;
		for(int i=0;i<n;i++){
			cur=ring_move(x,1);
			if(cur==L)return;
			if(cur>o){
				break;
			}else if(o==INT_MAX && cur==o-1){
				o=ring_move(x,-1);
				break;
			}else o=cur;
		}
	}
	return;
}