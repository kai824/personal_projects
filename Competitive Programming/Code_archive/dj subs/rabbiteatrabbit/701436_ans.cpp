// ans.cpp 17 Feb 20, 16:19:19 100 0.37 Judging completed in 3.901s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[4005][4005][2];
ll arr[4005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,k,ans=0;
    cin>>n>>k;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
    }
    for(int x=1;x<=k;x++){
        for(int y=1;y<n;y++){
            dp[x][y][0]=max(dp[x-1][y][0],max(dp[x][y-1][0],dp[x][y-1][1]));
            dp[x][y][1]=max(dp[x][y][0],max(dp[x-1][max(0,y-2)][1],dp[x-1][y-1][0])+arr[y]);
            ans=max(ans,dp[x][y][1]);
        }
    }
    for(int x=0;x<=k;x++){
        for(int y=0;y<n;y++){
            dp[x][y][0]=dp[x][y][1]=0;
        }
    }
    for(int x=1;x<=k;x++){
        for(int y=1;y<n;y++){
            dp[x][y][0]=max(dp[x-1][y][0],max(dp[x][y-1][0],dp[x][y-1][1]));
            dp[x][y][1]=max(dp[x][y][0],max(dp[x-1][max(0,y-2)][1],dp[x-1][y-1][0])+arr[y+1]);
            ans=max(ans,dp[x][y][1]);
        }
    }
    cout<<ans;
    return 0;
}