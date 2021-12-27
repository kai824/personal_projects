// ans.cpp 14 Feb 19, 17:10:37 100 0.03 Judging completed in 2.685s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
int arr[100005];//default set to 0...
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,q,a,b,c;
  cin>>n>>q;
  for(int x=0;x<q;x++){
    cin>>a>>b>>c;
    arr[a]=max(arr[a],c);
    arr[b]=max(arr[b],c);
  }
  for(int x=1;x<=n;x++){
    cout<<max(arr[x],1);
    if(x<n)cout<<' ';
  }
  return 0;
}