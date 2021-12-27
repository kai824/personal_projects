// ans.cpp 24 Nov 18, 15:40:51 53 2 Judging completed in 5.498s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,g,a;
	cin>>n>>g;
	ll arr[g+1][n+1];
	ll ps[n+1];
	ps[0]=0;
	for(ll x=1;x<=n;x++){
		cin>>a;
		ps[x]=ps[x-1]+a;
	}
	for(ll x=1;x<=n;x++){//when only 1 guard used...
		arr[1][x]=x*ps[x];
	}
	for(ll x=2;x<=g;x++){
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