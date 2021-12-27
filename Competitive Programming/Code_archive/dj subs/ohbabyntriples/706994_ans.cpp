// ans.cpp 29 Feb 20, 13:28:37 0 0 Compilation failed on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define mp make_pair
#define int long long//learning from chur zhe
#define pii pair<int,int>
int l[3005],r[3005],v[3005];

int main2(int n,int m){
    for(int x=0;x<n;x++){
        cin>>l[x]>>r[x]>>v[x];
    }
    int ans=1e15,cur,maxi;
    map<int,int> stat;
    for(int i=1;i<(1ll<<n);i++){
        stat.clear();
        for(int x=0;x<n;x++){
            if((1<<x)&i){
                stat[l[x]]+=v[x];
                stat[r[x]+1]-=v[x];
            }
        }
        cur=maxi=0;
        if(stat.begin()->first!=1)continue;
        for(auto it=stat.begin();it!=stat.end();it++){
          if(it->first>m)break;
            cur+=it->second;
            maxi=max(maxi,cur);
            if(cur==0)break;
        }
        if(cur!=0){
          ans=min(ans,maxi);
        }
    }
    if(ans==1e15)cout<<"-1\n";
    else cout<<ans<<'\n';
    return 0;
}
int main3(int n,int m){
  int cur=0;
  map<int,int> stat;
  pair<int,int> arr[n];
  for(int x=0;x<n;x++){
    cin>>l[x]>>r[x]>>v[x];
    stat[l[x]]+=v[x];
    stat[r[x]]-=v[x];
    arr[x]=mp(r[x],l[x]);
  }
  for(auto it=stat.begin();it!=stat.end();it++){
    if(it->first>m)break;
    cur+=it->second;
    maxi=max(maxi,cur);
    if(cur==0)break;
  }
  if(cur==0){
    cout<<"-1\n";return 0;
  }
  sort(arr,arr+n);
  set<int> poss;
  poss.insert(0);
  for(int x=0;x<n;x++){
    if(poss.find(arr[x].first)!=poss.end())continue;
    if(poss.find(arr[x].second-1)!=poss.end())poss.insert(arr[x].first);
  }
  if(poss.find(m)!=poss.end())cout<<"1\n";
  else cout<<"2\n";
}

pii dp[10005];//max value, value of last element...

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,ans=0,nex=1,s,e;
  cin>>n>>m;
  if(n<=10){
      main2(n,m);
      return 0;
  }else if(n>3001){
    main3(n,m);
    return 0;
  }
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