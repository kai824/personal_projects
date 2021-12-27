#include<bits/stdc++.h>
using namespace std;

int arr[300005],dp[900005];
pair<int,int> mm[300005];

vector<int> adjl[900005];//altho prolly 2 children... reduce later if MLE
int val[900005],pre[900005],sub[900005];
int par[900005][20],nex;
int ufds[900005];
int getr(int x){
  if(ufds[x]==-1)return x;
  return ufds[x]=getr(ufds[x]);
}
void merge(int a,int b){
  //cerr<<"Merge "<<a<<' '<<b<<'\n';
  a=getr(a);b=getr(b);
  if(a==b){
    ufds[a]=nex;
    val[nex]=val[a];
    adjl[nex].push_back(a);
  }else{
    ufds[a]=ufds[b]=nex;
    val[nex]=max(val[a],val[b]);
    adjl[nex].push_back(a);adjl[nex].push_back(b);
  }
  nex++;
}

int pp=1;
void dfs(int node,int prev=-1){
  //cerr<<val[node]<<' '<<node<<' '<<prev<<'\n';
  par[node][0]=prev;
  for(int i=1;i<20;i++){
    if(par[node][i-1]==-1)par[node][i]=-1;
    else par[node][i]=par[par[node][i-1]][i-1];
  }
  pre[node]=pp++;
  for(int x:adjl[node]){
    if(x==prev)continue;//shouldn't happen
    dfs(x,node);
  }
  sub[node]=pp-1;
}

struct node{
  int s,e,v=0;
  node *l,*r;
  node(int ss,int ee){
    s=ss;e=ee;
    if(s==e){
      l=r=NULL;
    }else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
    }
  }
  void update(int p,int nv){
    if(s==e){
      v=nv;
      return;
    }
    if(p<=(s+e)/2)l->update(p,nv);
    else r->update(p,nv);
    v=max(l->v,r->v);
  }
  int query(int a,int b){
    if(a<=s && e<=b){
      return v;
    }
    int ans=0;
    if(a<=(s+e)/2)ans=l->query(a,b);
    if((s+e)/2<b)ans=max(ans,r->query(a,b));
    return ans;
  }
} *root;

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,d;
  cin>>n>>d;
  memset(ufds,-1,sizeof(ufds));
  memset(val,-1,sizeof(val));
  for(int i=0;i<n;i++){
    cin>>arr[i];
    mm[i]=make_pair(arr[i],-i);//increasing arr[i], decreasing i...
  }
  sort(mm,mm+n);
  nex=n;
  set<int> act;//activated stuff...
  set<int>::iterator ite;
  for(int i=0;i<n;i++){
    int it=-mm[i].second;
    ite=act.upper_bound(it);
    //merge left...
    if(ite==act.begin())goto end;
    ite--;
    if(*ite+d>=it)merge(*ite,it);
    ite++;
    end:;

    //merge right...
    if(ite!=act.end()){
      if(it+d>=*ite)merge(it,*ite);
    }
    val[getr(it)]=mm[i].first;
    act.insert(it);
  }
  int rt=getr(0);
  dfs(rt);//for preorder purposes...
  root=new node(0,pp);
  int ans=1,a,b;
  for(int i=0;i<n;i++){
    //find appropriate ancestor
    if(val[i]>=0){
      dp[pre[i]]=1;
      root->update(pre[i],1);
      goto hell;
    }
    a=i;
    for(int j=19;j>=0;j--){
      if(par[a][j]==-1)continue;
      if(val[par[a][j]]<arr[i])a=par[a][j];
    }
    a=par[a][0];
    //cout<<"Root "<<i<<' '<<a<<'\n';
    //query range max...
    b=0;
    //cout<<pre[a]<<' '<<sub[a]<<'\n';
    b=root->query(pre[a],sub[a]);
    //for(int j=pre[a];j<=sub[a];j++)b=max(b,dp[j]);
    //update...
    dp[pre[i]]=b+1;
    root->update(pre[i],b+1);
    ans=max(ans,dp[pre[i]]);

    hell:;
    //cout<<"DP value "<<i<<' '<<dp[pre[i]]<<'\n';
  }
  cout<<ans<<'\n';
  return 0;
}
