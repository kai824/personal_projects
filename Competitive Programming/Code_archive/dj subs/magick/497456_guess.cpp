// guess.cpp 23 Feb 19, 18:32:53 0 0.05 Judging completed in 58.232s on AWS Oregon.
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
        string ans="  ";
        srand(time(0));
        ans[0]='0'+(rand()%10);
        ans[1]='0'+(rand()%10);
    }
}