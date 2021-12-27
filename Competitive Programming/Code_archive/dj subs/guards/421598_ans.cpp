// ans.cpp 25 Nov 18, 18:50:29 0 0 Compilation failed on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[3005][8005],ps[8005],cur;
void dnc(ll l, ll r, ll s, ll e){
	if(l>=r)return ps[l]-ps[l-1];
	ll mid=(l+r)/2,best_it=-1;
	arr[cur][mid]=LLONG_MAX;
	for(ll x=s;x<=min(e,mid-1);x++){
		arr[cur][mid]=min(arr[cur][mid],arr[cur-1][mid]+ ((ps[mid]-ps[x])*(mid-x)) );
	}
	dnc(l,mid-1,s,arr[cur][mid]);
	dnc(mid+1,r,arr[cur][mid],e);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,g,a;
	cin>>n>>g;
	for(ll x=1;x<=n;x++){
		cin>>a;
		ps[x]=ps[x-1]+a;
	}
	for(ll x=1;x<=n;x++){//when only 1 guard used...
		arr[1][x]=x*ps[x];
	}
	for(ll x=2;x<=g;x++){
		cur=x;
		dnc(1,n,1,n);//search range, valid range...
		for(ll y=1;y<=n;y++){
			
			arr[x][y]=LLONG_MAX;
			for(ll z=x-1;z<y;z++){
				arr[x][y]=min(arr[x][y],arr[x-1][z]+((ps[y]-ps[z])*(y-z)));
			}
		}
	}
	cout<<arr[g][n];
	return 0;
}