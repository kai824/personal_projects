#include<bits/stdc++.h>
using namespace std;

#define int long long
#define eb emplace_back
#define f first
#define s second

const int mxn=5000;
vector<pair<int,char> >adjl[mxn];
int val[mxn],par[mxn],hh[mxn];
char ps[mxn];

void dfs(int nd,int p=-1){
  if(p!=-1)hh[nd]=hh[p]+1;
  par[nd]=p;
  for(auto x:adjl[nd]){
    if(x.f==p)continue;
    ps[x.f]=x.s;
    dfs(x.f,nd);
  }
}
int lca(int a,int b){
  if(hh[a]<hh[b])swap(a,b);
  while(hh[a]!=hh[b])a=par[a];
  while(a!=b){
    a=par[a];b=par[b];
  }
  return a;
}
void bt(int b,int c){
  if(b==c)printf("(%lld)",val[b]);
  else{
    bt(par[b],c);
    printf("%c(%lld)",ps[b],val[b]);
  }
}

int32_t main(){
  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++)cin>>val[i];
  for(int i=1;i<n;i++){
    int a,b;char c;
    cin>>a>>b>>c;
    adjl[a].eb(b,c);
    adjl[b].eb(a,c);
  }
  dfs(1);
  while(q--){
    int a,b;
    cin>>a>>b;
    int c=lca(a,b);
    while(a!=c){
      printf("(%lld)%c",val[a],ps[a]);
      a=par[a];
    }
    bt(b,c);
    printf("\n");
  }
}
