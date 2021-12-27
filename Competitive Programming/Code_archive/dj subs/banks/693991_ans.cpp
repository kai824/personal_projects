// ans.cpp 3 Feb 20, 15:43:34 100 0.18 Judging completed in 4.111s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
bool vis[200005];
int ans[500005],cnt1[200005],cnt2[200005];
int grp[200005],nex=1;
vector<pair<int,int> > adjl[200005],adjl_rev[200005];
vector<int> nodes;//discovery time...
int dfs(int node,int to_update){
	int subtree_size=cnt1[node];
	vis[node]=true;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x].first])continue;
		subtree_size+=dfs(adjl[node][x].first,adjl[node][x].second);
	}
	nodes.push_back(node);
	if(to_update!=-1)ans[to_update]+=subtree_size;
	return subtree_size;
}
int dfs2(int node,int to_update){
	int subtree_size=cnt2[node];
	grp[node]=nex;
	vis[node]=false;
	for(int x=0;x<adjl_rev[node].size();x++){
		if(vis[adjl_rev[node][x].first]==false)continue;
		subtree_size+=dfs2(adjl_rev[node][x].first,adjl_rev[node][x].second);
	}
	if(to_update!=-1)ans[to_update]+=subtree_size;
	return subtree_size;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,b;
	cin>>n>>m;
	for(int x=0;x<m;x++){
		cin>>a>>b;//if you hire a, must hire b...
		cnt1[a]++;cnt2[b]++;
		adjl[a].push_back(make_pair(b,x));
		adjl_rev[b].push_back(make_pair(a,x));
		ans[x]=1;
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==false){
			dfs(x,-1);
		}
	}
	while(nodes.size()>0){
		if(vis[nodes.back()]==true){
			dfs2(nodes.back(),-1);
			nex++;
		}
		nodes.pop_back();
	}
	for(int x=1;x<=n;x++){
		for(int i=0;i<adjl[x].size();i++){
			if(grp[adjl[x][i].first]!=grp[x]){//links to outside the group
				cout<<"NO\n";
				return 0;
			}
		}
	}
	cout<<"YES\n";
	for(int x=0;x<m;x++){
		cout<<ans[x];
		if(x+1<m)cout<<' ';
	}
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