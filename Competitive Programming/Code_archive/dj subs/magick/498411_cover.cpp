// cover.cpp 25 Feb 19, 11:16:26 0 0.04 Judging completed in 6.639s on AWS Oregon.
#include <bits/stdc++.h>
#include "cover.h"

using namespace std;

int cover(int n, int k, string s) {
    int sums[k];
    for(int x=0;x<k;x++){
        sums[x]=0;
    }
	for(int x=0;x<s.length();x++){
	    sums[x%k]+=s[x]-'0';
	    sums[x%k]%=10;
	}
	int ans=0;
	for(int x=0;x<k;x++){
	    ans*=10;
	    ans+=sums[x];
	}
	return ans+1;
}