// ans.cpp 21 Oct 19, 23:39:45 100 0 Judging completed in 3.317s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
  long long v,i,i2,ans=0;
  cin>>v;
  long long coins[9]={1,5,10,50,100,500,1000,5000,10000};
  long long coins2[6]={1,5,10,17,50,100};
  for(int x=8;x>=4;x--){
      ans+=v/coins[x];
      v%=coins[x];
  }
  long long amt[1000];
  for(i=0;i<=v;i++){
    amt[i]=INT_MAX;
  }
  amt[0]=0;
  for(i=0;i<6;i++){
    for(i2=coins2[i];i2<=v;i2++){
      amt[i2]=min(amt[i2-coins2[i]]+1,amt[i2]);
      //cout<<amt[i2]+1<<" "<<i<<" "<<i2<<" "<<amt[i2+coins[i]]<<endl;
    }
  }
  cout<<amt[v] + ans;
  return 0;
}