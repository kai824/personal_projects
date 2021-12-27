// ans.cpp 29 Feb 20, 12:59:10 15 0 Judging completed in 3.959s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define mp make_pair
#define int long long//learning from chur zhe
#define pii pair<int,int>
int l[3005],r[3005],v[3005];

pii dp[10005];//max value, value of last element...

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,ans=0,nex=1,s,e;
  cin>>n>>m;
  vector<int> nums;
  nums.push_back(m);
  for(int x=1;x<=n;x++){
    cin>>l[x]>>r[x]>>v[x];
    nums.push_back(l[x]);
    nums.push_back(r[x]);
  }
  sort(nums.begin(),nums.end());
  map<int,int> disc;
  disc[nums[0]]=1;
  for(int x=1;x<nums.size();x++){
    if(nums[x]!=nums[x-1]){
        if(nums[x]==nums[x-1]+1){
            disc[nums[x]]=++nex;
        }else{
            nex+=2;
            disc[nums[x]]=nex;
        }
    }
  }
  for(int x=1;x<=nex;x++){
    dp[x].first=dp[x].second=LLONG_MAX;
  }
  vector<pair<pii,int> > ranges;
  for(int x=1;x<=n;x++){
    l[x]=disc[l[x]];
    r[x]=disc[r[x]];
    ranges.emplace_back(mp(r[x],l[x]),v[x]);
  }
  sort(ranges.begin(),ranges.end());
  for(int x=0;x<n;x++){
    s=ranges[x].first.second;
    e=ranges[x].first.first;
    if(max(dp[s-1].first,ranges[x].second)<dp[e].first){
      dp[e]=mp(max(dp[s-1].first,ranges[x].second),ranges[x].second);
    }
    for(int i=s;i<e;i++){
      if(max(max(dp[i].first,dp[i].second+ranges[x].second),ranges[x].second)<dp[e].first){
        dp[e]=mp(max(max(dp[i].first,dp[i].second+ranges[x].second),ranges[x].second) ,ranges[x].second);
      }
    }
  }
  if(dp[nex].first==LLONG_MAX)cout<<"-1\n";
  else cout<<dp[nex].first<<'\n';
  return 0;
}