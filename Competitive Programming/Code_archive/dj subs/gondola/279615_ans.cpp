// ans.cpp 5 Dec 17, 22:58:14 75 0.04 Judging completed in 5.709s on AWS Oregon.
#include "gondola.h"
#include<bits/stdc++.h>
using namespace std;

int valid(int n, int in[]){
    vector<int>v;
    int expected=-1;
    for(int x=0;x<n;x++){
        if(in[x]>n)v.push_back(in[x]);
        else if(expected!=-1){
            if(expected!=in[x]){//input not what you expect...
                return 0;
            }
        }else{
        	expected=in[x];
        }
        if(expected!=-1){
            expected++;
            if(expected>n)expected=1;
        }
    }
    sort(v.begin(),v.end());
    for(int x=1;x<v.size();x++){
        if(v[x]==v[x-1]){
            return 0;
        }
    }
    return 1;
}

int replacement(int n, int in[], int replacementSeq[]) {
    vector<pair<int,int> >v;//kind of the iterator, then the gondola value...
    int next=n,expected=-1,last,ans=0;
    for(int x=0;x<n;x++){
    	if(x+1==n)last=expected;
        if(in[x]>n){
        	if(expected==-1)v.push_back({in[x],-x-1});
        	else v.push_back({in[x],expected});
        }else if(expected==-1){
        	expected=in[x];
        }
        if(expected!=-1){
            expected++;
            if(expected>n)expected=1;
        }
    }
    sort(v.begin(),v.end());//only those exceeding n...
    if(expected==-1){
    	for(int x=0;x<v.size();x++){
    		v[x].second*=-1;
    		while(next<v[x].first){
    			replacementSeq[ans]=v[x].second;
    			ans++;
    			next++;
    			v[x].second=next;
    		}
    	}
    	return ans;
    }
    
    
    if(last==-1){
    	last=expected-1;
    	if(last==0)last=n;
    }
    for(int x=0;x<v.size();x++){
    	if(v[x].second<0){
    		v[x].second*=-1;
    		v[x].second+=last;
    		if(v[x].second>n)v[x].second-=n;
    	}
    	while(next<v[x].first){
    		replacementSeq[ans]=v[x].second;
    		ans++;
    		next++;
    		v[x].second=next;
    	}
    }
    return ans;
}


typedef unsigned long long ll;
ll m=1000000009;
ll ipow(ll base, ll exponent) { 
	//if(base==1)return 1;
    ll result=1;
    while (exponent){
        if (exponent%2==1) result*=base;
        base *= base;
        base %= m;
        result %= m;
        exponent >>= 1;
    }
    return result;
}
int countReplacement(int n, int in[]) {
	if(valid(n,in)==0)return 0;
    vector<pair<ll,ll> >v;//kind of the iterator, then the gondola value...
    ll last,expected=-1,next=n+1;
    ll ans=1;
    for(ll x=0;x<n;x++){
    	if(x+1==n)last=expected;
        if(in[x]>n){
        	if(expected==-1)v.push_back({in[x],-x-1});
        	else v.push_back({in[x],expected});
        }else if(expected==-1){
        	expected=in[x];
        }
        if(expected!=-1){
            expected++;
            if(expected>n)expected=1;
        }
    }
    sort(v.begin(),v.end());
    ll perms;
    if(expected==-1){
    	perms=1;
    	for(ll x=1;x<=n;x++){
    		perms*=x;
    		perms%=m;
    	}
    }
    
    for(ll x=0;x<v.size();x++){
    	ans*=ipow(v.size()-x,v[x].first-next);
    	ans%=m;
    	next=v[x].first+1;
    }
    if(expected==-1)ans*=perms;
    ans%=m;
    return ans;
}