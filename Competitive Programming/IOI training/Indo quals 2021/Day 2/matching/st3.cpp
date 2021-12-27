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
ll dp[2][1100000];
int count_matching(int n, int m, int a, int b, vector<int> u, vector<int> v){//a<b<=20
  for(int i=0;i<m;i++){
    if(v[i]-u[i]==a)mk[v[i]][0]=true;
    else mk[v[i]][1]=true;
  }
  dp[0][0]=1;
  for(int i=1;i<=n;i++){
    for(int j=0;j<(1<<b);j++)dp[i%2][j]=0;
    for(int j=0;j<(1<<b);j++){
      dp[i%2][(j*2)%(1<<b)]+=dp[(i-1)%2][j];
      dp[i%2][(j*2)%(1<<b)]%=mod;
    }

    if(mk[i][0]){//can take path of a to cur...
      for(int j=0;j<(1<<(b+1));j+=2){
        if(j&(1<<a))continue;
        dp[i%2][(j+(1<<a)+1)%(1<<b)]+=dp[(i-1)%2][j/2];
        dp[i%2][(j+(1<<a)+1)%(1<<b)]%=mod;
      }
    }
    if(mk[i][1]){
      for(int j=0;j<(1<<(b+1));j+=2){
        if(j&(1<<b))continue;
        dp[i%2][(j+(1<<b)+1)%(1<<b)]+=dp[(i-1)%2][j/2];
        dp[i%2][(j+(1<<b)+1)%(1<<b)]%=mod;
      }
    }
    if(debug){
      cout<<dp[i%2][0]<<' '<<dp[i%2][1]<<' '<<dp[i%2][2]<<' '<<dp[i%2][3]<<'\n';
    }
  }
  for(int i=1;i<(1<<b);i++){
    dp[n&1][0]+=dp[n&1][i];
    dp[n&1][0]%=mod;
  }
  return dp[n&1][0];
}
