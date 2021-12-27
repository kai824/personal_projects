#include<bits/stdc++.h>
using namespace std;

int main(){
  int a;cin>>a;
  srand(a);
  int n=7;
  cout<<n<<'\n';
  for(int i=2;i<=n;i++){
    cout<<(rand()%(i-1))+1<<' '<<i<<' ';
    cout<<(rand()%10)+1<<'\n';
  }
}
