// ans.cpp 18 Dec 19, 17:56:10 73 1.04 Judging completed in 6.202s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int nex[5000005];
bool vis[5000005];

int dfs(int x,int dist){
	vis[x]=true;
	if(vis[nex[x]])return dist;
	return dfs(nex[x],dist+1);
}

ll calc(ll a,ll b){
	return (a/__gcd(a,b))*b;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m;
	long long lcm=1;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>nex[x];
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==false){
			lcm=calc(lcm,dfs(x,1));
		}
	}
	cout<<lcm%m;
    return 0;
}