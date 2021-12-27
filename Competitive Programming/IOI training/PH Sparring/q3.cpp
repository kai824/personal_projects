#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second

const int mod=1234567890ll;

int dp[2][43][75005];//edges traversed, discretised last weight, node
pair<int,pii> el[75005];
vector<pii> adjl[45];
vector<int> rel[45];
int vals[75005],lef[75005],rig[75005];

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int tc,n,m,k,d,ans;
  int a,b,c;
  cin>>tc;
  while(tc--){
    ans=0;
    cin>>n>>m>>k>>d;
    for(int i=1;i<=n;i++){
      adjl[i].clear();
      rel[i].clear();
      for(int j=1;j<=m;j++){
        dp[0][i][j]=dp[1][i][j]=0;
      }
    }
    for(int i=0;i<m;i++){
      cin>>el[i].s.f>>el[i].s.s>>el[i].f;
    }
    sort(el,el+m);
    a=1;//cur edge weight
    for(int i=0;i<m;i++){
      if(i>0 && el[i].f>el[i-1].f)a++;
      vals[a]=el[i].f;

      b=el[i].s.f;c=el[i].s.s;
      adjl[b].emplace_back(c,a);
      adjl[c].emplace_back(b,a);
      // if(rel[b].empty() || rel[b].back()<a)rel[b].push_back(a);
      // if(rel[c].empty() || rel[c].back()<a)rel[c].push_back(a);
      dp[1][b][a]++;
      dp[1][c][a]++;
    }//a is now highest edge weight...

    //compute lef and rig array...
    if(d>0){
      for(int i=1;i<=a;i++){
        if(i==1)lef[i]=1;
        else{
          lef[i]=lef[i-1];
          while(vals[lef[i]]+d<=vals[i])lef[i]++;
        }
      }
      for(int i=a;i>=1;i--){
        if(i==a)rig[i]=i;
        else{
          rig[i]=rig[i+1];
          while(vals[i]+d<=vals[rig[i]])rig[i]--;
        }
      }
    }
    // for(int i=1;i<=a;i++){
    //   cout<<i<<' '<<vals[i]<<'\t'<<lef[i]<<' '<<rig[i]<<'\n';
    // }

    for(int i=1;i<k;i++){
      b=(i&1);c=1-b;//dp[b] is current, dp[c] is prev...
      for(int node=1;node<=n;node++){
        for(int j=1;j<=a;j++)dp[c][node][j]=0;
      }
      for(int node=1;node<=n;node++){
        for(int j=1;j<=a;j++){//prefix sum...
          dp[b][node][j]+=dp[b][node][j-1];
          dp[b][node][j]%=mod;
        }
        for(pii x:adjl[node]){
          if(d==0)dp[c][x.f][x.s]+=dp[b][node][a];
          else dp[c][x.f][x.s]+=(dp[b][node][a]-dp[b][node][rig[x.s]]+dp[b][node][lef[x.s]-1] +mod)%mod;
          dp[c][x.f][x.s]%=mod;
        }
      }
    }
    c=k&1;
    for(int node=1;node<=n;node++){
      for(int j=1;j<=a;j++){
        ans+=dp[c][node][j];ans%=mod;
        // cout<<dp[c][node][j]<<' ';
      }
      // cout<<'\n';
    }
    cout<<ans<<'\n';
  }
  return 0;
}
