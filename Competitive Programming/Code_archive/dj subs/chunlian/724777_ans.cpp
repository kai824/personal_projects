// ans.cpp 15 Apr 20, 08:54:56 71 0.33 Judging completed in 6.038s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

#define int long long

int arr[300000],sum=0,ans=0;
priority_queue<pair<int,int> > pq;
set<pair<int,int> > ss;//the elements we currently keep
pair<int,int> smallest;

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,c,k;
    cin>>n>>c>>k;
    k=min(k+1,n);//the no. of stuff you can take...
    for(int x=0;x<n;x++)cin>>arr[x];

    for(int x=0;x<k;x++){
      pq.push(make_pair(arr[x],x));
    }
    for(int x=0;x<c;x++){
      smallest=pq.top();pq.pop();
      ss.insert(smallest);
      sum+=smallest.first;
    }
    ans=sum;
    for(int x=k;x<n;x++){//taken x, drop x-k...
      pq.push(make_pair(arr[x],x));
      if(ss.find(make_pair(arr[x-k],x-k) )!=ss.end() ){
        ss.erase(make_pair(arr[x-k],x-k));
        sum-=arr[x-k];
        sum+=pq.top().first;
        ss.insert(pq.top());
        pq.pop();
      }
      if(pq.empty()==false && pq.top().first>ss.begin()->first){
        pq.push(*ss.begin());
        sum-=ss.begin()->first;
        ss.erase(ss.begin());
        sum+=pq.top().first;
        ss.insert(pq.top());
        pq.pop();
      }
      ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}