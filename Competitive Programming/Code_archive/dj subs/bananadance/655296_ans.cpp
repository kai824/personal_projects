// ans.cpp 18 Dec 19, 17:58:32 0 0 Compilation failed on AWS Oregon.
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
	int128_t a;
    return 0;
}