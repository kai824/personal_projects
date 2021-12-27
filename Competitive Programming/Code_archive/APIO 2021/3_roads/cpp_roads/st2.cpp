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

vector<ll> minimum_closure_costs(int n, vector<int> u,vector<int> v,vector<int> w){
  //u[i]=i,v[i]=i+1: costs money to close stuff
  vector<ll> ans;
  ll sum=0;
  for(int i=0;i<n-1;i++){
    sum+=w[i];
  }
  ans.push_back(sum);

  ll dp[n][2];//first i edges, whether jth edge is open...
  memset(dp,0,sizeof(dp));
  dp[1][1]=0;dp[1][0]=w[0];

  for(int i=2;i<=n-1;i++){
    dp[i][1]=dp[i-1][0];//if ith is open, (i-1)th must close
    dp[i][0]=w[i-1]+min(dp[i-1][0],dp[i-1][1]);
  }
  ans.push_back(min(dp[n-1][0],dp[n-1][1]) );

  while(ans.size()<n){
    ans.push_back(0);
  }
  return ans;
}
/*
4
0 1 1
1 2 5
2 3 1
*/
