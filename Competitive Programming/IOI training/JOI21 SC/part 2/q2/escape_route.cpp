#include "escape_route.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=LLONG_MAX;
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define pii pair<ll,ll>

vector<pair<ll,pii> > adjl[95];//closing time, next node, road length

vector<ll> calculate_necessary_time(
    int n, int m, ll s, int q, vector<int> a, vector<int> b,vector<ll> l, vector<ll> c,
    vector<int> u,vector<int> v, vector<ll> t){
  for(int i=0;i<m;i++){//a b l c...
    adjl[a[i]].eb(c[i],mp(b[i],l[i]));
    adjl[b[i]].eb(c[i],mp(a[i],l[i]));
  }
  for(int i=0;i<n;i++){
    ;
  }

  return vector<ll>(q, 0);
}
