// ans.cpp 24 Nov 18, 11:11:05 40 1.01 Judging completed in 3.083s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll a,b,c,n,ans=0,xx;
	cin>>n>>a>>b>>c;
	ll arr[n+1],ps[n+1],dp[n+1];
	ps[0]=0;dp[0]=0;
	for(int x=1;x<=n;x++){
		cin>>arr[x];
	}
	for(int x=1;x<=n;x++){
		ps[x]=ps[x-1]+arr[x];
	}
	for(int x=1;x<=n;x++){
		dp[x]=0;
		for(int y=0;y<x;y++){
			xx=ps[x]-ps[y];
			dp[x]=max(dp[x],dp[y]+(a*xx*xx)+(b*xx)+c);
		}
		ans=max(ans,dp[x]);
	}
	cout<<ans;
	return 0;
}