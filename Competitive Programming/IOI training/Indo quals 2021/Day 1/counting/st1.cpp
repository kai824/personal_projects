#include "counting.h"
#include<bits/stdc++.h>
using namespace std;

vector<int> p;
int n,k;
bool nex(int it){
  if(it==0)return false;
  if(p[it]<n){
    p[it]++;
    return true;
  }
  p[it]=1;
  return nex(it-1);
}
bool vis[20];
void dfs(int nd){
  vis[nd]=true;
  if(nd+k>n){
    vis[n+1]=true;
    return;
  }
  for(int i=1;i<=k;i++){
    if(!vis[p[nd+i]])dfs(p[nd+i]);
    if(vis[n+1])return;
  }
}

int count_valid_board(int N,int K,int m){
  n=N;k=K;
  p.clear();
  p.push_back(0);
  for(int i=1;i<=n;i++){//next edge from node i...
    p.push_back(1);
  }
  long long ans=0;
  do{
    //for(int j=1;j<=n;j++)cout<<p[j]<<' ';cout<<'\n';
    memset(vis,false,n+1);
    for(int i=1;i<=n;i++){
      if(p[i]==i)continue;
      if(vis[i]||vis[p[i]])goto hell;
      vis[i]=vis[p[i]]=true;
    }
    memset(vis,false,n+2);
    for(int i=1;i<=k;i++){
      if(!vis[p[i]])dfs(p[i]);
      if(vis[n+1])break;
    }
    if(vis[n+1]){
      ans++;
      // for(int j=1;j<=n;j++)cout<<p[j]<<' ';cout<<'\n';
    }

    hell:;
  }while(nex(n));
  return (ans%m);
}
