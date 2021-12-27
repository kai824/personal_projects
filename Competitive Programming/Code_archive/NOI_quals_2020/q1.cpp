#include "bits/stdc++.h"
using namespace std;

#define int long long

int mod=1e9+7;
int arr[300005],fact[300005];
int ft[300005],n;

inline int ls(int x){
  return x & (-x);
}
void update(int p,int v){
  for(;p<=n+3;p+=ls(p)){
    ft[p]+=v;
  }
}
int query(int p){
  int ans=0;
  for(;p;p-=ls(p))ans+=ft[p];
  return ans;
}

pair<int,int> disc[300005];

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int a,ans=1;
  cin>>n;
  fact[0]=1;
  for(int x=1;x<=n;x++){
    fact[x]=(fact[x-1]*x)%mod;
  }
  for(int x=0;x<n;x++){
    cin>>arr[x];
    disc[x].first=arr[x];
    disc[x].second=x;
    update(x+1,1);
  }
  sort(disc,disc+n);
  for(int x=0;x<n;x++){
    arr[disc[x].second]=x+1;
  }
  for(int x=0;x<n;x++){
    ans+=fact[n-1-x]*query(arr[x]-1);
    ans%=mod;
    update(arr[x],-1);
  }
  cout<<ans<<'\n';
  return 0;
}
