#include "matching.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#ifdef local
bool debug=true;
#else
bool debug=false;
#endif

const ll mod=998244353;

bool mk[205][2];
ll dp[205][4];
int count_matching(int n, int m, int a, int b, vector<int> u, vector<int> v){//a=1,b=2
  for(int i=0;i<m;i++)mk[v[i]][v[i]-u[i]-1]=true;
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    dp[i][0]=(dp[i-1][0]+dp[i-1][2])%mod;
    dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
    if(mk[i][0]){
      for(int j=0;j<4;j++){
        dp[i][3]+=dp[i-2][j];
        dp[i][3]%=mod;
      }
    }
    if(mk[i][1]){
      for(int j=0;j<4;j+=2){
        dp[i][1]+=dp[i-2][j];dp[i][1]%=mod;
      }
      dp[i][3]+=dp[i-1][1];dp[i][3]%=mod;
    }
    if(debug){
      cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<' '<<dp[i][3]<<'\n';
    }
  }
  for(int i=1;i<4;i++){
    dp[n][0]+=dp[n][i];
    dp[n][0]%=mod;
  }
  return dp[n][0];
}
