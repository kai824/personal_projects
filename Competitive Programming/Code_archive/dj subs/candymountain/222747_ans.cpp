// ans.cpp 16 Oct 17, 12:17:51 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,k,a;
    cin>>n>>k;
    ll dp[n+2],arr[n+2];
    dp[0]=0;
    for(ll x=1;x<=n;x++){
        cin>>arr[x];
    }
    arr[n+1]=0;
    for(ll x=1;x<(n+2);x++){
        dp[x]=x-1;
        for(int y=max(0,x-k);y<x;y++){
            dp[x]=min(dp[x],dp[y]);
        }
        dp[x]=max(dp[x],arr[x]);
    }
    cout<<dp[n+1];
    return 0;
}