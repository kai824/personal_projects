// guess.cpp 24 Feb 19, 22:05:20 5 0.04 Judging completed in 6.304s on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int n, int k, string s) {
    if(n==20000){
        string ans="";
        for(int x=0;x<k;x++){
            ans+=s[n-1];
        }
        return ans;
    }
    int total=0,modded=0;
    if(k==1){
        for(int x=0;x<n;x++){
            if(s[x]=='?'){
                modded=x;
            }else{
                total+=s[x]-'0';
                total%=10;
            }
        }
        total+=10;
        total-=modded;
        total%=10;
        string ans=" ";
        ans[0]=total+'0';
        return ans;
    }
}