#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

const int32_t mxn=200005;

int sz[mxn];
struct node{
  int s,e,m,v;
  int lz=0;//lazy add...
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
      v=sz[s];
    }else{
      m=(s+e)/2;
      l=new node(s,m);
      r=new node(m+1,e);
      v=(l->v+r->v);
    }
  }
  inline void prop(){
    if(s<e && lz!=0){
      l->lz+=lz;r->lz+=lz;
      l->v+=(m-s+1)*lz;
      r->v+=(e-m)*lz;
    }
    lz=0;
  }
  void update(int a,int b,int c){
    if(a<=s && e<=b){
      lz+=c;
      v+=(e-s+1)*c;
      return;
    }
    prop();
    if(a<=m)l->update(a,b,c);
    if(m<b)r->update(a,b,c);
    v=(l->v+r->v);
  }
  int query(int a,int b){
    if(a<=s && e<=b)return v;
    prop();
    int ans=0;
    if(a<=m)ans+=l->query(a,b);
    if(m<b)ans+=r->query(a,b);
    return ans;
  }
  int get(int mn){
    if(s==e)return s;
    prop();
    if(l->v<mn)return r->get(mn-l->v);
    else return l->get(mn);
  }
} *root;

vector<int> adjl[mxn];
int par[mxn][18],rpre[mxn],pre[mxn],sub[mxn],nex=1;
int tot=0;
void dfs(int nd,int prev=-1){
  par[nd][0]=prev;
  for(int i=1;i<18;i++){
    if(par[nd][i-1]==-1)par[nd][i]=-1;
    else par[nd][i]=par[par[nd][i-1]][i-1];
  }
  pre[nd]=nex;
  rpre[nex++]=nd;
  for(int x:adjl[nd]){
    if(x==prev)continue;
    dfs(x,nd);
  }
  sub[nd]=nex-1;
}

inline int get(int nd){
  if(root->query(pre[nd],sub[nd])<<1>=tot)return nd;

  int kek;
  for(int i=17;i>=0;i--){
    if(par[nd][i]==-1)continue;
    kek=par[nd][i];
    if(root->query(pre[kek],sub[kek])<<1<tot)nd=kek;
  }
  return par[nd][0];
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  int n,q;
  int a,b,c;

  cin>>n>>q;
  for(int i=1;i<n;i++){
    cin>>a>>b>>c;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }
  dfs(1);//form 2^k decomp and preorder...
  for(int i=1;i<=n;i++){//build rupq fenwick tree
    cin>>sz[pre[i]];
  }
  root=new node(1,n);
  tot=root->v;
  while(q--){
    cin>>a>>b>>c;
    if(a==2 || a==4)c=-c;
    if(a<=2){
      tot+=c;
      root->update(pre[b],pre[b],c);//range add...
    }else{
      tot+=(sub[b]-pre[b]+1ll)*c;
      root->update(pre[b],sub[b],c);
    }
    b=get(rpre[root->get((tot+1)/2)]);

    cout<<b<<'\n';
  }
  return 0;
}
