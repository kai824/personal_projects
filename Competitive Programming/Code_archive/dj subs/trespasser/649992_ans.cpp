// ans.cpp 16 Dec 19, 12:14:23 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
#include "trespasser.h"
using namespace std;

int l,o=INT_MAX,cur;

void trespasser(int S, int r, int n, int L, int M){
	l=L;
	for(int x=1;x<r;x++){
		for(int i=;i<n;i++){
			cur=ring_move(x,1);
			if(cur>o){
				break;
			}else if(o==INT_MAX && cur==o-1){
				ring_move(x,-1);
				break;
			}else o=cur;
		}
	}
	return;
}