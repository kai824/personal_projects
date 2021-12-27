// ans.cpp 21 May 20, 11:45:13 0 0.15 Judging completed in 6.833s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

int n,l,h;
int cc[100005],ww[100005];
long double ps[100005];

deque<pair<long double,int> > dq;//value, index...

bool poss(long double k){//see if can do at cost k
  for(int x=1;x<=n;x++){
    ps[x]=ps[x-1]+cc[x]-(k*ww[x]);
  }
  dq.clear();
  for(int x=l;x<=h;x++){
    while(dq.size()>0 && dq.back().first<=ps[x]){
      dq.pop_back();
    }
    dq.emplace_back(ps[x],x);
  }
  for(int x=0;x<=n;x++){
    if(x+l>n)break;
    if(dq[0].first>=ps[x]){
      //cout<<"take the range "<<x+1<<" to "<<dq[0].second<<' '<<dq[0].first<<'\n';
      return true;
    }
    while(dq.size()>0 && dq[0].second<=l)dq.pop_front();//slide the range forward by 1...
    if(x+h+1>n)continue;
    while(dq.size()>0 && dq.back().first<=ps[x])dq.pop_back();
    dq.emplace_back(ps[x],x);
  }
  return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    long double lo=0,hi=1e6,mid;
    cin>>n>>l>>h;
    for(int x=1;x<=n;x++){
      cin>>cc[x]>>ww[x];
    }
    while(lo+0.000000001<hi){
      mid=(lo+hi)/2;
      if(poss(mid)){
        lo=mid;
        //cout<<"Ok can do on "<<mid<<'\n';
      }else hi=mid;
    }
    cout<<fixed<<setprecision(9);
    cout<<lo;
    return 0;
}