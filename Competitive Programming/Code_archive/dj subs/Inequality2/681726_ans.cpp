// ans.cpp 18 Jan 20, 16:13:39 27 3.02 Judging completed in 7.662s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool active[500005];
ll parent[500005];
ll    siz[500005];

ll getr(ll x){
	if(parent[x]==-1)return x;
	parent[x]=getr(parent[x]);
	return parent[x];
}
inline void merge(ll a,ll b){
	a=getr(a);b=getr(b);
	if(a==b)return;
	parent[a]=b;//make b the new root...
	siz[b]+=siz[a];siz[a]=0;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,prev,b=0,ans,l,r;
	cin>>n;
	ll arr[n];
	pair<ll,ll> tmp[n];
	for(ll x=0;x<n;x++){
		cin>>arr[x];
	}
	for(ll x=0;x<=n;x++){
		if(x>0 && b==0){
			cout<<prev<<'\n';
			if(x<n){
				cin>>b;
				arr[x]+=b;
			}
			continue;
		}
		
		for(ll x=0;x<n;x++){
			parent[x]=-1;
			active[x]=false;
			siz[x]=1;
			tmp[x].first=arr[x];
			tmp[x].second=x;
		}
		sort(tmp,tmp+n);
		ans=0;
		for(ll x=0;x<n;x++){
			active[tmp[x].second]=true;
			l=r=0;
			if(tmp[x].second>0 && active[tmp[x].second-1]){
				l=siz[getr(tmp[x].second-1)];
			}
			
			if(tmp[x].second+1<n && active[tmp[x].second+1]){
				r=siz[getr(tmp[x].second+1)];
			}
			
			if(tmp[x].second>0 && active[tmp[x].second-1]){
				merge(tmp[x].second,tmp[x].second-1);
			}
			
			if(tmp[x].second+1<n && active[tmp[x].second+1]){
				merge(tmp[x].second,tmp[x].second+1);
			}
			
			ans+=(l+1)*(r+1)*tmp[x].first;
		}
		prev=ans;
		cout<<prev<<'\n';
		if(x<n){
			cin>>b;
			arr[x]+=b;
		}
	}
	return 0;
}

/*
4
5 7 10 9
3 4 5 7
*/