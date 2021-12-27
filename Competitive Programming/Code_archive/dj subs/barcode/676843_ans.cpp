// ans.cpp 10 Jan 20, 22:01:22 0 0.01 Judging completed in 4.301s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int ps[100005],ps2[100005];//counts 1s, counts 0s
int dp[100005];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,a,b;
	string s;
	cin>>n>>a>>b>>s;
	for(int x=0;x<s.length();x++){
		ps[x+1]=ps[x];
		ps2[x+1]=ps2[x];
		if(s[x]=='1')ps[x+1]++;
		else ps2[x+1]++;
	}
	a=max(a,1);
	if(b==0){
	    assert(false);
		cout<<ps[s.length()];//no tolerance for 1s...
		return 0;
	}

	priority_queue<pii,vector<pii>, greater<pii> > pq,pq2;
	//for finding min dp[j]-ps[j], dp[j]-ps2[j], with the iterator...
	for(int x=1;x<=s.length();x++){
	    dp[x]=ps[x];
	    if(s[x-1]=='0'){
	        dp[x]=min(dp[x],dp[x-1]);
	    }
		if(x>=a){
			pq.push(make_pair(dp[x-a]-ps[x-a],x-a));
			pq2.push(make_pair(dp[x-a]-ps2[x-a],x-a));

			while(pq.top().second<x-b){//check if range can end there...
				pq.pop();
			}
			dp[x]=min(dp[x],ps[x]+pq.top().first);
			while(pq2.top().second<x-b){
				pq2.pop();
			}
			dp[x]=min(dp[x],ps2[x]+pq2.top().first);
		}
		//cout<<dp[x]<<' ';
	}
	//ranges of 1 at least length a, up to b
	cout<<dp[s.length()];
	return 0;
}