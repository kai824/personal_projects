#include "jumps.h"

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back
//each time, call init(n,h) and then query minimum_jumps(a,b,c,d)

//put the brute force bfs method here...
vector<int> adjl[200005];
int dis[200005],N;
void init(int n,vector<int>h){
  N=n;
  for(int i=0;i<n;i++)adjl[i].clear();
  vector<pii> v;
  v.eb(h.back(),h.size()-1);
  for(int i=h.size()-2;i>=0;i--){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()>0)adjl[i].push_back(v.back().s);
    v.eb(h[i],i);
  }
  v.clear();

  v.eb(h[0],0);
  for(int i=1;i<n;i++){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()>0)adjl[i].push_back(v.back().s);
    v.eb(h[i],i);
  }
}
deque<int> bfs;
int minimum_jumps(int a,int b,int c,int d){
  int n=N;
  for(int i=0;i<n;i++)dis[i]=1e9;
  bfs.clear();
  for(int i=a;i<=b;i++){
    bfs.push_back(i);
    dis[i]=0;
  }
  int k;
  while(bfs.size()>0){
    k=bfs.front();
    //if(c<=k && k<=d)return dis[k];
    bfs.pop_front();
    for(int x:adjl[k]){
      if(dis[x]==1e9){
        dis[x]=dis[k]+1;
        if(c<=x && x<=d)return dis[x];
        bfs.push_back(x);
      }
    }
  }
  return -1;
}
