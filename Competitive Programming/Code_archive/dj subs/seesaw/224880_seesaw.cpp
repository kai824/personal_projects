// seesaw.cpp 20 Oct 17, 14:19:17 100 0.24 Judging completed in 6.318s on AWS Oregon.
#include "seesaw.h"
#include<bits/stdc++.h>
using namespace std;

int mini=0,maxi=1,cur,cur2;

void seesaw(int n, int R) {
	if(n==1){
	    answer(0,0);
	    return;
	}
	if(less_than(maxi,mini))swap(maxi,mini);
	for(int x=2;x<n;x+=2){
	    if(x+1<n){
	        cur=x;
	        cur2=x+1;
	        if(less_than(cur,cur2)==false){
	            swap(cur,cur2);
	        }
	        if(less_than(maxi,cur2)){
	            maxi=cur2;
	        }
	        if(less_than(cur,mini)){
	            mini=cur;
	        }
	    }else{//only x left...
	        if(less_than(x,mini)){
	            mini=x;
	        }else if(less_than(maxi,x)){
	            maxi=x;
	        }
	    }
	}
	answer(mini,maxi);
}