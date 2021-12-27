// ans.cpp 10 Jan 20, 12:17:44 15 0.14 Judging completed in 5.37s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

bool vis[200005];
vector<int> adjl[200005];
int  depth[200005],ans=1;

int dfs(int node,int prev,int d){//returns the shallowest backedge...
	depth[node]=d;
	vis[node]=true;
	int shallow=d,cnt=0;//shallowest backedge...
	for(int x=0;x<adjl[node].size();x++){
		if(prev==adjl[node][x])continue;//parent, ignore
		if(vis[adjl[node][x]]){//may have found a back edge
		    cnt++;
			continue;
		}
		shallow=min(shallow,dfs(adjl[node][x],node,d+1));
	}
	if(shallow>=d){//backedge from children doesn't exist!!!
	    //(it's an articulation point!)
		if(ans<adjl[node].size()-cnt){
		    ans=adjl[node].size()-cnt;
		}
	}
	for(int x=0;x<adjl[node].size();x++){
		if(prev==adjl[node][x])continue;
	    shallow=min(shallow,depth[ adjl[node][x] ]);
	}
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