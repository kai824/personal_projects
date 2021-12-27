// ans.cpp 22 Jul 20, 17:54:56 100 0.12 Judging completed in 4.093s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

vector<int> adjl[100005];
bool vis[100005];
int dist[100005],preorder[100005],rt[100005],parent[100005];
int nex=1;

int dfs(int node,int prev=-1){
  rt[node]=node;//unless u have a heavy path up
  parent[node]=prev;
  int cur=1,maxi=0,max_it=-1,a;
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    a=dfs(adjl[node][i],node);
    cur+=a;
    if(a>maxi){
      a=maxi;
      max_it=i;
    }
  }
  if(max_it!=-1 && max_it!=0){
    swap(adjl[node][max_it],adjl[node][0]);//for preorder
  }
  if(max_it!=-1)rt[adjl[node][0]]=node;
	return cur;
}
void dfs2(int node,int dd,int prev=-1){//do the preorder
  preorder[node]=nex++;//post-increment
  rt[node]=rt[rt[node]];//if had heavy path up, gfy
  dist[node]=dd;
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    dfs2(adjl[node][i],dd+1,node);
  }
}

int ft[100005];//rupq here
inline int ls(int x){
	return x & (-x);
}
void update(int x,int v){
	for(;x<=100002;x+=ls(x))ft[x]+=v;
}
int query(int x){
	int ans=0;
	for(;x;x-=ls(x)){
		ans+=ft[x];
	}
	return ans;
}

void plant(int a,int b){//update from path of a to b...
  if(dist[rt[a]]<dist[rt[b]])swap(a,b);//always ensure dist[rt[a]]>dist[rt[b]]
  while(rt[a]!=rt[b]){
    if(a==-1){
      //cerr<<"GGWP a is -1";
      assert(false);
    }
    if(dist[rt[a]]<dist[rt[b]])swap(a,b);//always ensure dist[rt[a]]>dist[rt[b]]
    update(preorder[rt[a]],1);
    update(preorder[a]+1,-1);
    //cerr<<"update from"<<' '<<preorder[rt[a]]<<" to "<<preorder[a]<<'\n';
    a=parent[rt[a]];
  }
  if(dist[a]>dist[b])swap(a,b);
  update(preorder[a]+1,1);//cos supposed to be on the edge...
  update(preorder[b]+1,-1);
  //cerr<<"update from"<<' '<<preorder[a]+1<<" to "<<preorder[b]<<'\n';
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
	dfs2(1,1);
  for(int x=1;x<=n;x++){
    //cout<<x<<' '<<preorder[x]<<' '<<rt[x]<<' '<<parent[x]<<'\n';
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