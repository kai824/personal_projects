// ans.cpp 7 Mar 20, 10:42:58 40 0.68 Judging completed in 4.552s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

bool vis[50005];

int parent[50005][17],depth[50005];

vector<int> adjl[50005];
vector<int> b_nodes;//nodes with back edges...

void dfs(int node,int prev=-1){
	if(prev==-1)depth[node]=1;
	else depth[node]=depth[prev]+1;
	//cout<<node<<' '<<depth[node]<<'\n';

	parent[node][0]=prev;
	for(int x=1;x<17;x++){
		if(parent[node][x-1]==-1)parent[node][x]=-1;
		else parent[node][x]= parent[ parent[node][x-1] ][x-1];
	}
	bool back=false;
	vis[node]=true;
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x]==prev)continue;
		if(vis[adjl[node][x]]){
			back=true;
			continue;
		}
		dfs(adjl[node][x],node);
	}
	if(back){
		b_nodes.push_back(node);
	}
}

int lca(int a,int b){
	if(a==b)return a;
	if(depth[a]<depth[b])swap(a,b);
	for(int x=16;x>=0;x--){
		if(depth[a]-(1<<x)>=depth[b]){
			a=parent[a][x];
		}
	}
	if(a==b)return a;
	for(int x=16;x>=0;x--){
		if(parent[a][x]!=parent[b][x]){
			a=parent[a][x];
			b=parent[b][x];
		}
	}
	return parent[a][0];
}

inline int get_dist(int a,int b){
	return depth[a]+depth[b]-(2*depth[lca(a,b)]);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int tc,a,b,ans=0;
		bool esc;
		cin>>tc;

		int n,m,r,s;
		while(tc--){
			cin>>n>>m>>r>>s;
			for(int x=1;x<=n;x++){
				vis[x]=false;depth[x]=-1;
				adjl[x].clear();
			}
			for(int x=0;x<m;x++){//edges...
				cin>>a>>b;
				adjl[a].push_back(b);
				adjl[b].push_back(a);
			}

			b_nodes.clear();
			dfs(r);
			esc=false;

			for(int x=0;x<b_nodes.size();x++){
				a=get_dist(r,b_nodes[x]);
				b=get_dist(s,b_nodes[x]);//see who will reach there first...
				if(b<a){//b will reach the cycle first...
					esc=true;
					break;
				}
			}

			if(esc){
				cout<<"sportaflop\n";
			}else{
				ans=0;
				for(int x=1;x<=n;x++){
					a=get_dist(r,x);
					b=get_dist(s,x);
					if(b<a){//b will reach the node first...
						ans=max(ans,a);
					}
				}
				cout<<ans<<'\n';
			}
		}
    return 0;
}