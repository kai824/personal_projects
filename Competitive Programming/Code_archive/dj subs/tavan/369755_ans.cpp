// ans.cpp 14 Jun 18, 10:48:11 60 0 Judging completed in 2.92s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m,k,z,t=1;
	string a,b="",c;
	cin>>m>>m>>k>>z;
	z--;
	cin>>a;
	for(int x=1;x<=m;x++){
		t*=k;
	}
	for(int x=0;x<m;x++){
		t/=(k);
		cin>>c;
		sort(c.begin(),c.end());
		b+=" ";
		b[x]=c[z/t];
		z%=t;
	}
	t=0;
	for(int x=0;x<a.length();x++){
		if(a[x]!='#')continue;
		a[x]=b[t];
		t++;
	}
	cout<<a;
	return 0;
}