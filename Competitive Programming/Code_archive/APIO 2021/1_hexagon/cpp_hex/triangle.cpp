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
const int ang[7]={0,0,1,2,4,5,6};//* pi/4

int draw_territory(int n, int a, int b,vector<int> d, vector<int> l){
  assert(n==3);
  int it=-1;
  ll ans=0,len,sum=0;
  len=l[0]+1;
  ans=len*(len+1ll)/2ll;
  ans%=mod;
  ans*=a;ans%=mod;
  for(ll i=2;i<=len;i++){
    sum+=(i-1)*i;
    sum%=mod;
  }
  ans+=sum*b;
  ans%=mod;
  return ans;
}
