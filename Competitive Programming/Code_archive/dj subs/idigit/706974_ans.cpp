// ans.cpp 29 Feb 20, 13:19:49 17 1 Judging completed in 4.472s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define mp make_pair
#define int unsigned long long//learning from chur zhe
#define pii pair<int,int>

int tc,n,x,s,a,mm;
int arr[10];
string cur="";

bool brute_force(int d,int mod){//no. of digits alr completed, cur mod
  if(d==n){
    return (mod==x);
  }
  mod*=10;
  for(int i=0;i<s;i++){
    cur[d]='0'+arr[i];
    if(brute_force(d+1,(mod+arr[i])%(1LL<<n)))return true;
  }
  return false;
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>tc;
  while(tc--){
    cin>>n>>x>>s;
    cur="";
    for(int i=0;i<n;i++)cur+=" ";
    for(int i=0;i<s;i++)cin>>arr[i];
    if(s<=2){
      if(brute_force(0,0))cout<<cur<<'\n';
      else cout<<"-1\n";
    }
  }
  return 0;
}