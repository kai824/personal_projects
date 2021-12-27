// ans.cpp 28 Dec 16, 12:40:38 100 0 Judging completed in 3.83s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,e,a,b;
	vector<vector <int> >nos;
	cin>>n>>e;
	for(int c=0;c<n;c=c+1){
		vector<int> y;
		nos.push_back(y);
	}
	for(int c=0;c<e;c=c+1){
		cin>>a>>b;
		(nos[a-1]).push_back(b);
		(nos[b-1]).push_back(a);
	}
	for(int d=0;d<n;d=d+1){
	    if(nos[d].size()==0) cout<<"\n";
	for(int c=0;c<nos[d].size();c=c+1){
		cout<<nos[d][c];
		if(nos[d].size()-c==1) cout<<"\n";
		else cout<<" ";
	}
}
	return 0;
}