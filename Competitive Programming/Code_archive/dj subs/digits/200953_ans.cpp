// ans.cpp 16 Mar 17, 22:33:29 13 2 Judging completed in 8.417s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
long long mypow(long long y){
	long long ans=1;
	for(long long x=0;x<y;x++){
		ans*=2;
	}
	return ans;
}
string add(string a,char b,long long c){
  if(a.length()-c<=0)a="0"+a;
  long long digit=((a[a.length()-c]-'0')+(b-'0'));
  a[a.length()-c]=(digit%10)+'0';
  if(digit/10>=1)a=add(a,(digit/10)+'0',c+1);
  return a;
}
string sum(string a,string b){
  long long c=1;
  for(long long x=b.length()-1;x>=0;x--){
    a=add(a,b[x],c);
    c++;
  }
  if(a[0]=='0')a.erase(0,1);
  return a;
}
string times(long long a,long long b){
	a*=b;
	string ans="";
	while(a>0){
		ans=" "+ans;
		ans[0]=(a%10)+'0';
		a/=10;
	}
	return ans;
}
string multiply(string a,string b){
	string current,ans="";
	if(a.length()>b.length()){
		swap(a,b);
	}
	for(long long x=0;x<a.length();x++){
		current="";
		for(long long y=0;y<b.length();y++){
			current=sum(current+"0",times(a[x]-'0',b[y]-'0'));
		}
		ans=sum(ans+"0",current);
	}
	return ans;
}
string spow(string a,long long b){
	string ans="1",current;
	for(long long x=62;(x>=0 && b>0);x--){
		if(mypow(x)>b)continue;
		current=a;
		for(long long y=0;y<x;y++){
			current=multiply(current,current);
		}
		ans=multiply(ans,current);
		b-=mypow(x);
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a;
	long long b,tc;
	cin>>tc;
	for(int x=0;x<tc;x++){
		cin>>a>>b;
		cout<<spow(a,b).length()<<endl;
	}
	return 0;
}