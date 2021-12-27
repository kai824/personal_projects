// kindergarten.cpp 9 Aug 20, 16:13:20 100 0.96 Judging completed in 10.822s on AWS Oregon.
#include "kindergarten.h"
#include"bits/stdc++.h"
using namespace std;

#define maxn 300005
#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;
#define inter(a,b) ( double(a.second-b.second)/double(b.first-a.first) )

//arrays are 1-indexed, but not the vectors given :(
ll ps[maxn],dp[maxn],lo,hi,mid;
int leftt[maxn];//the rightmost person you cannot include...


struct node{//segtree[i] stores the line you get if you end prev team at i, and take next team from i+1 onwards
  ll s,e;
  vector<pair<double,pii> > v;
  //all the lines, x-intercept, m,c...
  //m is always increasing
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
    while(v.size()>=2 && inter(v[v.size()-2].second,mp(m,c))<=v.back().first ){
      v.pop_back();
    }
    if(v.size()==0)v.emplace_back(-1e10,mp(m,c) );
    else v.emplace_back(inter(v.back().second,mp(m,c)),mp(m,c) );

    if(s==e)return;
    if(p<=(s+e)/2)l->insert(p,m,c);
    else r->insert(p,m,c);
  }
  ll query(ll a,ll b,ll x){
      assert(a<=b);
    ll ans=LLONG_MIN;
    if(a<=s && e<=b){
      if(v.size()==0)return LLONG_MIN;
      lo=0;hi=v.size()-1;
      while(lo<hi){
        mid=hi-((hi-lo)/2);
        if(v[mid].first<=x)lo=mid;
        else hi=mid-1;//v[mid]>x
      }
      return v[lo].second.first*x + v[lo].second.second;
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
    if(dp[i]==LLONG_MIN){
        dp[i]=-1;//not possible to form teams, don't fake news to future dps
        continue;
    }
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