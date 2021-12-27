// ans.cpp 7 Mar 18, 22:30:12 100 0.18 Judging completed in 4.415s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005][1005],a[1005];
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    bool chec=1,chekk=0;
    cin>>n;
    for(int i=1;i<=n;++i){
      cin>>a[i];
      if(a[i]==0)chekk=1;
    }
    for(int i=0;i<=n;++i){
      for(int j=0;j<=n;++j){
        if(i>j)dp[i][j]=0;
        else dp[i][j]=INT_MAX;
      }
    }
    for(int s=1;s<=n;++s){
      for(int i=1;i<=n-s+1;++i){
        int l=i,r=i+s-1;
        int mini=1e9;
        for(int j=l+1;j<=r;++j){
          if(a[i]==a[j]){
            chec=0;
            mini=min(mini,dp[l+1][j-1]+dp[j][r]);
          }
        }
        dp[l][r]=min(mini,1+dp[l+1][r]);
      }
    }
    if(!chec||!chekk)cout<<dp[1][n];
    else cout<<n-1;
}