// ans.cpp 14 Jun 18, 10:57:30 100 0 Judging completed in 2.747s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m,k,z,limit;
	long long t=1;
	string a,b="",c;
	cin>>m>>m>>k>>z;
	limit=-1;
	z--;
	cin>>a;
	for(int x=1;x<=m;x++){
		t*=k;
		if(t>1000000000){
			limit=m-x;
			break;
		}
	}
	for(int x=0;x<m;x++){
		if(x>=limit)t/=(k);
		cin>>c;
		sort(c.begin(),c.end());
		b+=" ";
		b[x]=c[z/t];
		if(x>=limit)z%=t;
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