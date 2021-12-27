// ans.cpp 10 May 17, 14:22:32 100 0 Judging completed in 9.918s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,a;
	string b="";
	cin>>n;
	a=n;
	for(int x=(n-1)*2;x>0;x-=2){
		for(int y=0;y<x;y++){
			cout<<' ';
		}
		for(int y=0;y<a;y++){
			cout<<'*';
		}
		cout<<'\n';
		a+=4;
	}
	for(int y=0;y<a;y++){
		b+="*";
	}
	b+="\n";
	for(int x=0;x<n;x++){
		cout<<b;
	}
	for(int x=2;x<=(n-1)*2;x+=2){
		a-=4;
		for(int y=0;y<x;y++){
			cout<<' ';
		}
		for(int y=0;y<a;y++){
			cout<<'*';
		}
		cout<<'\n';
	}
	return 0;
}