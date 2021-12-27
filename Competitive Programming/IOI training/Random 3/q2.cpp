#include<bits/stdc++.h>
using namespace std;

int arr[100005],n,k;
int arr2[100005];
bool poss(int x){
  if(k==0){
    //cout<<"oo\n";
    arr2[0]=arr[0];
    for(int i=1;i<n;i++){
      if(arr2[0]+x+x<arr[i]){
        return false;
      }
      arr2[0]=min(arr2[0]+x,arr[i]);
    }
    return true;
  }
  for(int i=0;i<k;i++){
    ;
  }
  for(int i=n-1;i>k;i--){
    ;
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int t;
  cin>>n>>k>>t;
  k--;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    arr[i]*=2;
  }t*=2;

  if(k==n-1){
    k=0;
    for(int i=0;i<n;i++){
      arr[i]=arr[n-1]-arr[i];
    }
  }
  int lo,hi,mid;
  lo=0;hi=4e9;//distance travelled before it runs out...
  while(lo<hi){
    mid=lo+((hi-lo)/2);
    if(poss(mid)){
      hi=mid;
    }else lo=mid+1;
  }
  cout<<lo<<'\n';

  if(lo%t)cout<<(lo/t)+1;
  else cout<<lo/t;
  return 0;
}
