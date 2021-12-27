#include"bits/stdc++.h"
using namespace std;

#define int long long

pair<int,int> arr[500005];

vector<int> v;//the current LDS...

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,lo,hi,mid;
    cin>>n>>m;
    for(int x=0;x<m;x++){
      cin>>arr[x].first;//A[x]
    }
    for(int x=0;x<m;x++){
      cin>>arr[x].second;//T[x]
    }
    for(int x=0;x<m;x++){
      a=arr[x].first;b=arr[x].second;
      arr[x]=make_pair(a-b,a+b);
    }
    sort(arr,arr+m);
    for(int x=0;x<m;x++){
      //add arr[x].second
      if(v.size()==0){
        v.push_back(arr[x].second);
        continue;
      }
      if(v.back()>arr[x].second){
        v.push_back(arr[x].second);continue;
      }
      lo=0;hi=v.size()-1;
      while(lo<hi){//find first instance where arr[x].second>=v[lo]
        mid=lo+((hi-lo)/2);
        if(arr[x].second>=v[mid]){
          hi=mid;
        }else{//v[mid]>=arr[x].second
          lo=mid+1;
        }
      }
      v[lo]=max(v[lo],arr[x].second);
    }
    cout<<v.size();
    return 0;
}
