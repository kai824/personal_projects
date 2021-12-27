// examhalls.cpp 7 Nov 19, 17:05:22 100 0.01 Judging completed in 6.831s on AWS Oregon.
#include "examhalls.h"
#include<bits/stdc++.h>
using namespace std;

long long examhalls(int n, int a[]) {
    long long sum=0,maxi=-1;
    for(int x=0;x<n;x++){
        sum+=a[x];
        maxi=max(maxi,(long long)a[x]);
    }
    bool pos[50005];
    for(int x=0;x<50005;x++){pos[x]=false;}
    pos[0]=true;
    for(int x=0;x<n;x++){
        for(long long y=sum-sum/2;y>=a[x];y--){
            pos[y]|=pos[y-a[x]];
            if(pos[y])maxi=max(maxi,y);
        }
    }
    long long ans=maxi*maxi;
    ans+=(sum-maxi)*(sum-maxi);
    return ans;
}