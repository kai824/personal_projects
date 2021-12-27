// ans.cpp 15 Apr 17, 20:11:20 80 0 Judging completed in 3.756s on AWS Oregon.
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
int main() {
    string a;
    cin>>a;
    if(isalpha(a[0])){
        for(int x=0;x<a.length();x++){
            a[x]=toupper(a[x]);
        }
    }else{
        a=sum(a,a);
    }
    cout<<a;
    return 0;
}