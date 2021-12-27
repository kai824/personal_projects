// ans.cpp 11 Jan 18, 09:56:01 100 0.04 Judging completed in 3.755s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    long long n,k,i,i1,i2,x;
    cin>>n>>k;
    long long val[k],cost[k];//dp stores min value, no stores number of ads
	long long zero=0;
	for (i=0;i<k;i++){
		cin>>val[i]>>cost[i];
	}
	pair<long long,long long>dp[n];
	i=0;
	for (i1=0;i1<=n;i1++){
		dp[i1] = {INT_MAX,0};
	}
	dp[0]={0,0};
	
	for (i1=0;i1<=n;i1++){
		dp[i1] = min(dp[i1], {dp[max(i1 - val[i], zero)].first + cost[i], dp[max(i1 - val[i], zero)].second + 1});
	}
	for (i=1;i<k;i++){
		for (i1=0;i1<=n;i1++){
			dp[i1] = min(dp[i1], {dp[max(i1 - val[i], zero)].first + cost[i], dp[max(i1 - val[i], zero)].second + 1});
			//cout<<dp[i].first<<" "<<dp[i].second<<'\n';
		}
		//cout<<'\n';
	}
	//for (i=0;i<=n;i++){
	//	cout<<dp[i].first<<" "<<dp[i].second<<'\n';
	//}
	if (dp[n].first>=INT_MAX){
		cout<<"Mr Beancurd is doomed!!!\n";
	}
	else cout<<dp[n].first<<' '<<dp[n].second<<'\n';
    
}