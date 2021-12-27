// ans.cpp 24 Feb 20, 12:33:04 22 0.11 Judging completed in 4.522s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

typedef long long ll;
ll cnt[31];//number of ways to end up for each possible bit...

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  ll n,a,ways;
  cin>>n;
  for(int x=0;x<n;x++){
    cin>>a;
    if(x==0){
      ways=1;
    }else{
      ways=0;
      for(ll i=0;i<30;i++){
        if(((1ll<<i)&a)!=0){
          ways+=cnt[i];
        }
      }
    }
    for(ll i=0;i<30;i++){
      if(((1ll<<i)&a)!=0){
        cnt[i]+=ways;
      }
    }
  }
  cout<<ways<<'\n';
  return 0;
}