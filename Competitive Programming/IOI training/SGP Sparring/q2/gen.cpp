#include<bits/stdc++.h>
using namespace std;

#define int long long
#define eb emplace_back
#define f first
#define s second

int32_t main(){
  int sd;cin>>sd;srand(sd);

  int n=7,q=3;
  cout<<n<<' '<<q<<'\n';
  for(int i=0;i<n;i++){
    cout<<rand()%10<<' ';
  }cout<<'\n';

  for(int i=2;i<=n;i++){
    cout<<i<<' '<<(rand()%(i-1))+1<<' '<<"+-*"[rand()%3]<<'\n';
  }

  while(q--){
    cout<<1+(rand()%n)<<' '<<1+(rand()%n)<<'\n';
  }
  return 0;
}
