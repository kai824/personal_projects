#include<bits/stdc++.h>
using namespace std;

#define db false
#define int long long
#define eb emplace_back
#define f first
#define s second

const int mod=1e9+7,mxn=500005;

int exp(int a,int b){
  int ans=1;
  while(b){
    if(b&1){
      ans*=a;
      ans%=mod;
    }
    b>>=1;
    a*=a;
    a%=mod;
  }
  return ans;
}
#define inv(x) exp(x,mod-2)

int val[mxn];
vector<pair<int,char> > adjl[mxn];

int par[mxn][20],hh[mxn];

char ps[mxn];//sign of edge to par...
int mrt[mxn],mp[mxn];//multiplicative root + product
int zr[mxn];//zero count: workaround so mmi works :waturr:

int sum1[mxn],sum2[mxn];

void dfs(int nd,int p=-1){
  if(p==-1)hh[nd]=1;
  else hh[nd]=hh[p]+1;
  par[nd][0]=p;
  for(int i=1;i<20;i++){
    if(par[nd][i-1]==-1)par[nd][i]=-1;
    else par[nd][i]=par[par[nd][i-1]][i-1];
  }
  if(p==-1){
    mrt[nd]=nd;
    if(val[nd]==0){
      mp[nd]=zr[nd]=1;
    }else mp[nd]=val[nd];
  }

  if(p==-1){
    sum1[nd]=sum2[nd]=val[nd];
  }else{
    int pnd=mp[nd];if(zr[nd]>0)pnd=0;
    if(mrt[nd]==1)sum2[nd]=pnd;
    else{
      sum2[nd]=sum2[par[mrt[nd]][0]];
      if(ps[mrt[nd]]=='-')sum2[nd]-=pnd;
      else sum2[nd]+=pnd;
    }
    sum2[nd]=(sum2[nd]+mod)%mod;

    int pp=mp[p];if(zr[p]>0)pp=0;
    if(ps[nd]=='*'){
      sum1[nd]=sum1[p]-pp+pnd;
    }else if(ps[nd]=='+'){
      sum1[nd]=sum1[p]+val[nd];
    }else{
      sum1[nd]=sum1[p]-(pp*2)+val[nd];
    }
    sum1[nd]=(sum1[nd]+mod+mod)%mod;
  }

  if(db)cout<<"DFS: "<<nd<<' '<<sum1[nd]<<' '<<sum2[nd]<<' '<<mp[nd]<<' '<<zr[nd]<<'\n';
  for(auto x:adjl[nd]){
    if(x.f==p)continue;
    if(x.s=='*'){
      mrt[x.f]=mrt[nd];
      if(val[x.f]==0){
        mp[x.f]=mp[nd];
        zr[x.f]=zr[nd]+1;
      }else{
        mp[x.f]=(mp[nd]*val[x.f])%mod;
        zr[x.f]=zr[nd];
      }
    }else{
      mrt[x.f]=x.f;mp[x.f]=val[x.f];
      if(mp[x.f]==0){
        zr[x.f]=mp[x.f]=1;
      }
    }
    ps[x.f]=x.s;
    dfs(x.f,nd);
  }
}
int lca(int a,int b){
  if(hh[a]<hh[b])swap(a,b);
  for(int i=19;i>=0;i--){
    if(hh[a]-(1ll<<i)>=hh[b])a=par[a][i];
  }
  if(a==b)return a;
  for(int i=19;i>=0;i--){
    if(par[a][i]!=par[b][i]){
      a=par[a][i];b=par[b][i];
    }
  }
  return par[a][0];
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);

  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>val[i];
  }
  for(int i=1;i<n;i++){
    int a,b;char c;
    cin>>a>>b>>c;
    adjl[a].eb(b,c);
    adjl[b].eb(a,c);
  }
  dfs(1);

  while(q--){
    int a,b,c;
    cin>>a>>b;
    c=lca(a,b);

    int a1=a,b1=b;
    char s1,s2;s1=s2='+';
    if(mrt[a1]!=mrt[c]){
      for(int i=19;i>=0;i--){
        if(par[a1][i]==-1)continue;
        if(hh[a1]-(1ll<<i)<hh[c])continue;
        if(mrt[par[a1][i]]!=mrt[c])a1=par[a1][i];
      }
      if(ps[a1]=='-')s1='-';
      a1=par[a1][0];
    }
    if(mrt[b1]!=mrt[c]){
      for(int i=19;i>=0;i--){
        if(par[b1][i]==-1)continue;
        if(hh[b1]-(1ll<<i)<hh[c])continue;
        if(mrt[par[b1][i]]!=mrt[c])b1=par[b1][i];
      }
      if(ps[b1]=='-')s2='-';
      b1=par[b1][0];
    }
    int mv=(mp[a1]*mp[b1])%mod;//middle value...
    int z=zr[a1]+zr[b1];
    if(val[c]==0)z--;
    else mv=(mv*inv(val[c]))%mod;
    if(mrt[c]!=c){
      z-=zr[par[c][0]]*2;
      mv*=inv( (mp[par[c][0]]*mp[par[c][0]])%mod );
      mv%=mod;
    }//mv: a1->c->b1 product
    if(z>0)mv=0;

    if(db)printf("Path: %lld->%lld->%lld->%lld->%lld\n",a,a1,c,b1,b);

    int va,vb;
    if(a1==a)va=0;
    else{
      if(s1=='+' || zr[a1]>0)va=(sum1[a]-sum1[a1])%mod;
      else va=(sum1[a]-sum1[a1]+(2*mp[a1]))%mod;
      va=(va+mod)%mod;
    }
    if(b1==b)vb=0;
    else{//actl s2 not impt but wtv
      vb=(sum2[b]-sum2[b1]+mod)%mod;
    }
    if(db)printf("Values: %lld %c %lld + %lld\n",va,s1,mv,vb);
    if(s1=='-')mv=-mv;
    int ans=va+mv+vb;
    ans%=mod;
    ans=(ans+mod)%mod;
    cout<<ans<<'\n';
  }
  return 0;
}
/*
5 8
10 2 3 4 5
2 1 *
3 2 +
1 4 -
4 5 *
1 2
1 3
1 4
1 5
2 1
3 1
4 1
5 1
*/
