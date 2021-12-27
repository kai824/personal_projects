// guess.cpp 23 Feb 19, 16:07:53 17 0.06 Judging completed in 8.076s on AWS Oregon.
#include <bits/stdc++.h>
#include "guess.h"

using namespace std;

string guess(int n, int k, string s) {
    int total=0;
    for(int x=0;x<n;x++){
        if(s[x]>'9' || s[x]<'0')continue;
        total+=s[x]-'0';
    }
    total/=n-1;
    string ans=" ";
    ans[0]=total+'0';
    return ans;
}