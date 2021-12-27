#include "bits/stdc++.h"
using namespace std;

#define int long long

vector<pair<int,int> > adjl[3005];
int n,k,dist[3005];//distance from root node...

vector<int> v0,v1;//v0 is within reach, v1 is out of reach...
vector<int> vv[3005];//faraway children...
int dp[3005][2];
//0 for exclude this node, 1 for include
//1e9 if cannot...

bool first=true;
void recurse(int node){
  if(dp[node][1]>=dp[node][0]){
    if(first==false)cout<<' ';
    first=false;
    cout<<node;
    for(int x=0;x<vv[node].size();x++){
      recurse(vv[node][x]);
    }
  }else{
    ;
  }
}

pair<int,int> dfs(int node,int dd,int prev,bool root=false){
  //returns min cost of subtree if need to overflow,
  //and min cost of dont need to overflow...
  pair<int,int> ans=make_pair(-1,0),kk;
  int diff=1e9;
  bool c=false;
  for(int x=0;x<adjl[node].size();x++){
    if(adjl[node][x].first==prev)continue;
    if(dd+adjl[node][x].second>k){
      v1.push_back(adjl[node][x].first);
      ans.second+=min(dp[adjl[node][x].first][0],dp[adjl[node][x].first][1]);
      continue;
    }
    c=true;
    kk=dfs(adjl[node][x].first,dd+adjl[node][x].second,node);
    if(kk.first>=kk.second){
      ans.second+=kk.second;
      diff=min(diff,kk.first-kk.second);
      continue;
    }else{
      diff=0;
      ans.second+=kk.first;//since it's smaller...
    }
  }
  if(root){
    //cout<<"dfs"<<node<<' '<<c<<'\n';
  }
  if(c==false){
    if(root)return make_pair(1+ans.second,ans.second);
    return make_pair(dp[node][1],dp[node][0]);
  }
  if(root){
    ans.first=ans.second+diff;
  }else ans.first=min(ans.second+diff,dp[node][1]);
  return ans;
}

void dfs2(int node,int prev=-1){
  bool c=false;
  for(int x=0;x<adjl[node].size();x++){
    if(adjl[node][x].first==prev)continue;
    c=true;
    dfs2(adjl[node][x].first,node);
  }
  if(c==false){//no children nodes...
    dp[node][0]=1e9;
    dp[node][1]=1;
    //cout<<"dfs2 on node "<<node<<'\n';
    //cout<<"issa leaf node!!\n\n";
    return;
  }
  v0.clear();v1.clear();
  dp[node][0]=dfs(node,0,prev,true).first;
  vv[node]=v1;

  if(dp[node][0]>=1e9)dp[node][0]=1e9;
  dp[node][1]=1;
  for(int x=0;x<v1.size();x++){
    dp[node][1]+=min(dp[v1[x]][0],dp[v1[x]][1]);//take the stuff out of reach...
  }
  dp[node][0]=min(dp[node][0],dp[node][1]);
  //cout<<"dfs2 on node "<<node<<'\n';
  //cout<<dp[node][0]<<' '<<dp[node][1]<<"\n\n";
}

int32_t main(){
  //ios_base::sync_with_stdio(false);cin.tie(0);
  int a,b,c;
  cin>>n>>k;//where k is the max distance...
  if(n>5005){
    cout<<n<<'\n';
    for(int x=1;x<=n;x++){
      cout<<x;
      if(x<n)cout<<' ';
    }
    return 0;
  }
  for(int x=1;x<n;x++){
    cin>>a>>b>>c;
    adjl[a].emplace_back(b,c);
    adjl[b].emplace_back(a,c);
  }
  dfs2(1);
  cout<<min(dp[1][0],dp[1][1])<<'\n';
  recurse(1);
  return 0;
}
/*

4 3
1 2 2
2 3 3
3 4 4

9 4
1 2 10
2 3 4
8 9 4
8 7 3
7 3 5
3 4 1
4 5 3
5 6 2

ans:
cost 4
*/
