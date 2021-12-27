#include<bits/stdc++.h>
using namespace std;

int main(){
  int sd;cin>>sd;srand(sd);

  int x,n,m,w,t;
  x=30+(rand()%20);
  n=2;
  m=5;
  w=3+(rand()%10);
  t=8+(rand()%10);
  if((x%t)==0)x++;
  cout<<x<<' '<<n<<' '<<m<<' '<<w<<' '<<t<<'\n';

  set<int> ss;ss.insert(0);ss.insert(x%t);//these cannot be used again...
  for(int i=0;i<n;i++){
    int a=rand()%t;
    while(ss.find(a)!=ss.end()){
      a=rand()%t;
    }
    ss.insert(a);
    cout<<a+(t*(rand()%(x/t)))<<'\n';
  }
  for(int i=0;i<m;i++){
    int a=rand()%t;
    while(ss.find(a)!=ss.end()){
      a=rand()%t;
    }
    ss.insert(a);
    cout<<a<<' ';
    cout<<3+(rand()%20)<<'\n';
  }
  return 0;
}
