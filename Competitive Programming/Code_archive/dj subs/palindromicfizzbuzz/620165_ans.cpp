// ans.cpp 2 Dec 19, 10:46:00 100 0.02 Judging completed in 3.839s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
inline string ss(ll b){
  string ans="";
  while(b>0){
    ans+=" ";
    ans[ans.length()-1]='0'+(b%10LL);
    b/=10LL;
  }
  return ans;
}
inline bool is_palindrome(ll b){
  string a=ss(b);
  for(ll x=0;x<a.length()/2;x++){
        if(a[x]!=a[a.length()-1-x]){
            return false;
        }
    }
	return true;
}
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  ll s,e;
  cin>>s>>e;
  for(ll x=s;x<=e;x++){
    if(is_palindrome(x)){
      cout<<"Palindrome!\n";
      continue;
    }else cout<<x<<'\n';
  }
  return 0;
}