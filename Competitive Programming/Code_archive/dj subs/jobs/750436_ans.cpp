// ans.cpp 24 Jul 20, 14:19:00 0 0.05 Judging completed in 3.889s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int match[2010];
bool vis[2010];
vector<int>v[2010];
int aug(int l){
	if (vis[l])return 0;
	vis[l]=1;
	for (int i=0;i<v[l].size();i++){
		int r=v[l][i];
		if (match[r]==-1/*||aug(match[r])*/){
			match[r]=l;
			return 1;
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n,m,i,x,y,i1,mcbm=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		for (i1=0;i1<m;i1++){
			cin>>x;
			if (x==1){
				v[i].push_back(i1+1000);
			}
		}
	}
	for (i=0;i<2010;i++){
		match[i]=-1;
	}
	for (i=0;i<n;i++){
		for (i1=0;i1<2010;i1++){
			vis[i1]=0;
		}
		mcbm+=aug(i);
	}
	cout<<mcbm<<'\n';
    
}