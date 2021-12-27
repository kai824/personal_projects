// ans.cpp 1 Feb 20, 10:22:17 24 1 Judging completed in 5.945s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")

typedef long long ll;

ll arr[300005],ps[300005],cur_max;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,ans=0;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		cin>>arr[x];
		ps[x]=ps[x-1]+arr[x];
	}
	for(int x=1;x<=n;x++){
		cur_max=arr[x];
		for(int y=x+1;y<=n;y++){
			cur_max=max(cur_max,arr[y]);
			if(((ps[y]-ps[x-1]-cur_max)%m)==0)ans++;
		}
	}
	cout<<ans;
	return 0;
}