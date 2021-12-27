//generates one testcase...
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define eb emplace_back
#define mp make_pair
#define f first
#define s second

int main(){
  int a;cin>>a;srand(a);

  cout<<1<<'\n';

  int n=7,q=3;
  int par[n+1];
  cout<<n<<' '<<q<<'\n';
  for(int i=2;i<=n;i++){
    par[i]=1+(rand()%(i-1));
    cout<<i<<' '<<par[i]<<'\n';
  }
  for(int i=1;i<=q;i++){
    cout<<1+(rand()%n)<<' '<<(1+(rand()%n))<<' '<<(1+(rand()%n))<<'\n';
  }
  return 0;
}
