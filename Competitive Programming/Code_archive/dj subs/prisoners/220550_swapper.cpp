// swapper.cpp 21 Sep 17, 09:27:42 100 0 Judging completed in 9.028s on AWS Oregon.
#include "swapper.h"
#include<bits/stdc++.h>
using namespace std;
void swapper(int n, int boxes[]) {
	int x=2*n,cycle_length,first,prev,cur;//total number of unconfirmed stuff...
	bool a[2*n];
	vector<int> cycle;
	memset(a,0,sizeof(a));
	while(true){
	    cycle_length=1;
	    //mark all the stuff in cycle...
	    for(int x=0;x<2*n;x++){
	        if(!a[x]){
	            first=x;
	            break;
	        }
	    }
	    prev=first;cur=boxes[first];
	    cycle.push_back(first);
	    while(cur!=first){
	        cycle_length++;
	        prev=cur;
	        cycle.push_back(cur);
	        cur=boxes[cur];
	    }
	    
	    if(cycle_length>n){
	        swapKeys(cycle[0],cycle[cycle_length-n]);break;//NOT DONE HERE
	    }else{
	        x-=cycle_length;
	        if(x<n)break;
	        for(int x=0;x<cycle.size();x++){
	            a[cycle[x]]=true;
	        }
	    }
	}
}