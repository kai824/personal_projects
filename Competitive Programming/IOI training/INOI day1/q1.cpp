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

const int mod=1000000007;

vector<int> adjl[1000005];
int dp[1000005];
int vali[1000005],vals[1000005];//vals stores expected no. of diff values...

void dfs(int node,int prev=-1){
  int cnt;
  if(prev==-1){
    cnt=0;
  }else cnt=1;
  dp[node]=cnt;
  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs(x,node);
    dp[node]+=dp[x];cnt++;
    dp[node]%=mod;
  }
  dp[node]-=vals[cnt];
  dp[node]=(dp[node]+mod)%mod;
}

int exp(int a,int b){
  int ans=1;
  while(b>0){
    if(b&1){
      ans*=a;
      ans%=mod;
    }
    b/=2;
    a=(a*a)%mod;
  }
  return ans;
}
#define inv(x) exp(x,mod-2)

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m;cin>>n>>m;
  //compute probs[i]
  vali[1]=1;
  int mm=inv(m);
  for(int i=2;i<=n;i++){
    vali[i]=vali[i-1]+1;
    vali[i]-=(vali[i-1]*mm)%mod;
    vali[i]=(vali[i]+mod)%mod;
  }
  for(int i=1;i<=n;i++)vals[i]=(i-vali[i]+mod)%mod;
  for(int i=1;i<=n;i++){
    //cout<<i<<' '<<vals[i]<<'\n';
  }

  for(int i=1;i<n;i++){
    int a,b;cin>>a>>b;
    adjl[a].push_back(b);
    adjl[b].push_back(a);
  }
  dfs(2);
  cout<<dp[2]<<'\n';
  return 0;
}
/*

*/
