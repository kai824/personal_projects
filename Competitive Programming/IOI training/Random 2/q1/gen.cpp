#include<bits/stdc++.h>
using namespace std;

int main(){
  int a;cin>>a;srand(a);
  set<pair<int,int> > ss;

  int r=10,c=10,n=1+(rand()%10);
  cout<<r<<' '<<c<<' '<<n<<'\n';
  for(int i=0;i<n;i++){
    int a=1+(rand()%r),b=1+(rand()%c);
    while(ss.find(make_pair(a,b))!=ss.end()){
      a=1+(rand()%r),b=1+(rand()%c);
    }
    cout<<a<<' '<<b<<'\n';
  }
  int q=15;
  cout<<q<<'\n';
  for(int i=0;i<q;i++){
    for(int j=0;j<2;j++){
      int a=1+(rand()%r);cout<<a<<' ';
      a=1+(rand()%c);cout<<a<<' ';
    }
    cout<<'\n';
  }
  return 0;
}
