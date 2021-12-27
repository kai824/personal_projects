#include<bits/stdc++.h>
using namespace std;
#define int long long
//shouldn't need, just in case...

int eve[2000005];

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin>>n;
  int a,b;
  for(int i=1;i<=n;i++){
    cin>>a>>b;
    eve[a]=i;
    eve[b]=-i;
  }
  int ans=0;
  vector<int> v1,v2;
  for(int i=0;i<(1ll<<n);i++){
    v1.clear();v2.clear();
    for(int j=1;j<=(2*n);j++){
      if(i&(1<<(abs(eve[j])-1))){
        if(eve[j]>0)v1.push_back(eve[j]);
        else if(v1.back()==abs(eve[j]))v1.pop_back();
        else goto sadge;
      }else{
        if(eve[j]>0)v2.push_back(eve[j]);
        else if(v2.back()==abs(eve[j]))v2.pop_back();
        else goto sadge;
      }
    }
    ans++;

    sadge:;
  }
  cout<<ans;
  return 0;
}
