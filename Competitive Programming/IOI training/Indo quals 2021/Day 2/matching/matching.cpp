#include "matching.h"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

const ll mod=998244353;
ll dp[205][205][405][4];//im not convinced this works
vector<int> adjl[205];
int count_matching(int n, int m, int a, int b, vector<int> u, vector<int> v){
  for(int i=0;i<m;i++)adjl[v[i]].push_back(u[i]);
  memset(dp,0,sizeof(dp));
  for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int ed=0;ed<=m;ed++)dp[i][j][ed][0]=1;
  for(int i=1;i<=1;i++){
    for(int j=i;j<=3;j++){
      dp[i][j][0][0]=1;//take nothing
      for(int ed=1;ed<=m;ed++){
        dp[i][j][ed][0]=dp[i-1][j][ed][0]+dp[i-1][j][ed][2];
        dp[i][j][ed][1]=0;
        dp[i][j][ed][2]=0;
        dp[i][j][ed][3]=dp[i][j][ed-1][3];
        if(1){
          for(int k=0;k<4;k++){
            if(i==u[ed-1] && j==v[ed-1])dp[i][j][ed][3]+=dp[i-1][j-1][ed-1][k];
          }
        }
        cout<<"dp "<<i<<' '<<j<<' '<<ed<<":\t";
        for(int k=0;k<4;k++)cout<<dp[i][j][ed][k]<<' ';cout<<'\n';
      }
    }
  }
  ll ans=dp[n][n][m][0]+dp[n][n][m][3];ans%=mod;
  return ans;
}
/*
dp[1 1 1]=1 0 0 0
dp[1 1 2]=1 0 0 0
dp[1 1 3]=1 0 0 0
dp[1 2 1]=1 0 0 1
dp[1 2 2]=1 0 0 1
dp[1 2 3]=1 0 0 1
dp[1 3 1]=
dp[1 3 2]
dp[1 3 3]
dp[1 4 1]
dp[1 4 2]
dp[1 4 3]
dp[2 1 1]
dp[2 1 2]
dp[2 1 3]
dp[2 2 1]
dp[2 2 2]
dp[2 2 3]
dp[2 3 1]
dp[2 3 2]
dp[2 3 3]
dp[2 4 1]
dp[2 4 2]
dp[2 4 3]
dp[3 1 1]
dp[3 1 2]
dp[3 1 3]
dp[3 2 1]
dp[3 2 2]
dp[3 2 3]
dp[3 3 1]
dp[3 3 2]
dp[3 3 3]
dp[3 4 1]
dp[3 4 2]
dp[3 4 3]
dp[4 1 1]
dp[4 1 2]
dp[4 1 3]
dp[4 2 1]
dp[4 2 2]
dp[4 2 3]
dp[4 3 1]
dp[4 3 2]
dp[4 3 3]
dp[4 4 1]
dp[4 4 2]
dp[4 4 3]
5
*/
