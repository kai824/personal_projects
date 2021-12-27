// ans.cpp 28 Mar 20, 13:46:29 56 2 Judging completed in 5.786s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

bool finding=true;
vector<int> path;
bool marked[100005],in_path[100005],allow=false;
vector<int> adjl[100005];
int n,k,m1,m2,xx;

int dfs(int node,int prev=-1){
  int ans=0;
  vector<int> v;
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    if(allow==true && node==xx && in_path[adjl[node][i]])continue;
    if(adjl[node][i]==xx && allow==false){
      if(finding)path.push_back(node);
      marked[node]=true;
      continue;
    }
    v.push_back(dfs(adjl[node][i],node) );
    if(marked[adjl[node][i]]){
      marked[node]=true;
      if(finding)path.push_back(node);
    }
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
    xx=m2;

    int a,b,ans=INT_MAX;
    for(int x=1;x<n;x++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    a=dfs(m1);
    if(m2==0){
      cout<<a;
      return 0;
    }else{
      finding=false;
      for(int i=0;i<path.size();i++){
        in_path[path[i]]=true;
      }in_path[m2]=true;
      for(int i=0;i<path.size();i++){
        xx=path[i];
        allow=true;
        a=dfs(m1);
        allow=false;
        b=dfs(m2);
        ans=min(ans,max(a,b));
        //cout<<path[i]<<' '<<a<<' '<<b<<'\n';
      }
      cout<<ans<<'\n';
    }
    return 0;
}