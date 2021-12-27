#include<bits/stdc++.h>
using namespace std;

int main(){
  int s;cin>>s;srand(s);

  int n,d;
  n=10;d=1;
  cout<<n<<' '<<d<<'\n';
  for(int i=0;i<n;i++){
    cout<<(1+rand()%10)<<' ';
  }
}
