// ans.cpp 4 Feb 20, 12:11:33 100 0.15 Judging completed in 5.749s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

bool vis[200005];
vector<int> adjl[200005];
int  depth[200005],ans;

int dfs(int node,int prev,int d){//returns the shallowest backedge...
	depth[node]=d;
	vis[node]=true;
	int shallow=d,cnt=1,tmp;//shallowest backedge...
	if(prev==-1)cnt=0;
	for(int x=0;x<adjl[node].size();x++){
		if(prev==adjl[node][x])continue;//parent, ignore
		if(vis[adjl[node][x]]){//may have found a back edge
			shallow=min(shallow,depth[ adjl[node][x] ]);
			continue;
		}
		tmp=dfs(adjl[node][x],node,d+1);
		shallow=min(shallow,tmp);
		if(tmp>=d){
		    cnt++;
		}
	}
	ans=max(ans,cnt);
	return shallow;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,e,a,b;
	cin>>n>>e;
	for(int x=0;x<e;x++){
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	dfs(0,-1,1);
	cout<<ans;
	return 0;
}