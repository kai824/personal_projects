#include "hexagon.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;

const ll mod=1000000007;
const int xx[7]={0,1,1,0,-1,-1,0};
const int yy[7]={0,0,1,1,0,-1,-1};
int ang[7]={0,0,1,2,4,5,6};//* pi/4 useless

const bool debug=false;

ll exp(ll a,ll b){
  ll ans=1;
  while(b>0){
    if(b%2){
      ans*=a;
      ans%=mod;
    }
    b/=2;
    a*=a;
    a%=mod;
  }
  return ans;
}

ll ans=0;
long double kek=0;
int draw_territory(int n, int A, int B,vector<int> d, vector<int> l){//direction, length
  ll a=A,b=B,sep=0,sep2=0,tt;
  ll half=exp(2,mod-2);
  pii cur=mp(0,0);//x y
  vector<pii> points;
  points.pb(cur);
  for(int i=0;i<n;i++){
    cur.f+=xx[d[i]]*l[i];
    cur.s+=yy[d[i]]*l[i];
    points.pb(cur);

    if(d[i]==2||d[i]==5){
      sep+=(l[i]-1)*half;
      sep%=mod;
    }else{
      sep+=(l[i]-1);
      sep%=mod;
    }

    tt=(0-ang[d[(i+1)%n]]+ang[d[i]]+8)%8;//tmp variable
    sep2+=tt;//counts the number of 1/8 pieces...
  }
  if(debug){
      cout<<"debug begins\n";
    for(int i=0;i<points.size();i++){
      cout<<points[i].f<<' '<<points[i].s<<'\n';
    }
  }
  for(int i=0;i+1<points.size();i++){
    kek+=points[i].f*points[i+1].s;
    ans+=points[i].f*points[i+1].s;
    ans%=mod;
    kek-=points[i].s*points[i+1].f;
    ans-=points[i].s*points[i+1].f;
    ans%=mod;
  }
  if(kek<0){
    ans=-ans;
    sep2=n*8-sep2;
  }
  if(debug)cout<<ans<<'\n';
  if(ans<0)ans+=mod;
  ans+=sep;
  ans+=(sep2*exp(4,mod-2))%mod;
  ans*=exp(2,mod-2);
  ans%=mod;

  if(debug)cout<<kek<<' '<<sep<<' '<<sep2<<'\n';
  ans+=2;
  ans*=a;ans%=mod;
  return ans;
}
/*
17 1 0
1 1
2 2
3 2
4 1
5 1
4 1
3 1
2 2
1 3
6 2
2 3
3 1
4 6
5 3
6 3
6 2
1 1
*/
