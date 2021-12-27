// cover.cpp 23 Feb 19, 16:07:53 17 0.06 Judging completed in 8.076s on AWS Oregon.
#include <bits/stdc++.h>
#include "cover.h"
using namespace std;

int cover(int n,int k,string s) {
    int total=0,c;
    for(int x=0;x<n;x++){
        total+=s[x]-'0';
    }
    for(int x=0;x<n;x++){
        c=s[x]-'0';
        if(c==(total-c)/(n-1)){
            return x+1;
        }
    }
}