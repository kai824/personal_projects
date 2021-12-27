#include "candies.h"
#include<bits/stdc++.h>
using namespace std;

#define lnt long long
const lnt inf=1e17;
typedef pair<lnt,lnt> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back

int main(){
  vector<int> c,l,r,v;
  int n,q;
  n=q=10;

  int ss=0;

  vector<int> a1,a2;
  do{
    c.clear();l.clear();r.clear();v.clear();
    for(int i=0;i<n;i++)c.push_back(1+(rand()%10));
    for(int i=0;i<q;i++){
      int a,b;
      a=rand()%n;b=rand()%n;
      if(a>b)swap(a,b);

      l.push_back(a);
      r.push_back(b);

      v.push_back((rand()%100)-50);
    }

    a1=distribute_candies(c,l,r,v);
    a2=distribute_candies2(c,l,r,v);
  }while(a1==a2);

  cout<<n<<'\n';
  for(int i=0;i<n;i++){
    cout<<c[i]<<' ';
  }cout<<'\n';
  cout<<q<<'\n';
  for(int i=0;i<q;i++){
    cout<<l[i]<<' '<<r[i]<<' '<<v[i]<<'\n';
  }
  cout<<"\n\n";
  for(int x:a1)cout<<x<<' ';cout<<'\n';//correct
  for(int x:a2)cout<<x<<' ';cout<<'\n';//wrong...
  // distribute_candies(c,l,r,v);
  // distribute_candies2(c,l,r,v);
}
