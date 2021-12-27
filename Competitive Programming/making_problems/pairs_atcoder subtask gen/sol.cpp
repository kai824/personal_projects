#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/

typedef long long ll;

ll arr[200005];
ll n,k,ans;

ll less_count(ll a){
	//returns number of pairs with sum less than k
	ans=0;
	ll lo,hi,mid;
	for(int x=0;x+1<n;x++){
		if(arr[x]*arr[x+1]>=a && arr[x]*arr[n-1]>=a)continue;//no point to continue increasing...
		if(arr[x]==0){
			ans+=(n-x-1);
			continue;
		}
		lo=x+1;hi=n-1;
		lo-=x;hi-=x;
		while(lo<hi){
			mid=hi-((hi-lo)/2);
			if(arr[x]<0){
				if(arr[x]*arr[n-mid]<a){
					lo=mid;
				}else hi=mid-1;
			}else{
				if(arr[x]*arr[mid+x]<a){
					lo=mid;
				}else hi=mid-1;
			}
		}
		ans+=lo;
	}
	return ans;
}

int main(int argc, char *argv[]){
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen (argv[1],"r",stdin);
	freopen (argv[2],"w",stdout);
	cin>>n>>k;
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	sort(arr,arr+n);
	ll lo,hi,mid;
	lo=-1e18;
	hi=1e18;

	//we want less_count of answer to be between at most k-1...
	while(lo<hi){
		mid=hi-(hi-lo)/2;
		if(less_count(mid)<k){
			lo=mid;
		}else{
			hi=mid-1;
		}
	}
	cout<<lo<<'\n';
	return 0;
}
