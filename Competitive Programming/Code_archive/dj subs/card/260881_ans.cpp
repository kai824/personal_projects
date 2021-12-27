// ans.cpp 18 Nov 17, 14:21:27 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;
int x[100005],y[100005];
int ps_x[100005],ps_y[100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<pair<int,int>,bool> mp;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		mp[make_pair(x,y)]=true;
	}
	sort(x+1,x+n+1);sort(y,y+n+1);
	for(int i=1;i<=n;i++){
		ps_x[i]=ps_x[i-1]+x[i];
		ps_y[i]=ps_y[i-1]+y[i];
		//prefix sum them...
	}
	cin>>m;
	for(int x=0;x<m;x++){
		//queries
		//NOT COMPLETED HERE...
		cin>>a>>b;
		
	}
    return 0;
}