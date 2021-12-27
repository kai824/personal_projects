// guess.cpp 25 Feb 19, 11:05:36 0 0.07 Judging completed in 10.711s on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int n, int k, string s) {
    int psums[k],ans,sums[k],panses[k];
    string true_ans="";
    for(int x=0;x<s.length();x++){
        if(isdigit(s[x]))continue;
        //here, s[x] not a digit...
        ans=x;
        break;
    }
    for(int x=k-1;x>=0;x--){
        psums[x]=ans%10;
        ans/=10;
        sums[x]=0;
    }
    for(int x=0;x<s.length();x++){
        if(isdigit(s[x])){
            sums[x%k]+=s[x]-'0';
            sums[x%k]%=10;
        }
    }
    for(int x=0;x<k;x++){
        panses[k]=(20+psums[k]-sums[k])%10;
    }
    for(int x=ans;!isdigit(s[x]);x++){
        true_ans+=" ";
        true_ans[true_ans.length()-1]=panses[x%k]-'0';
    }
	return true_ans;
}