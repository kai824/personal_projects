// ans.cpp 19 Dec 19, 10:41:34 73 1.04 Judging completed in 6.786s on AWS Oregon.
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
    if(a<b)swap(a,b);
    if(b==0)return a;
    return __gcd((long long)b,(long long)(a%b));
}

inline ll calc(ll a,ll b){
	return (a/gcd(a,b))*b;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	long long n,m;
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