// ans.cpp 29 Feb 20, 12:54:05 0 0.64 Judging completed in 4.471s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define mp make_pair
#define int long long//learning from chur zhe
#define pii pair<int,int>
int l[3005],r[3005],v[3005];

int dist[3010];
vector<pii> adjl[3010];

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,a;
  cin>>n>>m;
  for(int x=1;x<=n;x++){
    cin>>l[x]>>r[x]>>v[x];
  }
  for(int x=1;x<=n+1;x++){
    dist[x]=1e15;
  }dist[0]=0;
  vector<pair<int,pii> > edges;
  for(int x=1;x<=n;x++){
    if(l[x]<=1)edges.emplace_back(v[x],mp(0,x));
    if(r[x]>=m)edges.emplace_back(v[x],mp(n+1,x));
  }
  for(int x=1;x<=n;x++){
    for(int y=x+1;y<=n;y++){
      if(r[x]<l[y] ||r[y]<l[x]){
          //ranges don't overlap
          if(r[x]+1==l[y] || r[y]+1==l[x]){
              edges.emplace_back(max(v[x],v[y]),mp(x,y));
          }
          continue;
      }
      edges.emplace_back(v[x]+v[y],mp(x,y));
    }
  }
  for(int i=0;i<edges.size();i++){
    adjl[edges[i].second.first].emplace_back(edges[i].second.second,edges[i].first);
    adjl[edges[i].second.second].emplace_back(edges[i].second.first,edges[i].first);
  }
  priority_queue<pii,vector<pii>, greater<pii> > dijk;//dist, node...
  dijk.push(mp(0,0));
  while(!dijk.empty()){
    a=dijk.top().second;//the node...
    dijk.pop();
    for(int i=0;i<adjl[a].size();i++){
      if(max(dist[a],adjl[a][i].second)<dist[adjl[a][i].first]){
        dist[adjl[a][i].first]=max(dist[a],adjl[a][i].second);
        dijk.push(mp(dist[adjl[a][i].first],adjl[a][i].first));
      }
    }
  }
  /*sort(edges.begin(),edges.end());
  int i=0;//next thing to merge...
  while(getr(0)!=getr(n+1) && i<edges.size()){
    merge(edges[i].second.first,edges[i].second.second);
    ans=edges[i].first;
    i++;
  }
  for(int i=0;i<edges.size();i++){
      if(getr(edges[i].second.first)==getr(edges[i].second.second)){
          if(getr(edges[i].second.first)==getr(0)){//part of the path
              ans=max(ans,edges[i].first);
          }
      }
  }*/
  if(dist[n+1]==1e15)cout<<"-1\n";
  else cout<<dist[n+1]<<'\n';
  return 0;
}