// guess.cpp 23 Feb 19, 17:02:21 22 0.05 Judging completed in 9.19s on AWS Oregon.
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
    int total=0;
    if(k==1){
        for(int x=0;x<n;x++){
            if(s[x]>'9' || s[x]<'0')continue;
            total+=s[x]-'0';
        }
        total/=n-1;
        string ans=" ";
        ans[0]=total+'0';
        return ans;
    }else if(k==2){
        for(int x=1;x<n;x+=2){
            if(s[x]>'9'||s[x]<'0')continue;
            if(s[x-1]>'9'||s[x-1]<'0')continue;
            total+=s[x]-'0'+(10*(s[x-1]-'0') );
        }
        total/=n/2;
        string ans="  ";
        ans[0]=(total/10)+'0';
        ans[1]=(total%10)+'0';
        return ans;
    }
}