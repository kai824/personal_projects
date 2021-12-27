#include<bits/stdc++.h>
using namespace std;
#define int long long
const int b=2,b2=13,mod=1000000007;

int n;

int ft[150000];
#define ls(x) (x&(-x))
void update(int p){
  for(;p<=(1<<n);p+=ls(p))ft[p]++;
}
int query(int p){
  int ans=0;
  for(;p;p-=ls(p))ans+=ft[p];
  return ans;
}

int cnt(vector<int>&v){
  int ans=0;
  for(int i=1;i<=(1<<n);i++)ft[i]=0;
  for(int i=v.size()-1;i>=0;i--){
    ans+=query(v[i]+1);
    update(v[i]+1);
  }
  return ans;
}

typedef pair<int,int> pii;
map<pii,pair<pii,int> > dist;//last move...
int best;
pii hs;
pii hh(vector<int> &v){
  pii ans=make_pair(0,0);
  int a=1,a2=1;
  for(int i=0;i<v.size();i++){
    a*=b;a%=mod;
    a2*=b2;a2%=mod;
    ans.first+=(a*v[i])%mod;
    ans.second+=(a2*v[i])%mod;
  }
  ans.first%=mod;
  ans.second%=mod;
  return ans;
}
int kk;
pii pp;
void dfs(vector<int>&v,pii h){
  kk=cnt(v);
  if(kk<best){
    best=kk;
    hs=h;
  }
  vector<int> v2;

  if(dist[h].second!=1){
    //move 1:
    for(int i=(1<<(n-1));i<(1<<n);i++)v2.emplace_back(v[i]);
    for(int i=0;i<(1<<(n-1));i++)v2.emplace_back(v[i]);
    pp=hh(v2);
    if(dist.find(pp)==dist.end()){
      dist[pp]=make_pair(h,1);
      dfs(v2,pp);
    }
    v2.clear();
  }

  //move 2:
  for(int i=0;i<(1<<n);i+=2)v2.emplace_back(v[i]);
  for(int i=1;i<(1<<n);i+=2)v2.emplace_back(v[i]);
  pp=hh(v2);
  if(dist.find(pp)==dist.end()){
    dist[pp]=make_pair(h,2);
    dfs(v2,pp);
  }
}
void bt(pii x,bool out=true){
  if(dist[x].second==-1)return;
  bt(dist[x].first);
  if(out)cout<<dist[x].second;
}
void ft(pii x){
  if(dist[x].second==-1)return;
  cout<<dist[x].second;
  ft(dist[x].first);
}

void main2(vector<int> &v){
  cout<<"0\n";
  deque<pii> bf1,bf2;
  vector<int> v2=v;
  sort(v2.begin(),v2.end());

  pii h1=hh(v),h2=hh(v2);
  if(h1==h2){
    cout<<"11\n";
    return;
  }
  bf1.push_back(h1);bf2.push_back(h2);
  hh mp=make_pair(-1,-1);
  while(true){
    v2.clear();
  }
  bt(mp,false);
  ft(mp);
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  vector<int> v;
  for(int i=0;i<(1<<n);i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  if(n==0){
    cout<<"0\n2\n";
    return 0;
  }
  if(n>7){main2(v);return 0;}
  best=1e18;hs=hh(v);
  dist[hs]=make_pair(hs,-1);
  dfs(v,hs);
  cout<<best<<'\n';
  bt(hs);
}
