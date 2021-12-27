// ans.cpp 21 Dec 19, 17:05:55 0 0.11 Judging completed in 3.631s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

vector<int> adjl[100005];
bool vis[100005];
int dist[100005],preorder[100005],rt[100005],parent[1000005];
int nex=1;

int dfs(int node){
	vis[node]=true;
	int cnt=1,a,cur=0,it=-1;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]==false){
			a=dfs(adjl[node][x]);
			cnt+=a;
			if(a>cur){
				cur=a;
				it=x;
			}
		}
	}
	if(it>0){
		swap(adjl[node][it],adjl[node][0]);
	}
	return cnt;
}
void dfs2(int node,int dd,int prev,int heavy_root=-1){
	if(heavy_root==-1)heavy_root=node;
	rt[node]=heavy_root;
	vis[node]=false;
	dist[node]=dd;parent[node]=prev;
	preorder[node]=nex;nex++;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]==true){
			if(x==0)dfs2(adjl[node][x],dd+1,node,heavy_root=heavy_root);//heavy edge...
			else dfs2(adjl[node][x],dd+1,node);//light edge...
		}
	}
}

int ft[100005];
inline int ls(int x){
	return x & (-x);
}
void update(int x,int v){
	for(;x<=100000;x+=ls(x))ft[x]+=v;
}
int query(int x){
	int ans=0;
	for(;x;x-=ls(x)){
		ans+=ft[x];
	}
	return ans;
}

void plant(int a,int b){
	while(rt[a]!=rt[b]){
		if(b==1 || dist[rt[a]]>dist[rt[b]])swap(a,b);
		update(preorder[rt[b]],1);
		update(preorder[b]+1,-1);
		b=parent[rt[b]];
	}
	if(dist[a]>dist[b])swap(a,b);
	update(preorder[a]+1,1);update(preorder[b]+1,-1);
}
int qry(int a,int b){
	if(dist[a]>dist[b])swap(a,b);
	return query(preorder[b]);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,b;
	char c;
	cin>>n>>m;
	for(int x=1;x<n;x++){
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	dfs(1);//choose which child is heavy...
	dfs2(1,1,1);
	for(int x=1;x<=n;x++){
		cout<<x<<' '<<parent[x]<<' '<<rt[x]<<' '<<preorder[x]<<'\n';
	}
	for(int x=0;x<m;x++){
		cin>>c>>a>>b;
		if(c=='P'){
			plant(a,b);
		}else{
			cout<<qry(a,b)<<'\n';
		}
	}
	return 0;
}