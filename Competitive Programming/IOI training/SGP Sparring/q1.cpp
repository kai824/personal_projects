#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxn=500005;

int last[mxn],rig[mxn];
int b[mxn],c[mxn];
int m;

void funny(int n){
  int sf[n+1];
  sf[n]=b[n];
  for(int i=n-1;i>=1;i--){//suffix max the prefix sum...
    sf[i]=max(sf[i+1],b[i]);
  }
  int ans=LLONG_MIN;
  for(int i=1;i<=n;i++){
    ans=max(ans,sf[i]-b[i-1]);
  }
  ans+=m;
  cout<<ans<<'\n';
}

struct L{
  mutable int m,c,p;
  bool operator<(const L&o) const {return m<o.m;}//max cht...
  bool operator<(int x)const{return p<x;}
};
#define inf LLONG_MAX
#define ite iterator
struct lc:multiset<L,less<> >{
  int div(int a,int b){
    return a/b - ((a^b)<0 && (a%b));
  }
  bool isect(ite x,ite y){
    if(y==end()){
      x->p=inf;
      return false;
    }
    if(x->m==y->m){
      if(x->c>=y->c){
        x->p=inf;
      }else x->p=-inf;
    }else{
      x->p=div(x->c-y->c,y->m-x->m);
    }
    return (x->p>=y->p);
  }
  void add(int m,int c){
    ite z=insert({m,c,0}),x,y;
    x=y=z++;
    while(isect(y,z))z=erase(z);
    if(x==begin())return;
    --x;
    if(isect(x,y)){
      isect(x,y=erase(y));
      return;
    }
    while((y=x)!=begin() && isect(--x,y)){
      isect(x,erase(y));
    }
  }
  int query(int x){
    ite it=lower_bound(x);
    return it->m*x+it->c;
  }
} hull;

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n;
  cin>>n>>m;//m=multiplier
  for(int i=1;i<=n;i++){
    cin>>c[i]>>b[i];
    b[i]+=b[i-1];//prefix sum :)
  }
  if(c[n]==1){
    funny(n);
    return 0;
  }
  //toxic problem moment...
  int ans=LLONG_MIN;
  for(int i=n-1;i>=0;i--){
    hull.add(-2*m*(i+1),b[i+1]+((i+1)*(i+1)*m));
    ans=max(ans,hull.query(i)+(i*i*m)-b[i]);
  }
  cout<<ans<<'\n';
  return 0;
}
