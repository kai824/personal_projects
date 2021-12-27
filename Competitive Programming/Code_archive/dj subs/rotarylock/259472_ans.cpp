// ans.cpp 17 Nov 17, 16:59:24 0 0.02 Judging completed in 14.798s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll ft[1000005],n,q,k,a,b,c;
ll ls(ll x){
	return(x & (-x));
}
ll query(ll p) {
	ll sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(ll p,ll v) {
    v%=k;
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
		ft[p]%=k;
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>q>>k;
	k=1<<k;
	int arr[q];
	for(ll x=0;x<q;x++){
	    arr[q]=q-x;
	}
	stable_sort(arr,arr+q);
	return 0;
}