#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define mp make_pair
typedef pair<int,int> pii;
#define f first
#define s second

#ifdef local
#define debug(x,label) cerr<<"DEBUG "<<label<<" "<<x<<'\n';
bool deb=true;
#else
#define debug(x,label);
bool deb=false;//for in-code checking
#endif

#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define lbd lower_bound
#define upb upper_bound

//const int mod=1000000007 or 998244353;

vector<int> adjl[100005];
int dp[100005][35],k;

int tmp,t2;
vector<int> v;
void dfs(int node,int prev){//assumes there's an edge above node, and fixes this edge
  dp[node][1]=0;//a value to be minimised
  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs(x,node);
    dp[node][1]+=dp[x][k-1]+1;
  }

  for(int i=2;i<k;i++){
    //dp[node][i]=tmp=0;
    if(2*(i-1)<k){
      for(int x:adjl[node]){//all edges have diff colour
        if(x==prev)continue;
        dp[node][i]+=dp[x][i-1];
      }
    }else{
      tmp=0;
      v.clear();
      for(int x:adjl[node]){
        if(x==prev)continue;
        dp[node][i]+=dp[x][k-i];
        v.push_back(dp[x][k-i]-dp[x][i-1]);
      }
      sort(v.begin(),v.end());
      if(v.size()>0){
        dp[node][i]-=v.back();v.pop_back();
      }
      while(v.size()>0 && v.back()>1){
        dp[node][i]-=(v.back()-1);v.pop_back();
      }
      dp[node][i]=min(dp[node][i],t2);
    }
    dp[node][i]=min(dp[node][i],dp[node][i-1]);
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,a,b;
  cin>>n>>k;
  for(int i=1;i<n;i++){
    cin>>a>>b;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }
  for(int i=1;i<=n;i++){
    if(adjl[i].size()==1){
      a=i;break;
    }
  }//find leaf node
  b=adjl[a][0];
  dfs(b,a);
  if(deb)
  for(int i=1;i<=n;i++){
    for(int j=1;j<k;j++){
      cout<<dp[i][j]<<' ';
    }cout<<'\n';
  }
  cout<<n-1-dp[b][k-1];
  return 0;
}
/*

*/
