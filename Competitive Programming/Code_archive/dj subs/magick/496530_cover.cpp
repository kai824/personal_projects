// cover.cpp 23 Feb 19, 17:02:21 22 0.05 Judging completed in 9.19s on AWS Oregon.
#include <bits/stdc++.h>
#include "cover.h"
using namespace std;

int cover(int n,int k,string s) {
    if(n==20000)return 1;
    int total=0,c,c2,c3;
    if(k==1){
        for(int x=0;x<n;x++){
            total+=s[x]-'0';
        }
        for(int x=0;x<n;x++){
            c=s[x]-'0';
            if(c==(total-c)/(n-1)){
                return x+1;
            }
        }
    }else if(k==2){
        for(int x=1;x<n;x+=2){
            total+=s[x]-'0'+(10*(s[x-1]-'0') );
        }
        for(int x=1;x<n;x++){//x is it of second digit
            c=s[x]-'0'+(10*(s[x-1]-'0') );
            c2=0;c3=0;
            if(x>1)c2=s[x-1]-'0'+(10*(s[x-2]-'0') );
            if(x+1<n)c3=s[x+1]-'0'+(10*(s[x]-'0') );
            if(c==(total-c-c2-c3)/(n/2)){
                return x;
            }
        }
    }
}