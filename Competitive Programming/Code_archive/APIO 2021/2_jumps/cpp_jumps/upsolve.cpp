#include "jumps.h"

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#ifdef local
#define debug(x,label) cerr<<label<<' '<<x<<'\n';
#else
#define debug(a,b) ;
#endif

//int N;
pii nex[200005];
int hh[200005];
int par[3][200005][19];//par[0] for greedy 2kd, par[1] for going left only, par[2] for right
void init(int n,vector<int>h){
  //N=n;
  for(int i=0;i<n;i++){
    nex[i]=mp(-1,-1);
    par[0][i][0]=par[1][i][0]=par[2][i][0]=-1;
    hh[i]=h[i];
  }
  vector<pii> v;
  v.eb(h.back(),h.size()-1);
  for(int i=h.size()-2;i>=0;i--){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()>0){
      nex[i]=max(nex[i],v.back() );
      par[2][i][0]=v.back().s;
    }
    v.eb(h[i],i);
  }
  v.clear();

  v.eb(h[0],0);
  for(int i=1;i<n;i++){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()>0){
      nex[i]=max(nex[i],v.back() );
      par[1][i][0]=v.back().s;
    }
    v.eb(h[i],i);
  }
  for(int i=0;i<n;i++){
    par[0][i][0]=nex[i].s;
  }
  for(int i=1;i<19;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<3;k++){
        if(par[k][j][i-1]==-1)par[k][j][i]=-1;
        else par[k][j][i]=par[k][par[k][j][i-1]][i-1];
      }
    }
  }
}
int rmax(int a,int b){//max height
  for(int i=18;i>=0;i--){
    if(par[1][b][i]==-1)continue;
    if(par[1][b][i]<a)continue;
    b=par[1][b][i];
  }
  return hh[b];
}

int minimum_jumps(int a,int b,int c,int d){
  //int n=N;
  int lo,hi;//such that we just need to reach range of [lo,hi]
  hi=rmax(c,d);
  int ans=1;
  for(int i=18;i>=0;i--){
    if(par[1][b][i]==-1)continue;
    if(par[1][b][i]<a)continue;
    if(hh[par[1][b][i]]>hi)continue;
    b=par[1][b][i];
  }//now we start from b...
  lo=rmax(b,c-1);
  if(lo>=hi)return -1;
  debug(b,"start from")
  //cout<<b<<' '<<hh[b]<<' '<<lo<<' '<<hi<<'\n';
  for(int i=18;i>=0 && hh[b]<lo;i--){
    if(par[0][b][i]==-1)continue;
    if(hh[par[0][b][i]]>=lo)continue;
    b=par[0][b][i];
    ans+=(1<<i);
  }
  if(hh[b]<lo && hh[par[0][b][0]]<=hi){
    b=par[0][b][0];ans++;
  }
  debug(b,"intermediate")
  for(int i=18;i>=0 && hh[b]<lo;i--){
    if(par[2][b][i]==-1)continue;
    if(hh[par[2][b][i]]>=lo)continue;
    b=par[2][b][i];
    ans+=(1<<i);
  }
  if(hh[b]<lo){
    ans++;
    b=par[2][b][0];
  }
  if(hh[b]>hi || hh[b]<lo)return -3;//tf?
  return ans;
}
