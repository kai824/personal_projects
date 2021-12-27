#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

vector<int> adjl[120005],v1,v2;
vector<pair<int,pii> > qq[120005];//root node here...

int hh[120005],h1[120005],par[120005],anss[120005];//some excessively large arrays (for ST1-4)

void dfs(int node,int prev=-1){
  par[node]=prev;
  h1[node]=0;
  if(prev==-1)hh[node]=1;
  else hh[node]=hh[prev]+1;

  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs(x,node);
    h1[node]=max(h1[node],h1[x]+1);
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int tc,n,q;
  cin>>tc;
  while(tc--){
    cin>>n>>q;
    int a,b,r;
    for(int i=1;i<=n;i++){
      adjl[i].clear();
      qq[i].clear();
    }
    for(int i=1;i<n;i++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    for(int i=0;i<q;i++){
      cin>>r>>a>>b;
      qq[r].eb(i,mp(a,b));
    }
    for(int i=1;i<=n;i++){
      if(qq[i].size()==0)continue;
      dfs(i);
      for(auto x:qq[i]){
        v1.clear();v2.clear();
        a=x.s.f;b=x.s.s;
        while(a!=b){
          if(hh[a]>=hh[b]){
            v1.push_back(h1[a]);
            a=par[a];
          }else{
            v2.push_back(h1[b]);
            b=par[b];
          }
        }
        v1.push_back(h1[a]);

        anss[x.f]=v2.size();
        anss[x.f]=(anss[x.f]*(anss[x.f]-1))/2;
        a=0;

        for(int j=0;j<v1.size();j++){
          while(a<v2.size() && v2[a]<v1[j])a++;
          anss[x.f]+=a;
        }
      }
    }

    for(int i=0;i<q;i++)cout<<anss[i]<<'\n';
  }
  return 0;
}
