#include"bits/stdc++.h"
using namespace std;

#define int long long
#define mp make_pair
#define pii pair<int,int>

int parent[100005][18],depth[100005];
int arr[100005],nex=1,vis[100005];
vector<pii> v[100005];//it, value(kinda prefix summed)
vector<int> adjl[100005];

void dfs(int node,int prev=-1){
  if(prev==-1)depth[node]=0;
  else depth[node]=depth[prev]+1;
  parent[node][0]=prev;
  for(int x=1;x<18;x++){
    if(parent[node][x-1]==-1)parent[node][x]=-1;
    else parent[node][x]=parent[parent[node][x-1]][x-1];
  }
  vis[node]=nex;
  v[arr[node]].emplace_back(nex,v[arr[node]].back().second+1);
  nex++;
  for(int x=0;x<adjl[node].size();x++){
    if(adjl[node][x]==prev)continue;
    dfs(adjl[node][x],node);
  }
  v[arr[node]].emplace_back(nex,v[arr[node]].back().second-1);
  nex++;
}
int lca(int a,int b){
  if(depth[a]<depth[b])swap(a,b);
  for(int x=17;x>=0 && depth[a]>depth[b];x--){
    if(depth[a]-(1<<x)>=depth[b]){
      a=parent[a][x];
    }
  }
  if(a==b)return a;
  for(int x=17;x>=0;x--){
    if(parent[a][x]!=parent[b][x]){
      a=parent[a][x];b=parent[b][x];
    }
  }
  return parent[a][0];
}

int32_t main(){
  freopen("milkvisits.in", "r", stdin);
freopen("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,a,b,c,u;
    cin>>n>>q;
    for(int x=1;x<=n;x++){
      cin>>arr[x];
      v[x].emplace_back(0,0);
    }
    for(int x=1;x<n;x++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    dfs(1);
    while(q--){
      cin>>a>>b>>c;
      if(vis[a]>vis[b])swap(a,b);
      u=lca(a,b);
      if(arr[a]==c || arr[b]==c || arr[u]==c){
        cout<<'1';
        continue;
      }
      if( ((--upper_bound(v[c].begin(),v[c].end(),mp(vis[a],0ll)))) ->second != ((--upper_bound(v[c].begin(),v[c].end(),mp(vis[u],0ll))))->second){
        cout<<'1';
      }else if(((--upper_bound(v[c].begin(),v[c].end(),mp(vis[b],0ll))))->second != ((--upper_bound(v[c].begin(),v[c].end(),mp(vis[u],0ll))))->second){
        cout<<'1';
      }else cout<<'0';
    }
    /*cout<<'\n';
    for(int x=1;x<=n;x++){
      cout<<x<<": ";
      for(int i=0;i<v[x].size();i++){
        cout<<v[x][i].first<<' '<<v[x][i].second<<'\t';
      }cout<<'\n';
    }*/
    return 0;
}
/*

*/
