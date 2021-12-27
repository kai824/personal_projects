// ans.cpp 18 Jun 18, 11:04:11 100 0 Judging completed in 3.666s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,b,c,ans=0,maxi=-1,d,e;
	string a,bb;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>a;
		cin>>b>>c;
		d=0;
		while(b<=c){
			e=c/b;
			d+=e;
			c%=b;
			c+=2*e;
		}
		if(d>maxi){
			maxi=d;
			bb=a;
		}
		ans+=d;
	}
	cout<<ans<<'\n'<<bb;
	return 0;
}