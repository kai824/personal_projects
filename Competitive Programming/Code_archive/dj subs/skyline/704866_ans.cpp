// ans.cpp 24 Feb 20, 14:06:06 100 0.42 Judging completed in 5.559s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

map<pair<int,int>,int> mp;

int n,a,b,nex;
int ans[500005];

void recurse(int l,int r){
  int c;
  a=l;b=r;
  if(a==0)a=-1;
  if(b==n+1)b=-1;
  c=mp[make_pair(a,b)];
  ans[c]=nex;nex--;
  if(c+1<r){
    recurse(c,r);
  }
  if(l+1<c){
    recurse(l,c);//range not empty...
  }
}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n;
  nex=n;
  for(int x=0;x<n;x++){
    cin>>a>>b;
    mp[make_pair(a,b)]=x+1;
  }
  recurse(0,n+1);
  for(int x=1;x<=n;x++){
    cout<<ans[x];
    if(x<n)cout<<' ';
    else cout<<'\n';
  }
  return 0;
}