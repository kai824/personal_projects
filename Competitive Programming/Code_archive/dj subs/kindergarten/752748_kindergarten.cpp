// kindergarten.cpp 9 Aug 20, 15:43:18 0 2.16 Judging completed in 13.096s on AWS Oregon.
#include "kindergarten.h"
#include"bits/stdc++.h"
using namespace std;

#define maxn 300005
typedef long long ll;
typedef pair<ll,ll> pii;

//arrays are 1-indexed, but not the vectors given :(
ll ps[maxn],dp[maxn];
int leftt[maxn];//the rightmost person you cannot include...

struct node{//segtree[i] stores the line you get if you end prev team at i, and take next team from i+1 onwards
  ll s,e;
  vector<pii> v;//all the lines...
  node *l,*r;
  node(ll ss,ll ee){
    s=ss;e=ee;
    if(s==e)l=r=NULL;
    else{
      l=new node(s,(s+e)/2);
      r=new node((s+e)/2+1,e);
    }
  }
  void insert(ll p,ll m,ll c){
    v.emplace_back(m,c);//switch this up later on...

    if(s==e)return;
    if(p<=(s+e)/2)l->insert(p,m,c);
    else r->insert(p,m,c);
  }
  ll query(ll a,ll b,ll x){
      assert(a<=b);
    ll ans=LLONG_MIN;
    if(a<=s && e<=b){
      for(ll i=0;i<v.size();i++)ans=max(ans,v[i].first*x + v[i].second);
      return ans;
    }
    if(a<=(s+e)/2)ans=max(ans,l->query(a,b,x));
    if((s+e)/2<b)ans=max(ans,r->query(a,b,x));
    return ans;
  }
}*root;

void init(int n, vector<int> T, vector<int> d, vector<int> H){
  ps[0]=leftt[0]=0;
  for(int i=0;i<n;i++)ps[i+1]=ps[i]+T[i];
  for(int i=0;i<n;i++){
    leftt[i+1]=0;
    if(H[i]!=-1)leftt[i+1]=H[i];//nvm, if 2 ppl hate each other can same grp if not leader
  }
  root=new node(0,n);
  dp[0]=0;

  root->insert(0,0,dp[0]-ps[0]);

  for(ll i=2;i<=n;i++){
    //cerr<<i<<' '<<leftt[i]<<' '<<d[i-1]-1<<'\n';
    dp[i]=root->query(leftt[i],d[i-1]-1,T[i-1]);
    dp[i]+=(i*T[d[i-1]-1]) + ps[i] - (i*T[i-1]);
    //+= L*Td + Pi - iTl, L=i, and T,d are 0-indexed...
    root->insert(i,i,dp[i]-ps[i]);
    //j*Tl -Pj + dpj
  }
}

long long combined_ability(int k){
  return dp[k];
}

/*
10 9
7 8 2 10 8 -3 -4 -5 -3 -6
 0  1  2  3  3  5  3  2 6  4
-1 -1 -1 -1 -1 -1 -1 -1 5 -1
2
3
4
5
6
7
8
9
10

13 35 13 19 107 70 127 -11 174
*/