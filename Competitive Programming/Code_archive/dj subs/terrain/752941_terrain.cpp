// terrain.cpp 9 Aug 20, 16:51:51 0 2.03 Judging completed in 11.3s on AWS Oregon.
#include "terrain.h"
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;

int dp[300005],thres;
vector<int> adjl[300005],hh;
vector<pair<pii,int> >nodes;//node number (1-indexed),

int best_hike(int n, int e, vector<int> h, vector<int> d, vector<int> a, vector<int> b){
  int ans=INT_MAX;
  for(int i=0;i<e;i++){
    //connect A[i] and B[i]...
    if(d[a[i]-1]==d[b[i]-1]){//cos of the non-overlapping condition, can just assume same d will always go upwards...
      if(h[a[i]-1]<h[b[i]-1])adjl[a[i]].push_back(b[i]);
      else adjl[b[i]].push_back(a[i]);
    }else if(d[a[i]-1]>d[b[i]-1])adjl[b[i]].push_back(a[i]);//adjl stores who you can go to next...
    else adjl[a[i]].push_back(b[i]);
  }
  for(int i=0;i<n;i++){
    nodes.emplace_back(mp(d[i],h[i]),i+1);//sort by this to determine order to process nodes...
    hh.push_back(h[i]);
  }
  sort(nodes.begin(),nodes.end());
  sort(hh.begin(),hh.end());
  for(int i=0;i<hh.size();i++){
    if(i>0 && hh[i]==hh[i-1])continue;//try a different min height lah...
    if(hh[i]>h[0] || hh[i]>h.back()){//no point trying min height greater than height of stop 1 or n
      break;
    }
    thres=hh[i];//min height
    for(int i=1;i<=n;i++)dp[i]=INT_MAX;//max height to pass through to reach node i
    dp[1]=h[0];
    for(int i=1;i<=n;i++){
      if(dp[i]==INT_MAX)continue;//can't even reach this node smh
      if(h[i-1]<thres)continue;
      for(int j=0;j<adjl[i].size();j++){
        dp[adjl[i][j]]=min(dp[adjl[i][j]],max(dp[i],h[adjl[i][j]-1]) );
      }
    }
    if(dp[n]<INT_MAX)ans=min(ans,dp[n]-thres);
  }
  if(ans==INT_MAX)return -1;
  return ans;
}
/*
8 14 11 0 3 14
7 1 7 4 0 3 19 4 17 3 15 18
1 4
2 4
2 8
3 1
3 4
4 5
4 7
5 2
5 3
6 8
7 1
7 6
7 8
8 4
*/