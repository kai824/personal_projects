#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define mp make_pair
typedef pair<int,int> pii;
#define f first
#define s second

#ifdef local
#define debug(x,label) cerr<<"DEBUG "<<label<<" "<<x<<'\n';
bool deb=true;
#else
#define debug(x,label);
bool deb=false;//for in-code checking
#endif

#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)
#define lbd lower_bound
#define upb upper_bound

int par[100005];

int32_t main(){//gen 1 testcase...
  int a;cin>>a;srand(a);
  int n,k;
  n=7;k=2+(rand()%5);
  cout<<n<<' '<<k<<'\n';
  vector<pii>v;v.eb(1,0);
  for(int i=2;i<=n;i++){
    int it=rand()%(v.size());

      if(deb){
        cout<<i<<'\n';
        for(pii x:v)cout<<x.f<<' '<<x.s<<'\n';
        cout<<"END: "<<it<<' '<<v[it].f<<'\n';
        cout<<"\n\n";
      }

    par[i]=v[it].f;
    v[it].s++;
    if(v[it].s>=2){
      if(it+1<v.size())swap(v[it],v[v.size()-1]);
      v.pop_back();
    }
    v.eb(i,0);
  }
  for(int i=2;i<=n;i++){
    if(rand()%2)cout<<i<<' '<<par[i]<<'\n';
    else cout<<par[i]<<' '<<i<<'\n';
  }
}
