// ans.cpp 9 Dec 17, 16:09:29 36 1.02 Judging completed in 7.271s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
vector<vector<int> >v(1000010);
bool vis[1000010];
int m=0,id;
void dfs(int node,int val){
  if (vis[node])return;
  vis[node]=1;
  if (val>m){
    m=val;
    id=node;
  }
  for (int i=0;i<v[node].size();i++){
    dfs(v[node][i],val+1);
  }
}
int dist[1000010];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,i,x;
  cin>>n;
  for (i=2;i<=n;i++){
    m=0;
    cin>>x;
    v[x].push_back(i);v[i].push_back(x);
    memset(vis,0,sizeof(vis));
    dfs(1,0);
    m=-1;
    memset(vis,0,sizeof(vis));
    dfs(id,0);
    cout<<m<<'\n';
  }
  
}