// ans.cpp 24 Nov 20, 19:49:59 0 17 Judging completed in 23.476s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3

typedef long long ll;
ll n,sum[16],arr[16][2],j,k;

#define process(x) (64-__builtin_clzll(x)-1)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<16;x++){
        cin>>arr[x][0];
        //cout<<long_computation(arr[x]);
		sum[x]=arr[x][0];
    }
	for(int i=1;i<n;i++){
		j=i%2;
		k=1-j;
		for(int x=0;x<16;x++)arr[x][j] = ((arr[x][k]% 1000000007) * (arr[x][k]% 1000000007)) % 1000000007;
		for(int x=0;x<16;x++)arr[x][j] = ( (arr[x][j]% 1000000007) * process(arr[x][j]) ) % 1000000007;
		for(int x=0;x<16;x++)arr[x][j] = (arr[x][j]% 1000000007) * ((((arr[x][k]% 1000000007) + (arr[x][j]% 1000000007)) * ((arr[x][j]% 1000000007) + (arr[x][k]% 1000000007)))% 1000000007);
		for(int x=0;x<16;x++)arr[x][j] %= 1000000007;
	
		for(int x=0;x<16;x++)sum[x] += arr[x][j];
	}
	for(int i=0;i<15;i++){
		cout<<sum[i]<<' ';
	}cout<<sum[15];
    return 0;
}