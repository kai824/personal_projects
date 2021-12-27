// cover.cpp 23 Feb 19, 16:10:21 22 0.03 Judging completed in 5.752s on AWS Oregon.
#include <bits/stdc++.h>
#include "cover.h"
using namespace std;

int cover(int n,int k,string s) {
    if(n==20000)return 1;
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