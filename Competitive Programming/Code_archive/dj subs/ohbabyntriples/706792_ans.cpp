// ans.cpp 29 Feb 20, 12:10:45 0 0.83 Judging completed in 4.985s on AWS Oregon.
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
  int n,m,ans=0,nex=1;
  cin>>n>>m;
  vector<int> nums;
  nums.push_back(m);
  for(int x=1;x<=n;x++){
    cin>>l[x]>>r[x]>>v[x];
    nums.push_back(l[x]);
    nums.push_back(r[x]);
  }
  sort(nums.begin(),nums.end());
  map<int,int> disc;
  disc[nums[0]]=1;
  for(int x=1;x<nums.size();x++){
    if(nums[x]!=nums[x-1]){
      disc[nums[x]]= ++nex;
    }
  }
  for(int x=0;x<=nex+1;x++){
    parent[x]=-1;
  }
  vector<pair<int,pii> > edges;
  for(int x=1;x<=n;x++){
    l[x]=disc[l[x]];r[x]=disc[r[x]];
    if(l[x]<=1)edges.emplace_back(v[x],mp(0,x));
    if(r[x]>=nex)edges.emplace_back(v[x],mp(nex+1,x));
  }
  for(int x=1;x<=n;x++){
    for(int y=x+1;y<=n;y++){
      if(r[x]<l[y]-1 ||r[y]<l[x]-1)continue;//ranges don't overlap
      edges.emplace_back(v[x]+v[y],mp(x,y));
    }
  }
  sort(edges.begin(),edges.end());
  int i=0;//next thing to merge...
  while(getr(0)!=getr(nex+1) && i<edges.size()){
    merge(edges[i].second.first,edges[i].second.second);
    ans=edges[i].first;
    i++;
  }
  if(getr(0)!=getr(nex+1))cout<<"-1\n";
  else cout<<ans<<'\n';
  return 0;
}