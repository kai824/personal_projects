#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

int cnto[5001],cnte[5001];

map<pii,bool> um;

char c;
bool les(int a,int b){
  if(um.find(mp(a,b))!=um.end())return um[mp(a,b)];
  cout<<"compare "<<a<<' '<<b<<endl;
  cin>>c;
  return um[mp(a,b)]=(c=='<');
}

int32_t main(){
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(false);
  int n,st;
  cin>>st>>n;
  int e,o;
  e=(n/2);o=n-e;

  if(st==1){
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
    return 0;
  }

  int lo,hi,mid;

  //assume odd numbers are sorted...
  for(int i=1;i<=e;i++){
    lo=1,hi=e;
    while(lo<hi){
      mid=lo+((hi-lo)/2);
      if(les(i,mid+1))hi=mid;
      else lo=mid+1;
    }
    cnte[i]=lo;
  }
  for(int i=1;i<=e;i++){
    if(les(cnte[i],cnte[i]))goto esorted;
    if(cnte[i]<o && les(cnte[i],cnte[i]+1)==false)goto esorted;
  }
  cout<<"answer";
  for(int i=1;i<=e;i++){
    cout<<' '<<cnte[i]*2;
  }
  for(int i=1;i<=n;i+=2){
    cout<<' '<<i;
  }
  return 0;
  esorted:;
  //cout<<"oo"<<endl;

  for(int i=1;i<=o;i++){
    lo=1,hi=o;
    while(lo<hi){
      mid=lo+((hi-lo)/2);
      if(!les(mid,i))hi=mid;
      else lo=mid+1;
    }
    cnto[i]=lo;
  }

  cout<<"answer";
  for(int i=2;i<=n;i+=2){
    cout<<' '<<i;
  }
  for(int i=1;i<=o;i++){
    cout<<' '<<cnto[i]*2-1;
  }
}
