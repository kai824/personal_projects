// ans.cpp 24 Sep 17, 08:54:06 100 0.19 Judging completed in 5.083s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k,i=0,ans;
    cin>>n>>k;
    ll p1[n],p2[n],dp[n],dp2[n];
    for(ll x=0;x<n;x++){
        cin>>p1[x];
    }
    for(ll x=0;x<n;x++){
        cin>>p2[x];
    }
    dp[n-1]=p1[n-1];
    dp2[n-1]=p2[n-1];
    ans=max(ans,max(dp[n-1],dp2[n-1]));
    for(ll x=n-2;x>=0;x--){
        dp[x]=p1[x];
        dp[x]+=max(max(dp[x+1],dp2[x+1]-k),i);
        dp2[x]=p2[x];
        dp2[x]+=max(max(dp[x+1]-k,dp2[x+1]),i);
        dp[x]=max(dp[x],i);
        dp2[x]=max(dp2[x],i);
        ans=max(ans,max(dp[x],dp2[x]));
    }
    cout<<ans;
    return 0;
}