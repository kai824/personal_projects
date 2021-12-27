// ans.cpp 21 Oct 19, 23:20:23 50 0 Judging completed in 3.344s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long coins[9]={1,5,10,50,100,500,1000,5000,10000};
long long value[9];

int main() {
  long long n=10,v,v2,ans=1e15,cur;
  cin>>v;
  v2=v;
  for(int x=0;x<10;x++){
      cur=0;
      for(int y=8;y>=x;y--){
          cur+=v/coins[y];
          v%=coins[y];
      }
      while(v>=17 && (v%5)!=0){
          cur++;
          v-=17;
      }
      for(int y=x-1;y>=0;y--){
          cur+=v/coins[y];
          v%=coins[y];
      }
      v=v2;
      ans=min(ans,cur);
      
      cur=0;
      for(int y=8;y>=x;y--){
          cur+=v/coins[y];
          v%=coins[y];
      }
      cur+=v/17;
      v%=17;
      for(int y=x-1;y>=0;y--){
          cur+=v/coins[y];
          v%=coins[y];
      }
      v=v2;
      ans=min(ans,cur);
  }
  //for(i=0;i<v+1;i++)cout<<amt[i]<<endl;
  cout<<ans;
}