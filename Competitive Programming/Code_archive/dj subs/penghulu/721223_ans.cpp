// ans.cpp 7 Apr 20, 09:46:49 0 0.14 Judging completed in 3.809s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define int long long

int ww[100005],depth[100005];

vector<int> adjl[100005];
int po[100005],st[100005],nex=1;//preorder, subtree...
int ps[100005];//prefix sum for no. of villagers...

void dfs(int node,int prev){
  ps[nex]=ww[node];
  po[node]=nex;nex++;
  if(prev==-1)depth[node]=0;
  else depth[node]=depth[prev]+1;
  for(int x=0;x<adjl[node].size()-1;x++){
    if(adjl[node][x]==prev){
      swap(adjl[node][x],adjl[node][adjl[node].size()-1]);
    }
  }
  if(prev==adjl[node].back())adjl[node].pop_back();//only keep the children...
  for(int x=0;x<adjl[node].size();x++){
    dfs(adjl[node][x],node);
  }
  st[node]=nex-1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,a,b,total=0,lo,hi,mid;
    cin>>n>>q;
    for(int x=1;x<=n;x++){
      cin>>ww[x];
      total+=ww[x];
    }
    for(int x=1;x<n;x++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
    }
    dfs(1,-1);
    for(int x=1;x<=n;x++)ps[x]+=ps[x-1];
    while(q--){
      cin>>a>>b;//a is district leader...
      if(po[b]<=po[a] && po[a]<=st[b] && depth[b]<depth[a]){//b is ancestor of a...
        lo=0;hi=adjl[b].size()-1;//find which subtree it's in...
        while(lo<hi){
          mid=lo+(hi-lo)/2;
          if(po[adjl[b][mid]]<=po[a] && po[a]<=st[adjl[b][mid]]){
            lo=mid;
            hi=mid;break;
          }else if(po[adjl[b][mid]]>po[a]){
            hi=mid-1;
          }else lo=mid+1;
        }
        lo=adjl[b][lo];
        cout<<total-(ps[st[lo]]-ps[po[lo]-1])<<'\n';
      }else{//just take the whole subtree of b
        cout<<ps[st[b]]-ps[po[b]-1]<<'\n';
      }
    }
    return 0;
}
/*
5 5
3 1 4 1 5
1 2
1 3
2 4
2 5


2 1
5 1
1 4
2 5
5 4
*/