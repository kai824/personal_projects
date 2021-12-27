#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

const int32_t mxn=200005;

int sz[mxn];
int pre[mxn],rpre[mxn],rt[mxn],nex=1;
struct node{//range max...
  int s,e,v;
  int lz=0;//lazy add...
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
      v=sz[rpre[s]];
    }else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
      v=max(l->v,r->v);
    }
  }
  void prop(){
    if(s<e){
      l->upd(s,e,lz);
      r->upd(s,e,lz);
    }lz=0;
  }
  void upd(int a,int b,int c){
    if(a<=s && e<=b){
      lz+=c;
      v+=c;//range max mah...
      return;
    }
    prop();
    if(a<=(s+e)/2)l->upd(a,b,c);
    if((s+e)/2<b)r->upd(a,b,c);
    v=max(l->v,r->v);
  }
  int query(int mn){//last value that >=mn...
    if(s==e)return s;
    prop();
    if(r->v>=mn)return r->query(mn);
    else return l->query(mn);
  }
} *root;

vector<int> adjl[mxn];
int cnt[mxn];
int par[mxn];
void dfsc(int nd,int prev=-1){//count subtree size... init for HLD...
  par[nd]=prev;
  cnt[nd]=1;
  int mm=-1;
  for(int i=0;i<adjl[nd].size();i++){
    if(adjl[nd][i]==prev)continue;
    dfsc(adjl[nd][i],nd);
    cnt[nd]+=cnt[adjl[nd][i]];
    if(mm==-1 || cnt[adjl[nd][i]]>cnt[adjl[nd][mm]])mm=i;
  }
  if(mm>0)swap(adjl[nd][0],adjl[nd][mm]);
}

void dfs(int nd,int prev=-1){
  if(prev==-1)rt[nd]=nd;
  pre[nd]=nex;
  rpre[nex++]=nd;
  for(int i=0;i<adjl[nd].size();i++){
    if(adjl[nd][i]==prev)continue;
    if(i==0)rt[adjl[nd][i]]=rt[nd];
    else rt[adjl[nd][i]]=adjl[nd][i];
    dfs(adjl[nd][i],nd);
    sz[nd]+=sz[adjl[nd][i]];//for subtree initialisation...
  }
}
void hld(int nd,int amt){
  while(nd!=-1){//-1 should be the root node...
    //cout<<"Propagate "<<pre[rt[nd]]<<' '<<pre[nd]<<" by "<<amt<<'\n';
    root->upd(pre[rt[nd]],pre[nd],amt);
    nd=par[rt[nd]];
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,q;
  int a,b,c;

  cin>>n>>q;
  for(int i=1;i<n;i++){
    cin>>a>>b>>c;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }
  dfsc(1);
  int tot=0;
  for(int i=1;i<=n;i++){
    cin>>sz[i];
    tot+=sz[i];
  }
  dfs(1);//establish preorder (and it's reverse) + HLD
  root=new node(1,n);
  while(q--){
    cin>>a>>b>>c;
    if(a==2)c=-c;
    tot+=c;
    hld(b,c);
    cout<<rpre[root->query((tot+1)/2)]<<'\n';//have at least ceil(tot/2);
  }
  return 0;
}
