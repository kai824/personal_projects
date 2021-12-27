#include "roads.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;

vector<pii> adjl[2005];

ll dp[2005][2005][2],n;
vector<ll> v;//for sorting...

void dfs(int node,int prev=-1){
  int cnt=0;
  for(pii x:adjl[node]){
    if(x.f==prev)continue;
    dfs(x.f,node);
    cnt++;
  }
  for(int i=1;i<n;i++){
    //compute dp[node][i]
    for(pii x:adjl[node]){
      if(x.f==prev)continue;
      if(dp[x.f][i][1]+x.s<=dp[x.f][i][0]){//break edge cheaper than not breaking
        dp[node][i][0]+=dp[x.f][i][1]+x.s;
      }else{
        dp[node][i][0]+=dp[x.f][i][0];//spend the degree of up to i...
        v.pb(dp[x.f][i][1]+x.s-dp[x.f][i][0]);//the amount saved...
      }
    }
    dp[node][i][1]=dp[node][i][0];//reduce operations
    if(v.size()==0)continue;
    sort(v.begin(),v.end());
    //degree of v.size() currently...
    for(int j=0;j+i<v.size();j++){//leave i edges
      dp[node][i][1]+=v[j];
    }
    for(int j=0;j+i-1<v.size();j++){//leave i-1
      dp[node][i][0]+=v[j];
    }

    v.clear();
  }
}

vector<ll> minimum_closure_costs(int N, vector<int> u,vector<int> v,vector<int> w){
  n=N;
  assert(n<2005);//go for n^2 dp subtasks...
  vector<ll> ans;
  ll sum=0;
  for(ll x:w)sum+=x;
  ans.push_back(sum);

  for(int i=0;i<n-1;i++){
    adjl[u[i]].eb(v[i],w[i]);
    adjl[v[i]].eb(u[i],w[i]);
  }

  dfs(0);
  for(int i=1;i<n;i++){
    ans.pb(min(dp[0][i][1],dp[0][i][0]) );
  }
  /*for(int i=0;i<n;i++){
    cout<<"Node "<<i<<": ";
    for(int j=1;j<n;j++)cout<<dp[i][j][0]<<' ';
    cout<<'\n';
  }
  for(int i=0;i<n;i++){
    cout<<"Node "<<i<<": ";
    for(int j=1;j<n;j++)cout<<dp[i][j][1]<<' ';
    cout<<'\n';
  }*/
  return ans;
}
