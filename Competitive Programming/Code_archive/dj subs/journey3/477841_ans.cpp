// ans.cpp 15 Jan 19, 21:44:18 43 0.08 Judging completed in 2.321s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dp[10001][401];
//city no., no. of nights spent
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,h,j,k;
    cin>>n>>m>>h;
    dp[0][0]=1;
    for(int x=0;x<n-1;x++){
        if(x>0){//cout<<dp[x][0];
        for(int y=1;y<m;y++){
            dp[x][y]+=dp[x][y-1];//can spend extra nights...
            dp[x][y]=min(dp[x][y],500000001);
            //cout<<' '<<dp[x][y];
        }}//cout<<'\n';
        for(int y=0;y<h;y++){
            cin>>j>>k;
            if(j<=x)continue;
            for(int z=0;z<401;z++){
                dp[j][z+k]+=dp[x][z];
            }
        }
    }
    cout<<dp[n-1][0];
    for(int y=1;y<m;y++){
        dp[n-1][y]+=dp[n-1][y-1];
        dp[n-1][y]=min(dp[n-1][y],500000001);
        cout<<' '<<dp[n-1][y];
    }
    return 0;
}