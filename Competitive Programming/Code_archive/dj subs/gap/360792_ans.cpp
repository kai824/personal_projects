// ans.cpp 6 May 18, 12:16:57 0 0 Compilation failed on AWS Oregon.
#include "gap.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll findGap(int t, int n){
    ll mn,mx=A[0];
	if(t!=0){
		vector<ll> v1,v2;
	    ll s=LLONG_MIN,e=LLONG_MAX,p1=1,p2=n;
	    while(p1<=p2){
	        if(s>e)break;
	        MinMax(s,e,&mn,&mx);
	        if(mn==-1 || mx==-1){
	            break;
	        }
	        v1.push_back(mn);p1++;
	        v2.push_back(mx);p2--;
	        s=mn+1;
	        e=mx-1;
	    }
	    mx=-1;
	    for(int x=1;x<v1.size();x++){
	        mx=max(v1[x]-v1[x-1],mx);
	    }
	    for(int x=1;x<v2.size();x++){
	    	mx=max(v2[x-1]-v2[x],mx);
	    }
	    mx=max(mx,v2.back()-v1.back());
	    return mx;
	}
}