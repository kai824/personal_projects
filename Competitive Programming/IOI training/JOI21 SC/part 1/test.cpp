#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pii pair<int,int>
#define f first
#define s second

int32_t main(){
  map<int,int> dd;
  dd[1]=1;dd[2]=2;dd[3]=3;
  auto it=dd.begin();it++;
  cout<<it->f<<' '<<it->s<<'\n';
  cout<<"After erase...\n";
  it=dd.erase(it);
  cout<<it->f<<' '<<it->s;
}
