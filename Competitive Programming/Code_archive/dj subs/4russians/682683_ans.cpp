// ans.cpp 19 Jan 20, 00:04:41 9 1 Judging completed in 5.441s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll c[5005],s[5005];

ll dp[5005][5005][2];//first one denotes whether you bomb the last bunker...

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
			dp[i][j][1]=max(max(dp[i-1][j][0],dp[i-1][j][1]),dp[i][j-1][0]);
			if(j==1)dp[i][j][1]-1e15;//to enforce that bomb must occur
			else dp[i][j][1]=dp[i][j-1][1];
			if(j>1){
				dp[i][j][1]=max(dp[i][j][1], s[i]+max(dp[i-1][j-1][0]-(c[i]*c[i-1])-(c[i]*c[i+1]), dp[1][i-1][j-1]-(c[i]*c[i+1])+(c[i]*c[i-1]) ) );
			}else{
				dp[i][j][1]=max(dp[i][j][1], s[i]+dp[i-1][j-1][0]-(c[i]*c[i-1])-(c[i]*c[i+1]));
			}
		}
		//cout<<'\n';
	}
	cout<<max(dp[n][k][0],dp[n][k][1]);
	return 0;
}