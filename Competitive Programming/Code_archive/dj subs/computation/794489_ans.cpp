// ans.cpp 25 Nov 20, 23:58:08 0 10.73 Judging completed in 16.723s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

typedef long long ll;
ll n,arr[2][16],j,k;
unsigned long long sum[16];

#define process(x) (64-__builtin_clzll(x)-1)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<16;x++){
        cin>>arr[0][x];
        //cout<<long_computation(arr[x]);
		sum[x]=arr[0][x];
    }
	for(int i=1;i<n;i++){
		j=i%2;
		k=1-j;
		for(int x=0;x<16;x++)arr[j][x] = (arr[k][x] * arr[k][x]) % 1000000007;
		for(int x=0;x<16;x++)arr[j][x] = ( arr[j][x] * process(arr[j][x]) ) % 1000000007;

		for(int x=0;x<16;x++)arr[k][x]+=arr[j][x];
		for(int x=0;x<16;x++)arr[k][x] %= 1000000007;
		for(int x=0;x<16;x++)arr[k][x]*=arr[k][x];
		for(int x=0;x<16;x++)arr[k][x] %= 1000000007;

		for(int x=0;x<16;x++)arr[j][x] *= arr[k][x];
		for(int x=0;x<16;x++)arr[j][x] %= 1000000007;
	
		for(int x=0;x<16;x++)sum[x] += arr[j][x];
	}
	for(int i=0;i<15;i++){
		cout<<sum[i]<<' ';
	}cout<<sum[15];
    return 0;
}//1 4732602024 6148672003