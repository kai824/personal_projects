// ans.cpp 3 Jun 17, 20:59:45 0.01 0.05 Judging completed in 4.479s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(int n){
	cin>>n;
	for(int x=1;x<=n;x++){
		for(int y=1;y<x;y++){
			cout<<y<<' ';
		}
		cout<<x<<'\n';
	}
}