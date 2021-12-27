// ans.cpp 9 Nov 20, 16:12:22 0 0 Judging completed in 6.17s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int dp[10002][5002][2],arr[10001];
//dp[cur_pos][amt_taken][taking?]

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    for(int x=1;x<n;x++){
        cin>>arr[x];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=(n/2);j++){
            dp[i][j][0]=dp[i][j][1]=INT_MAX;//not possible...
        }
    }
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=1;i<=n;i++){//amt of chocolate given out...
        for(int j=0;j<=(n/2);j++){
            for(int k=0;k<2;k++){
                if(dp[i][j][k]==INT_MAX)continue;
                if(k==0){
                    dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][k]+arr[i]);//break chocolate
                    dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][k]);//continue not taking
                }else{
                    dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][k]+arr[i]);//break...
                    dp[i+1][j+1][1]=min(dp[i+1][j+1][1],dp[i][j][k]);
                }
            }
        }
    }
    cout<<min(dp[n][n/2][0],dp[n][n/2][1]);
    return 0;
}