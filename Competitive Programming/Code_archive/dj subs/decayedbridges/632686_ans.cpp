// ans.cpp 7 Dec 19, 10:18:53 100 0.02 Judging completed in 3.622s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[100005],parent[100005],siz[100005];
pair<int,int> edge[100005];

int getr(int x){
	if(parent[x]==-1)return x;
	parent[x]=getr(parent[x]);
	return parent[x];
}
inline ll merge(int a,int b){
	a=getr(a);b=getr(b);
	if(a==b)return 0ll;
	ll tmp=siz[a]*siz[b];
	parent[a]=b;
	siz[b]+=siz[a];
	return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,e;
    cin>>n>>e;
	for(int x=0;x<e;x++){
		cin>>edge[x].first>>edge[x].second;
	}
	for(int x=1;x<=n;x++){
		parent[x]=-1;
		siz[x]=-1;
	}
	ans[e-1]=n*(n-1)/2;
	for(int x=e-2;x>=0;x--){
		ans[x]=ans[x+1]-merge(edge[x+1].first,edge[x+1].second);
	}
	for(int x=0;x<e;x++){
		cout<<ans[x]<<'\n';
	}
    return 0;
}