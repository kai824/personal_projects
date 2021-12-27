#include<bits/stdc++.h>
using namespace std;

int arr[300005];

int main(){
  int n,d;
  cin>>n>>d;
  assert(d==1);
  vector<int> v;
  int a,ans=1;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(int i=n-1;i>=0;i--){
    a=arr[i];
    while(v.size()>0 && v.back()<=a){
      v.pop_back();
    }
    v.push_back(a);
    if(v.size()>ans)ans=v.size();
  }
  cout<<ans<<'\n';
  return 0;
}
