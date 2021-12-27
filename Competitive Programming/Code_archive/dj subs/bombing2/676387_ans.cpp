// ans.cpp 10 Jan 20, 13:35:17 15 0.15 Judging completed in 5.426s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

bool vis[200005];
vector<int> adjl[200005];
int  depth[200005],ans=1,root;

int dfs(int node,int prev,int d){//returns the shallowest backedge...
	depth[node]=d;
	vis[node]=true;
	int shallow=INT_MAX,cnt=0;//shallowest backedge...
	for(int x=0;x<adjl[node].size();x++){
		if(prev==adjl[node][x])continue;//parent, ignore
		if(vis[adjl[node][x]]){//may have found a back edge
			continue;
		}
		shallow=min(shallow,dfs(adjl[node][x],node,d+1));
		cnt++;
	}
	if(cnt>0 && shallow>=d){//backedge from children doesn't exist!!!
	    //(it's an articulation point!)
		//since cnt is the number of nodes dfsed
		if(node!=root)cnt++;//the parent...
		ans=max(ans,cnt);
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
		a++;b++;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	root=1;
	dfs(root,-1,1);
	cout<<ans;
	return 0;
}