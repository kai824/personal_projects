#include "wiring.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second

#ifdef local
#define deb(x) cerr<<x<<'\n';
#define debl(label,x) cerr<<label<<": "<<x<<'\n';
#else
#define deb(x) ;
#define debl(label,x) ;
#endif

ll min_total_length(vector<int> r,vector<int> b){//r and b are sorted
	const int s1=r.size()+1,s2=b.size()+1;
	ll dp[s1][s2];
	for(int i=0;i<s1;i++){
		for(int j=0;j<s2;j++){
			dp[i][j]=1e18;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<s1;i++){
		for(int j=1;j<s2;j++){
			dp[i][j]=abs(r[i-1]-b[j-1])+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]) );
		}
	}
	return dp[s1-1][s2-1];
}
