// ans.cpp 8 Feb 17, 20:20:44 0 2 Judging completed in 9.372s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
bool smaller(string a,string b){//true if a<b, else false
  if(a.length()<b.length())return true;
  if(a.length()>b.length())return false;
  return(a<b);
}
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
string multiply(string a,string b){
  string c="0";
  if(smaller(a,b))swap(a,b);
  for(string x="0";smaller(x,b);x=sum("1",x)){
    c=sum(c,a);
  }
  return c;
}
string ipower(string a,string b){//returns a to the power of b...
  string ans="1";
  for(string x="0";smaller(x,b);x=sum("1",x)){
    ans=multiply(ans,a);
  }
  return ans;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  string a,b;
  cin>>tc;
  for(int x=0;x<tc;x++){
    cin>>a>>b;
    cout<<ipower(a,b)<<endl;
  }
  return 0;
}