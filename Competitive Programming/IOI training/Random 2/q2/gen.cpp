#include<bits/stdc++.h>
using namespace std;

const int mxn=10;
int arr[mxn+mxn+5];
pair<int,int> pp[mxn+5];

int32_t main(){
  int a;cin>>a;srand(a);
  int n=5;
  cout<<n<<'\n';
  for(int i=0;i<n;i++){
    arr[2*i+1]=arr[2*i+2]=i+1;
  }
  for(int i=2;i<=2*n;i++){
    swap(arr[i],arr[1+(rand()%(i-1))]);
  }
  for(int i=1;i<=2*n;i++){
    if(pp[arr[i]].first==0)pp[arr[i]].first=i;
    else pp[arr[i]].second=i;
  }
  for(int i=1;i<=n;i++)cout<<pp[i].first<<' '<<pp[i].second<<'\n';
  return 0;
}
