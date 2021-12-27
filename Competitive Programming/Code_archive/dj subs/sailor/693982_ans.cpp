// ans.cpp 3 Feb 20, 14:41:55 100 0.59 Judging completed in 5.8s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool vis[100005],not_leaf[100005];
int grp[100005],siz[100005],nex=1;
vector<int> adjl[100005],adjl_rev[100005];
vector<int> nodes;//discovery time...
void dfs(int node){
	vis[node]=true;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]])continue;
		dfs(adjl[node][x]);
	}
	nodes.push_back(node);
}
void dfs2(int node){
	grp[node]=nex;
	siz[nex]++;
	vis[node]=false;
	for(int x=0;x<adjl_rev[node].size();x++){
		if(vis[adjl_rev[node][x]]==false)continue;
		dfs2(adjl_rev[node][x]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,b,ans;
	cin>>n>>m;ans=n;
	for(int x=0;x<m;x++){
		cin>>a>>b;//if you hire a, must hire b...
		adjl[a].push_back(b);
		adjl_rev[b].push_back(a);
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==false){
			dfs(x);
		}
	}
	while(nodes.size()>0){
		if(vis[nodes.back()]==true){
			dfs2(nodes.back());
			nex++;
		}
		nodes.pop_back();
	}
	for(int x=1;x<=n;x++){
		if(not_leaf[grp[x]]==true)continue;
		for(int i=0;i<adjl[x].size();i++){
			if(grp[adjl[x][i]]!=grp[x]){//links to outside the group
				not_leaf[grp[x]]=true;
				break;
			}
		}
	}
	for(int x=1;x<nex;x++){
		if(not_leaf[x]==true)continue;
		ans=min(ans,siz[x]);
	}
	cout<<ans;
	return 0;
}
/*
5 6
1 2
2 4
4 3
3 2
5 1
5 4
*/