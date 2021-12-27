#include "bits/stdc++.h"
using namespace std;
#define int long long
#define eb emplace_back
#define mp make_pair
typedef pair<int,int> pii;
#define f first
#define s second

const int mod=1000000007;

#define mm(xx) (mod+(xx%mod))%mod
int n,g,q;

int ft[3][100005];//tt, ps1, ps2
#define ls(x) (x&(-x))
void update(int it,int a,int b,int c){//rupq...
  b++;
  for(;a<=n;a+=ls(a))ft[it][a]=(ft[it][a]+c)%mod;
  for(;b<=n;b+=ls(b))ft[it][b]=mm(ft[it][b]-c);
}
int query(int it,int x){
  int ans=0;
  for(;x;x-=ls(x))ans=(ans+ft[it][x])%mod;
  return ans;
}

vector<pair<int,pii> > adjl[100005];
int32_t dep[100005],pt[100005];//depth, previous toll...
int dis[100005],tt[100005];//tt stands for total toll...
int par[100005][19],x=0;

int pre[100005],sub[100005],nex=1;
int ps1[100005],ps2[100005];//down, up, both assume 0 at root node so need to displace...
void dfs(int node,int prev=-1,int dd=0,int depth=1){
  pre[node]=nex++;
  update(0,pre[node],pre[node],tt[node]);
  depth%=mod;dd%=mod;
  dep[node]=depth;dis[node]=dd;
  par[node][0]=prev;
  for(int i=1;i<19;i++){
    if(par[node][i-1]==-1)par[node][i]=-1;
    else par[node][i]=par[par[node][i-1]][i-1];
  }
  if(prev==-1)ps1[node]=ps2[node]=0;
  else{
    ps1[node]=ps1[prev];
    ps1[node]-=tt[node]*(dis[node]-dis[prev]);
    //ps1[node]+=(x-dis[node]);
    ps1[node]=mm(ps1[node]);

    ps2[node]=ps2[prev];
    //add tt[prev]*last dist
    ps2[node]+=tt[prev]*(dis[node]-dis[prev]);
    ps2[node]=mm(ps2[node]);

    pt[node]=mm(tt[node]-tt[prev]);
  }
  update(1,pre[node],pre[node],mm(ps1[node]+(tt[node]*dis[node])) );//ps1
  update(2,pre[node],pre[node],mm(ps2[node]-(tt[node]*dis[node])) );//ps2
  //cerr<<node<<' '<<ps1[node]<<' '<<ps2[node]<<'\t'<<dis[node]<<' '<<tt[node]<<'\n';
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i].f==prev)continue;
    tt[adjl[node][i].f]=(tt[node]+adjl[node][i].s.s)%mod;
    dfs(adjl[node][i].f,node,dd+adjl[node][i].s.f,depth+1);
  }
  sub[node]=nex-1;
}

inline int lca(int a,int b){
  if(dep[a]<dep[b])swap(a,b);
  for(int i=18;i>=0;i--){
    if(dep[a]-(1<<i)>=dep[b])a=par[a][i];
  }
  if(a==b)return a;

  for(int i=18;i>=0;i--){
    if(par[a][i]!=par[b][i]){
      a=par[a][i];
      b=par[b][i];
    }
  }
  return par[a][0];
}

inline int gtt(int x){//get total toll
  return query(0,pre[x]);
}
inline int gps1(int x){//get ps1
  return mm(query(1,pre[x])-(dis[x]*gtt(x)));
}
inline int gps2(int x){//get ps2
  return mm(query(2,pre[x])+(dis[x]*gtt(x)));
}
int qq(int a,int b){//a to b, how much fuel...
  int c=lca(a,b),ans=0,k;
  int ttb=gtt(b),ttc=gtt(c);
  k=g+ttb-ttc;//gold at lca, UPDATES will change

  //cerr<<"LCA: "<<c<<'\n';

  //down path
  ans=gps1(b)-gps1(c);
  //cerr<<ans<<' ';
  ans+=(k+ttc)*(dis[b]-dis[c]);
  ans=mm(ans);
  //cerr<<(k+tt[c])*(dis[b]-dis[c])<<'\t';

  //up path
  ans+=gps2(a)-gps2(c);
  //cerr<<ps2[a]-ps2[c]<<' ';
  ans+=(k-ttc)*(dis[a]-dis[c]);
  ans=mm(ans);
  return ans;
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>g;
  int a,b,d,t;
  for(int i=1;i<n;i++){
    cin>>a>>b>>d>>t;
    adjl[a].eb(b,mp(d,t) );
    adjl[b].eb(a,mp(d,t) );
  }
  dfs(1);
  cin>>q;
  while(q--){
    cin>>t;
    if(t==0){//update, toll change...
      cin>>a>>b>>d;
      if(dep[a]<dep[b])swap(a,b);//make a child (so we editting edge from a to parent)
      update(1,pre[a],sub[a],mm((d-pt[a])*dis[b]) );
      update(2,pre[a],sub[a],mm((pt[a]-d)*dis[a]) );
      update(0,pre[a],sub[a],mm(d-pt[a]) );
      pt[a]=d;
    }else{
      cin>>a>>b;//query...
      cout<<qq(a,b)<<'\n';
    }
  }
  return 0;
}
/*
4 3
1 2 3 0
2 3 1 0
3 4 4 0
1
1 1 4

6 2
1 2 2 1
2 3 1 2
2 4 2 3
4 5 2 2
4 6 1 4
3
1 3 6
0 4 5 5
1 2 5

23 18
*/
