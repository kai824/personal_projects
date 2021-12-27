// ans.cpp 25 Jan 20, 17:50:34 100 0.31 Judging completed in 4.891s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int ans[300005];
int parent[300005],depth[300005],upd[300005];
bool impt[300005];
pair<int,int> el[300005];
vector<int> adjl[300005];

void dfs(int node,int prev,int dep){
	parent[node]=prev;
	depth[node]=dep;
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x]==prev)continue;
		dfs(adjl[node][x],node,dep+1);
	}
}

int root[300005];
int getr(int x){
	if(root[x]==-1)return x;
	root[x]=getr(root[x]);
	return root[x];
}
inline void merge(int a,int b){
	a=getr(a);b=getr(b);
	if(a==b)return;
	if(depth[a]<depth[b])swap(a,b);//make sure a is deeper..
	root[a]=b;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,b,nex=1;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		root[x]=-1;
	}
	for(int x=1;x<=m;x++){
		cin>>el[x].first>>el[x].second;
	}
	for(int x=1;x<n;x++){
		cin>>a;
		impt[a]=true;
		adjl[el[a].first].push_back(el[a].second);
		adjl[el[a].second].push_back(el[a].first);
	}
	dfs(1,-1,0);
	for(int x=1;x<=m;x++){
		if(impt[x]){
			if(depth[el[x].first]>depth[el[x].second]){
				upd[el[x].first]=x;
			}else upd[el[x].second]=x;
		}
	}
	vector<int> v;
	for(int x=1;x<=m;x++){
		if(ans[x]>0)continue;//assigned an answer already...
		if(impt[x]){
			merge(el[x].first,el[x].second);
			ans[x]=nex;nex++;
		}else{
			if(getr(el[x].first)==getr(el[x].second)){
				ans[x]=nex;nex++;
				continue;
			}
			a=getr(el[x].first);b=getr(el[x].second);
			v.clear();
			while(a!=b){
				if(depth[a]<depth[b])swap(a,b);//ensure a is deeper...
				v.push_back(upd[a]);
				merge(a,parent[a]);
				a=getr(parent[a]);
			}
			if(v.size()>0){
				sort(v.begin(),v.end());
				for(int i=0;i<v.size();i++){
					ans[v[i]]=nex;
					nex++;
				}
			}
			ans[x]=nex;nex++;
		}
	}
	for(int x=1;x<=m;x++){
		cout<<ans[x];
		if(x<m)cout<<' ';
	}
	return 0;
}