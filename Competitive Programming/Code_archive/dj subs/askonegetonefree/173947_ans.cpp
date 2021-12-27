// ans.cpp 23 Dec 16, 21:34:33 0 0.06 Judging completed in 5.978s on AWS Ireland.
#include <bits/stdc++.h>
#include "askonegetonefree.h"
using namespace std;
bool ask(int N,vector<pair<int,Answer> > &history){
	bool a;
	for(int x=0;x<history.size();x++){
		a=(history[x].first<=N);
		if(a!=history[x].second.q) return false;
	}
	return query(N).q;
}
Answer guess(int n){
    Answer hi,lo;
    vector<pair<int,Answer> > replies;//input,output
    int mid;
    hi.p=n;
    hi.q=n;
    lo.p=0;
    lo.q=0;
    while(hi.p>lo.p){
    	mid=lo.p+(hi.p-lo.p)/2+1;
    	replies.push_back(make_pair(mid,query(mid)));
    	if(replies.back().second.p==1)lo.p=mid;
    	else hi.p=mid-1;
    }
    while(hi.q>lo.q){
    	mid=lo.q+(hi.q-lo.q)/2+1;
    	if(ask(mid,replies))lo.q=mid;
    	else hi.q=mid-1;
    }
    return lo;
}