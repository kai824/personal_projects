#include "counting.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod;
ll exp(ll a,ll b){
  ll ans=1;
  while(b>0){
    if(b&1){
      ans*=a;
      ans%=mod;
    }
    b=(b>>1);
    a=(a*a)%mod;
  }
  return ans;
}
#define inv(x) exp(x,mod-2);

ll dp[100];//count no. of ways to pick add edges with x cells
ll com[100][100];
ll fac[100],inn[100];
vector<ll> v;

ll C(int n,int k){
  return (((fac[n]*inn[n-k])%mod)*inn[k])%mod;
}

int count_valid_board(int n,int k,int m) {
  mod=m;
  ll ans=1,aa,side;//no nothing
  dp[0]=dp[1]=1;
  fac[0]=fac[1]=1;
  inn[0]=inn[1]=1;
  for(int i=2;i<=n;i++){
    dp[i]=dp[i-1];//no edges...
    dp[i]+=(2*(i-1)*dp[i-2])%mod;
    dp[i]%=mod;
    fac[i]=(i*fac[i-1])%mod;
    inn[i]=inv(fac[i]);
    assert(((fac[i]*inn[i])%mod)==1);
    // cout<<dp[i]<<'\n';
  }

  for(int i=0;i<=n;i++){
    com[i][0]=dp[i];
    for(int j=1;j<=n;j++){
      com[i][j]=dp[i];
      for(int k=1;k<=min(i,j);k++){
        com[i][j]+=(((C(i,k)*C(j,k))%mod)*dp[i-k])%mod;//j pairings...
        com[i][j]%=mod;
      }
      // cout<<i<<' '<<j<<'\t'<<com[i][j]<<'\n';
    }
  }

  for(int i=2;i<=n;i++){//no. of nodes in path from 1 to n
    ll cur,ww,sz;
    for(int j=1;j<(1<<(i-1));j++){
      cur=0;
      aa=0;//no. of nodes for pairing...
      v.clear();
      for(int k=0;k+1<i;k++){
        cur++;
        if(j&(1<<k)){
          v.push_back(cur);
          cur=0;
        }
      }
      v.push_back(++cur);
      if(v.size()<=1)continue;
      ww=(fac[n-i+v.size()-2]*inn[n-i])%mod;
      for(int k=1;k+1<v.size();k++){
        if(v[k]==1)goto end;
        aa+=v[k]-2;
      }
      aa+=v[0]-1+v.back()-1;
      side=com[n-i][aa];

      // cout<<"this executed!\n";
      // cout<<i<<' '<<ww<<' '<<aa<<' '<<side*ww<<'\n';
      // for(int x:v){
      //   cout<<x<<'\t';
      // }cout<<'\n';

      ans+=(side*ww)%mod;

      end:;
    }
  }
  return ans;
}
