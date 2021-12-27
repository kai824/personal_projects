// ans.cpp 16 Oct 17, 12:26:18 0 0.06 Judging completed in 4.686s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,a;
    cin>>n>>k;
    int dp[n+2],arr[n+2];
    dp[0]=0;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
    }
    arr[n+1]=0;
    for(int x=1;x<(n+2);x++){
        dp[x]=x-1;
        for(int y=max(0,x-k+1);y<x;y++){
            dp[x]=min(dp[x],dp[y]);
        }
        dp[x]=max(dp[x],arr[x]);
    }
    cout<<dp[n+1];
    return 0;
}