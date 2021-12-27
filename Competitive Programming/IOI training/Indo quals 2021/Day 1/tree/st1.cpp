#include "tree.h"
#include<bits/stdc++.h>
using namespace std;
//i swear if this works

vector<int> adjl[11],its;
bool inc(int it){//par array on bfs array
  if(it<0)return false;
  its[it]++;
  if(its[it]>it){
    its[it]=0;
    return inc(it-1);
  }
  return true;
}

vector<int> v;
int df(int nd,int p=-1){
  v.push_back(nd);
  int ans=0;
  for(int x:adjl[nd]){
    if(x==p)continue;
    ans=max(ans,df(x,nd));
  }
  return ans+1;
}
int aa,bb;
typedef pair<int,int> pii;
#define eb emplace_back
void bf(int x){
  deque<pii> d;
  d.eb(x,-1);
  while(d.size()>0){
    aa=d.front().first;bb=d.front().second;
    v.push_back(aa);
    d.pop_front();
    for(int nex:adjl[aa]){
      if(nex==bb)continue;
      d.eb(nex,aa);
    }
  }
}

double count_average_height(int n, vector<int> dfs, vector<int> bfs) {
  double a=0,b=0;
  int h;
  its.clear();
  for(int i=1;i<n;i++)its.push_back(0);
  do{
    for(int i=1;i<=n;i++)adjl[i].clear();
    for(int i=1;i<n;i++){
      adjl[bfs[its[i-1]]].push_back(bfs[i]);
    }
    v.clear();
    h=df(bfs[0]);
    /*for(int i=1;i<n;i++)cout<<"Parent "<<bfs[i]<<": "<<bfs[its[i-1]]<<'\n';
    for(int y:dfs)cout<<y<<' ';cout<<'\n';
    cout<<(v==dfs)<<"\n\n";*/
    if(v!=dfs)continue;
    v.clear();
    bf(bfs[0]);
    if(v!=bfs)continue;
    a+=h;
    b+=1;
  }while(inc(its.size()-1));
  //cout<<a<<' '<<b<<'\n';

  return (a/b);
}
