#include "train.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>
#define mp make_pair
#define f first
#define s second

#ifdef local
#define deb(x) cerr<<x<<'\n';
#define debl(label,x) cerr<<label<<": "<<x<<'\n';
#else
#define deb(x) ;
#define debl(label,x) ;
#endif

vector<int> adjl[5005],adj[5005];

vector<int> st;
int lo[5005],mm[5005],cur,n;
int scc[5005],nex;
bool mk[5005],vis[5005];
int ch[5005];//no. of unprocessed children
void dfs(int nd,int prev=-1){
	debl("DFSing",nd)
	vis[nd]=true;
	lo[nd]=mm[nd]=cur++;
	st.push_back(nd);
	for(int x:adjl[nd]){
		if(vis[x]){//if scc is not labelled 0, can be diff tree
			if(scc[x]==0)mm[nd]=min(mm[nd],lo[x]);
			continue;
		}else if(x==prev){
			assert(0);
		}
		dfs(x,nd);
		mm[nd]=min(mm[nd],mm[x]);
	}
	if(mm[nd]<lo[nd])return;//part of higher thing
	while(st.size()>0 && st.back()!=nd){
		scc[st.back()]=nex;
		st.pop_back();
	}
	mk[nex]=false;
	scc[st.back()]=nex++;st.pop_back();
}

bool dfs2(int x,int prev=-1){
	if(mk[x])return true;
	for(int i:adj[x]){
		if(i==prev)continue;
		if(dfs2(i,x))return true;
	}
	return false;
}

vector<int> who_wins(vector<int> a, vector<int> r, vector<int> u, vector<int> v) {
	vector<int> ans;
	n=a.size();
	for(int i=0;i<n;i++)scc[i]=0;
	for(int i=0;i<u.size();i++)adjl[u[i]].push_back(v[i]);
	cur=nex=1;
	for(int i=0;i<n;i++){
		if(vis[i]==false)dfs(i);//find SCCs
		deb("--------------------")
	}
	//for st3:
	for(int i=0;i<n;i++){
		if(r[i]==1)mk[scc[i]]=true;
	}
	/*
	//for st4:
	for(int i=1;i<nex;i++)mk[i]=false;
	for(int i=0;i<n;i++){
		if(r[i]==0)mk[scc[i]]=true;
	}
	*/
	for(int i=0;i<u.size();i++){
		if(scc[u[i]]==scc[v[i]])continue;
		adj[scc[u[i]]].push_back(scc[v[i]]);
	}
	for(int i=1;i<nex;i++){
		sort(adj[i].begin(),adj[i].end());
		adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
	}
	for(int i=0;i<n;i++){
		ans.push_back(dfs2(scc[i]));
	}
	return ans;
}
