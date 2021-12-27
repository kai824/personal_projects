// ans.cpp 27 Nov 17, 14:57:02 100 0 Judging completed in 4.276s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n,v,i,i2;
  cin>>n>>v;
  long long coins[n];
  long long amt[v+1];
  for(i=0;i<=v;i++){
    amt[i]=1000000000000000000;
  }
  for(i=0;i<n;i++){
    cin>>coins[i];
  }
  amt[0]=0;
  for(i=0;i<n;i++){
    for(i2=coins[i];i2<=v;i2++){
      amt[i2]=min(amt[i2-coins[i]]+1,amt[i2]);
      //cout<<amt[i2]+1<<" "<<i<<" "<<i2<<" "<<amt[i2+coins[i]]<<endl;
    }
  }
  //for(i=0;i<v+1;i++)cout<<amt[i]<<endl;
  if(amt[v]==1000000000000000000)cout<<"-1";
  else cout<<amt[v];
}