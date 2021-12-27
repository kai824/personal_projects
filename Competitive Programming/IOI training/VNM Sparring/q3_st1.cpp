#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

int cnto[5001],cnte[5001];

char c;
bool les(int a,int b){
  cout<<"compare "<<a<<' '<<b<<endl;
  cin>>c;
  return (c=='<');
}

int32_t main(){
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(false);
  int n;
  cin>>n>>n;
  int e,o;
  e=(n/2);o=n-e;
  for(int i=1;i<=e;i++){
    for(int j=1;j<=o;j++){
      if(les(i,j)){
        cnto[j]++;
      }else cnte[i]++;
    }
  }
  cout<<"answer";
  for(int i=1;i<=e;i++){
    cout<<' '<<cnte[i]*2;
  }
  for(int i=1;i<=o;i++){
    cout<<' '<<cnto[i]*2+1;
  }
}
