#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

vector<int> adjl[200005];
int sz[200005],tsz[200005];
int par[200005];

void dfs(int nd,int prev=-1){
  tsz[nd]=sz[nd];
  par[nd]=prev;
  for(int x:adjl[nd]){
    if(x==prev)continue;
    dfs(x,nd);
    tsz[nd]+=tsz[x];
  }
}
int dfs2(int nd,int prev=-1){
  for(int x:adjl[nd]){
    if(x==prev)continue;
    if(tsz[x]*2>tsz[1])return dfs2(x,nd);
  }
  return nd;
}
void upd(int nd,int d,int prev=-1){
  sz[nd]+=d;
  for(int x:adjl[nd]){
    if(x!=prev)upd(x,d,nd);
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,q;
  cin>>n>>q;
  int a,b,c;
  for(int i=1;i<n;i++){
    cin>>a>>b>>c;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    cin>>sz[i];
  }
  dfs(1);//update parent array first...
  while(q--){
    cin>>a>>b>>c;
    if(a==1){
      sz[b]+=c;
    }else if(a==2)sz[b]-=c;
    else if(a==3)upd(b,c,par[b]);
    else upd(b,-c,par[b]);
    dfs(1);
    //for(int i=1;i<=n;i++)cout<<tsz[i]<<' ';cout<<'\n';
    cout<<dfs2(1)<<'\n';//finds centroid: verify observation first
  }
}
