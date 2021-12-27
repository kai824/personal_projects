// ans.cpp 18 Dec 19, 18:07:22 0 1.03 Judging completed in 6.904s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

#pragma O3

typedef __int128 ll;

int nex[5000005];
bool vis[5000005];

int dfs(int x,int dist){
	vis[x]=true;
	if(vis[nex[x]])return dist;
	return dfs(nex[x],dist+1);
}

inline ll gcd(ll a,ll b){
    while(b)b ^=a^=a%=b;
    return a;
}

inline ll calc(ll a,ll b){
	return (a/gcd(a,b))*b;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m;
	ll lcm=1;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>nex[x];
	}
	for(int x=1;x<=n;x++){
		if(vis[x]==false){
			lcm=calc(lcm,dfs(x,1));
		}
	}
	cout<<(long long)(lcm%m);
    return 0;
}