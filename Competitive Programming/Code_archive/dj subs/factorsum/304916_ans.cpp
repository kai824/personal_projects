// ans.cpp 25 Dec 17, 14:17:52 60 2 Judging completed in 5.849s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
string add(string a,char b,int c){
  if(a.length()-c<=0)a="0"+a;
  int digit=((a[a.length()-c]-'0')+(b-'0'));
  a[a.length()-c]=(digit%10)+'0';
  if(digit/10>=1)a=add(a,(digit/10)+'0',c+1);
  return a;
}
string sum(string a,string b){
  int c=1;
  for(int x=b.length()-1;x>=0;x--){
    a=add(a,b[x],c);
    c++;
  }
  if(a[0]=='0')a.erase(0,1);
  return a;
}
string st(unsigned long long a){
    string ans="";
    while(a>0){
        ans=" "+ans;
        ans[0]=(a%10)+'0';
        a/=10;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    unsigned long long n;
    while(t--){
        cin>>n;
        string ans="0";
        for(unsigned long long x=1;x*x<=n;x++){
            if((n%x)!=0)continue;
            ans=sum(st(x),ans);
            if(x*x==n)continue;
            ans=sum(st(n/x),ans);
        }
        cout<<ans<<'\n';
    }
    return 0;
}