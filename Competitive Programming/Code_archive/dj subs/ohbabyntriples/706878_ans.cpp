// ans.cpp 29 Feb 20, 12:45:33 15 1.26 Judging completed in 5.194s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define mp make_pair
#define int long long//learning from chur zhe
#define pii pair<int,int>
int l[3005],r[3005],v[3005];

int parent[3010];
int getr(int x){
  if(parent[x]==-1)return x;
  parent[x]=getr(parent[x]);
  return parent[x];
}
inline void merge(int a,int b){
  a=getr(a);b=getr(b);
  if(a==b)return;
  parent[a]=b;
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,ans=0;
  cin>>n>>m;
  for(int x=1;x<=n;x++){
    cin>>l[x]>>r[x]>>v[x];
  }
  for(int x=0;x<=n+1;x++){
    parent[x]=-1;
  }
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
  sort(edges.begin(),edges.end());
  int i=0;//next thing to merge...
  while(getr(0)!=getr(n+1) && i<edges.size()){
    merge(edges[i].second.first,edges[i].second.second);
    ans=edges[i].first;
    i++;
  }
  for(int i=0;i<edges.size();i++){
      if(getr(edges[i].second.first)==getr(edges[i].second.second)){
          //ans=max(ans,edges[i].first);
      }
  }
  if(getr(0)!=getr(n+1))cout<<"-1\n";
  else cout<<ans<<'\n';
  return 0;
}