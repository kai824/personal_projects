#include<bits/stdc++.h>
using namespace std;

#define lnt long long
const lnt inf=1e17;
typedef pair<lnt,lnt> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back

vector<pii> adjl[200005],adj[200005];
bool vis[200005],tvis[200005];
bool inq[200005];//so we don't push redundant things into bfs...

vector<pii> ha[200005];

int n;
deque<int> bfs;

void hehe(int t){
	for(pii x:ha[t]){
		adj[x.f].eb(x.s,t);
		adj[x.s].eb(x.f,t);
		if(vis[x.f]!=vis[x.s]){
			if(vis[x.f]){
				if(!inq[x.f])bfs.push_back(x.f);
				inq[x.f]=true;
			}else if(!inq[x.s]){
				bfs.push_back(x.s);
				inq[x.s]=true;
			}
		}
	}
}

vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c) {
	n=r.size();
	int m=u.size();
	for(int i=0;i<m;i++){
		ha[c[i]].eb(u[i],v[i]);
		// adjl[u[i]].eb(v[i],c[i]);
		// adjl[v[i]].eb(u[i],c[i]);
	}
	vector<int> ans;ans.resize(n);
	int mn=INT_MAX;

	for(int i=0;i<n;i++){
		int cnt=1;
		for(int j=0;j<n;j++)vis[j]=tvis[j]=inq[j]=false;
		for(int j=0;j<n;j++)adj[j].clear();
		vis[i]=true;//starting node mah...
		tvis[r[i]]=true;
		hehe(r[i]);

		while(bfs.size()>0){
			int j=bfs.front();bfs.pop_front();
			for(int k=0;k<adj[j].size();k++){
				pii x=adj[j][k];
				if(vis[x.f])continue;

				vis[x.f]=true;bfs.push_back(x.f);
				if(tvis[r[x.f]]==false)hehe(r[x.f]);
				tvis[r[x.f]]=true;
				cnt++;
				if(cnt>mn){
					bfs.clear();goto hell;
				}
			}
			inq[j]=false;
			adj[j].clear();
		}
		hell:;
		ans[i]=cnt;
		mn=min(mn,ans[i]);
	}

	for(int i=0;i<n;i++){
		ans[i]=(mn==ans[i]);
	}
	return ans;
}
