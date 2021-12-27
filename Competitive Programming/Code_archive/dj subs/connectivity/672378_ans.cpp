// ans.cpp 3 Jan 20, 18:39:25 100 0.1 Judging completed in 4.083s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int parent[200005];//ufds for the roads...
int siz[200005];

int getr(int x){
    if(parent[x]==-1)return x;
    parent[x]=getr(parent[x]);
    return parent[x];
}
inline void merge(int a,int b){
    a=getr(a);b=getr(b);
    if(a==b)return;
    parent[a]=b;
    siz[b]+=siz[a];//since b is the new root
    siz[a]=0;
}

vector<int> adjl[200005];
bool vis[200005];
int ans[200005];
int cnt[200005];//count number of nodes with same ufds root

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k,l,a,b;
	cin>>n>>k>>l;
	for(int x=1;x<=n;x++){
		parent[x]=-1;
	}
	for(int x=0;x<k;x++){
		cin>>a>>b;
		merge(a,b);
	}
	for(int x=0;x<l;x++){
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	queue<int> bfs;
	vector<int> v,v2;
	for(int x=1;x<=n;x++){
		if(!vis[x]){
			vis[x]=true;
			v2.push_back(x);
			cnt[getr(x)]=1;
			v.push_back(getr(x));
			bfs.push(x);
			while(!bfs.empty()){
				a=bfs.front();
				for(int i=0;i<adjl[a].size();i++){
					if(vis[adjl[a][i]]==false){
						vis[adjl[a][i]]=true;
						bfs.push(adjl[a][i]);
						v2.push_back(adjl[a][i]);
						b=getr(adjl[a][i]);
						if(cnt[b]==0)v.push_back(b);
						cnt[b]++;
					}
				}
				bfs.pop();
			}
			/*for(int i=0;i<v2.size();i++){
				ans[v2[i]]+=cnt[getr(v2[i])]-1;
			}*/
			while(v2.size()>0){
				ans[v2.back()]+=cnt[getr(v2.back())]-1;
				v2.pop_back();
			}
			while(v.size()>0){
				cnt[v.back()]=0;
				v.pop_back();
			}
		}
	}
	for(int x=1;x<=n;x++){
		cout<<ans[x]+1;
		if(x<n)cout<<' ';
	}
    return 0;
}