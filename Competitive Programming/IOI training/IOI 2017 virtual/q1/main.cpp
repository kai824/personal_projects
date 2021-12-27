#include<bits/stdc++.h>
using namespace std;

string s[2],r[2];

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    if((i%2)==0)s[0]+=".";
    else s[0]+="X";
  }
  s[1]=s[0];
  swap(s[1][n-1],s[1][n-2]);
  r[0]=s[0];r[1]=s[1];
  reverse(r[0].begin(),r[0].end());
  reverse(r[1].begin(),r[1].end());
  for(int m=1;m*3<=n;m++){
    cout<<s[0]<<'\n';
    for(int i=0;i<n;i++)cout<<'.';cout<<'\n';
    cout<<s[1]<<'\n';
    swap(s,r);
  }
  return 0;
}
