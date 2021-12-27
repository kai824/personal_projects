// ans.cpp 24 Nov 18, 11:13:33 50 1.01 Judging completed in 3.105s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll a,b,c,n,xx;
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
		dp[x]=INT_MIN;
		for(int y=0;y<x;y++){
			xx=ps[x]-ps[y];
			dp[x]=max(dp[x],dp[y]+(a*xx*xx)+(b*xx)+c);
		}
	}
	cout<<dp[n];
	return 0;
}