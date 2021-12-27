// ans.cpp 14 Dec 19, 12:12:35 10 0.01 Judging completed in 3.724s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
static ll mod=1e9+7;
ll ans=1;
ll n,k,a;

bool vis[1000005],cur[1000005];
vector<int> adjl[1000005];

void dfs(int node){
	vis[node]=true;cur[node]=true;
	int cnt=0;
	bool cross=false;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]){
			cnt++;continue;
		}
		dfs(adjl[node][x]);
	}
	ans*=(k-cnt);
	ans%=mod;
	cur[node]=false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;
	if(n>k){
	    cout<<0;return 0;
	}
	for(int x=1;x<=n;x++){
		cin>>a;
		adjl[a].push_back(x);
		adjl[x].push_back(a);
	}
	for(int x=1;x<=n;x++){
		sort(adjl[x].begin(),adjl[x].end());
		a=unique(adjl[x].begin(),adjl[x].end())-adjl[x].begin();
		while(adjl[x].size()>a){
			adjl[x].pop_back();
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}