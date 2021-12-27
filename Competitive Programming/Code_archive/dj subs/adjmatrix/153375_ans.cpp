// ans.cpp 22 Oct 16, 15:27:45 70 0 Judging completed in 4.514s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,e,a,b;
	vector<vector <int> >nos;
	cin>>n>>e;
	for(int c=0;c<e;c=c+1){
		vector<int> y;
		for(int d=0;d<n;d++){
		    y.push_back(0);
		}
		nos.push_back(y);
	}
	for(int c=0;c<e;c=c+1){
		cin>>a>>b;
		nos[a-1][b-1]=1;
		nos[b-1][a-1]=1;
	}
	for(int d=0;d<n;d=d+1){
	for(int c=0;c<n;c=c+1){
		cout<<nos[d][c];
		if(nos[d].size()-c==1) cout<<"\n";
	}
}
	return 0;
}