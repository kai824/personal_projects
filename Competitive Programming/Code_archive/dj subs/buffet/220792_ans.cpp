// ans.cpp 24 Sep 17, 08:45:48 0 0.75 Judging completed in 5.908s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n,k;
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
    for(ll x=n-2;x>=0;x--){
        dp[x]=p1[x];
        dp[x]+=max(p1[x+1],p2[x+1]-k);
        dp2[x]=p2[x];
        dp2[x]+=max(p1[x+1]-k,p2[x+1]);
    }
    cout<<max(dp[0],dp2[0]);
    return 0;
}