// ans.cpp 9 Oct 17, 09:38:21 100 0.17 Judging completed in 7.919s on AWS Oregon.
#include "peanutparty.h"
#include<bits/stdc++.h>
using namespace std;

int minStrawberries(int n, int l, int a[]) {
    int sum=0,ans=INT_MAX;
    for(int x=0;x<l;x++){
        sum+=a[x];
    }
    ans=min(ans,sum);
    for(int x=l;x<n;x++){
        sum+=a[x];
        sum-=a[x-l];
        ans=min(ans,sum);
    }
    return ans;
}