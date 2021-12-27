// ans.cpp 18 Jan 20, 13:37:14 100 1.13 Judging completed in 5.061s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c[5005],s[5005];

ll dp[2][5005][5005];//first one denotes whether you bomb the last bunker...

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k;
	cin>>n>>k;
	for(int x=1;x<=n;x++)cin>>c[x];
	for(int x=1;x<=n;x++){
		cin>>s[x];
	}
	
	for(int j=1;j<=k;j++){//the number of bunkers bombed...
		for(int i=1;i<=n;i++){//bomb the ith bunker...
			dp[0][i][j]=max(max(dp[0][i-1][j],dp[1][i-1][j]),dp[0][i][j-1]);
			if(j==1)dp[1][i][j]=-1e15;//to enforce that bomb must occur
			else dp[1][i][j]=dp[1][i][j-1];
			if(j>1){
				dp[1][i][j]=max(dp[1][i][j], s[i]+max(dp[0][i-1][j-1]-(c[i]*c[i-1])-(c[i]*c[i+1]), dp[1][i-1][j-1]-(c[i]*c[i+1])+(c[i]*c[i-1]) ) );
			}else{
				dp[1][i][j]=max(dp[1][i][j], s[i]+dp[0][i-1][j-1]-(c[i]*c[i-1])-(c[i]*c[i+1]));
			}
		}
		//cout<<'\n';
	}
	cout<<max(dp[0][n][k],dp[1][n][k]);
	return 0;
}