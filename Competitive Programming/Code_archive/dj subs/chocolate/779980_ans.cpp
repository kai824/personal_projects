// ans.cpp 9 Nov 20, 16:25:42 100 0.25 Judging completed in 6.154s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int dp[2][5005][2],arr[10001];
//dp[cur_pos][amt_taken][taking?]

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,nex;
    cin>>n;
    for(int x=1;x<n;x++){
        cin>>arr[x];
    }
    for(int j=0;j<=(n/2);j++){
        dp[1][j][0]=dp[1][j][1]=INT_MAX;//not possible...
    }
    dp[1][0][0]=dp[1][1][1]=0;
    for(int i=1;i<=n;i++){//amt of chocolate given out...
        nex=1-(i%2);
        cerr<<"oi"<<nex;
        for(int j=0;j<=(n/2);j++){
            dp[nex][j][0]=dp[nex][j][1]=INT_MAX;//not possible...
        }
        for(int j=0;j<=(n/2);j++){
            for(int k=0;k<2;k++){
                if(dp[i%2][j][k]==INT_MAX)continue;
                if(k==0){
                    dp[nex][j+1][1]=min(dp[nex][j+1][1],dp[i%2][j][k]+arr[i]);//break chocolate
                    dp[nex][j][0]=min(dp[nex][j][0],dp[i%2][j][k]);//continue not taking
                }else{
                    dp[nex][j][0]=min(dp[nex][j][0],dp[i%2][j][k]+arr[i]);//break...
                    dp[nex][j+1][1]=min(dp[nex][j+1][1],dp[i%2][j][k]);
                }
            }
        }
    }
    cout<<min(dp[n%2][n/2][0],dp[n%2][n/2][1]);
    return 0;
}