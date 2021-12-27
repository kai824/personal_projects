#include<bits/stdc++.h>
using namespace std;

string ss[10],add=" ";

int main(){
  int a;cin>>a;
  srand(a);
  int n=4,k,tot=0;
  for(int i=0;i<n;i++){
    a=1+(rand()%5);
    for(int j=0;j<a;j++){
      add[0]='a'+(rand()%26);
      ss[i]+=add;
    }
    tot+=a;
  }

  k=n+(rand()%(tot+1-n));

  cout<<n<<' '<<k<<'\n';
  for(int i=0;i<n;i++){
    cout<<ss[i]<<'\n';
  }
}
