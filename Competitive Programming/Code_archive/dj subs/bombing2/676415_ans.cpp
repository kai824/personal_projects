// ans.cpp 10 Jan 20, 14:06:22 15 0.16 Judging completed in 6.17s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

bool vis[200005];
vector<int> adjl[200005];
int  depth[200005],ans=1,root,d=1;

int dfs(int node,int prev){//returns the shallowest backedge...
	depth[node]=d;
	d++;
	vis[node]=true;
	int shallow=INT_MAX,cnt=0;//shallowest backedge...
	for(int x=0;x<adjl[node].size();x++){
		if(prev==adjl[node][x])continue;//parent, ignore
		if(vis[adjl[node][x]]){//may have found a back edge
			continue;
		}
		shallow=min(shallow,dfs(adjl[node][x],node));
		cnt++;
	}
	if(shallow>=depth[node]){//backedge from children doesn't exist!!!
	    //(it's an articulation point!)
		//since cnt is the number of nodes dfsed
		if(node==root)ans=max(ans,cnt);
		else ans=max(ans,cnt+1);//'cause you still have the parent to count...
	}
	for(int x=0;x<adjl[node].size();x++){
		if(prev==adjl[node][x])continue;
	    if(vis[adjl[node][x]]){
	        shallow=min(shallow,depth[ adjl[node][x] ]);
	    }
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
	root=0;
	dfs(root,-1);
	cout<<ans;
	return 0;
}