// ans.cpp 28 Mar 20, 09:46:45 44 0.08 Judging completed in 3.655s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

vector<int> adjl[100005];
int n,k,m1,m2;

int dfs(int node,int prev=-1){
  int ans=0;
  vector<int> v;
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    v.push_back(dfs(adjl[node][i],node) );
  }
  sort(v.begin(),v.end(),greater<int>() );
  for(int i=0;i<v.size();i++){
    ans=max(ans,v[i]+i+1);
  }
  return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    if(k==1)cin>>m1;
    else cin>>m1>>m2;

    int a,b;
    for(int x=1;x<n;x++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    a=dfs(m1);
    if(m2==0){
      cout<<a;
      return 0;
    }
    return 0;
}