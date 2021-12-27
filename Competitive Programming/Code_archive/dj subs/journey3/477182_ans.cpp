// ans.cpp 14 Jan 19, 11:24:32 0 0.13 Judging completed in 4.383s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dp[10001][401];
//city no., no. of nights spent
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,h,j,k;
    cin>>n>>m>>h;
    dp[1][0]=1;
    for(int x=1;x<n;x++){
        for(int y=1;y<401;y++){
            dp[x][y]+=dp[x][y-1];//can spend extra nights...
            dp[x][y]=min(dp[x][y],500000000);
        }
        for(int y=0;y<h;y++){
            cin>>j>>k;
            for(int z=0;z<401;z++){
                dp[j][z+k]+=dp[j][z];
            }
        }
    }
    cout<<dp[n][0];
    for(int y=1;y<m;y++){
        dp[n][y]+=dp[n][y-1];
        dp[n][y]=min(dp[n][y],500000000);
        cout<<' '<<dp[n][y];
    }
    return 0;
}