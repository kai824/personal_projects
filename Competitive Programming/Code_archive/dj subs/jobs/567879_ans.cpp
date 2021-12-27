// ans.cpp 25 Oct 19, 18:17:06 0 0.39 Judging completed in 4.094s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int match[1010];
bool vis[1010];
vector<int>v[1010];
int aug(int l){
	if (vis[l])return 0;
	vis[l]=1;
	for (int i=0;i<v[l].size();i++){
		int r=v[l][i];
		if (match[r]==-1||aug(match[r])){
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
				v[i].push_back(i1);
			}
		}
	}
	for (i=0;i<n;i++){
		match[i]=-1;
	}
	for (i=0;i<n;i++){
		for (i1=0;i1<n;i1++){
			vis[i1]=0;
		}
		mcbm+=aug(i);
	}
	cout<<mcbm<<'\n';
    
}