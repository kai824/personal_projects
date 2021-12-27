// ans.cpp 26 Nov 20, 00:11:55 100 15.65 Judging completed in 22.354s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

typedef long long ll;
ll n,sum[16],arr[2][16],j,k;

#define process(x) (63-__builtin_clzll(x))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int x=0;x<16;x++){
        cin>>arr[0][x];
        arr[0][x]%=1000000007;
        //cout<<long_computation(arr[x]);
		sum[x]=arr[0][x];
    }
	for(int i=1;i<n;i++){
		j=i%2;
		k=1-j;
               arr[j][0] = (arr[k][0] * arr[k][0]) % 1000000007;
               arr[j][1] = (arr[k][1] * arr[k][1]) % 1000000007;
               arr[j][2] = (arr[k][2] * arr[k][2]) % 1000000007;
               arr[j][3] = (arr[k][3] * arr[k][3]) % 1000000007;
               arr[j][4] = (arr[k][4] * arr[k][4]) % 1000000007;
               arr[j][5] = (arr[k][5] * arr[k][5]) % 1000000007;
               arr[j][6] = (arr[k][6] * arr[k][6]) % 1000000007;
               arr[j][7] = (arr[k][7] * arr[k][7]) % 1000000007;
               arr[j][8] = (arr[k][8] * arr[k][8]) % 1000000007;
               arr[j][9] = (arr[k][9] * arr[k][9]) % 1000000007;
               arr[j][10] = (arr[k][10] * arr[k][10]) % 1000000007;
               arr[j][11] = (arr[k][11] * arr[k][11]) % 1000000007;
               arr[j][12] = (arr[k][12] * arr[k][12]) % 1000000007;
               arr[j][13] = (arr[k][13] * arr[k][13]) % 1000000007;
               arr[j][14] = (arr[k][14] * arr[k][14]) % 1000000007;
               arr[j][15] = (arr[k][15] * arr[k][15]) % 1000000007;

               arr[j][0] = ( arr[j][0] * process(arr[j][0]) ) % 1000000007;
               arr[j][1] = ( arr[j][1] * process(arr[j][1]) ) % 1000000007;
               arr[j][2] = ( arr[j][2] * process(arr[j][2]) ) % 1000000007;
               arr[j][3] = ( arr[j][3] * process(arr[j][3]) ) % 1000000007;
               arr[j][4] = ( arr[j][4] * process(arr[j][4]) ) % 1000000007;
               arr[j][5] = ( arr[j][5] * process(arr[j][5]) ) % 1000000007;
               arr[j][6] = ( arr[j][6] * process(arr[j][6]) ) % 1000000007;
               arr[j][7] = ( arr[j][7] * process(arr[j][7]) ) % 1000000007;
               arr[j][8] = ( arr[j][8] * process(arr[j][8]) ) % 1000000007;
               arr[j][9] = ( arr[j][9] * process(arr[j][9]) ) % 1000000007;
               arr[j][10] = ( arr[j][10] * process(arr[j][10]) ) % 1000000007;
               arr[j][11] = ( arr[j][11] * process(arr[j][11]) ) % 1000000007;
               arr[j][12] = ( arr[j][12] * process(arr[j][12]) ) % 1000000007;
               arr[j][13] = ( arr[j][13] * process(arr[j][13]) ) % 1000000007;
               arr[j][14] = ( arr[j][14] * process(arr[j][14]) ) % 1000000007;
               arr[j][15] = ( arr[j][15] * process(arr[j][15]) ) % 1000000007;

               arr[k][0]+=arr[j][0];
               arr[k][1]+=arr[j][1];
               arr[k][2]+=arr[j][2];
               arr[k][3]+=arr[j][3];
               arr[k][4]+=arr[j][4];
               arr[k][5]+=arr[j][5];
               arr[k][6]+=arr[j][6];
               arr[k][7]+=arr[j][7];
               arr[k][8]+=arr[j][8];
               arr[k][9]+=arr[j][9];
               arr[k][10]+=arr[j][10];
               arr[k][11]+=arr[j][11];
               arr[k][12]+=arr[j][12];
               arr[k][13]+=arr[j][13];
               arr[k][14]+=arr[j][14];
               arr[k][15]+=arr[j][15];

               arr[k][0]*=arr[k][0];
               arr[k][1]*=arr[k][1];
               arr[k][2]*=arr[k][2];
               arr[k][3]*=arr[k][3];
               arr[k][4]*=arr[k][4];
               arr[k][5]*=arr[k][5];
               arr[k][6]*=arr[k][6];
               arr[k][7]*=arr[k][7];
               arr[k][8]*=arr[k][8];
               arr[k][9]*=arr[k][9];
               arr[k][10]*=arr[k][10];
               arr[k][11]*=arr[k][11];
               arr[k][12]*=arr[k][12];
               arr[k][13]*=arr[k][13];
               arr[k][14]*=arr[k][14];
               arr[k][15]*=arr[k][15];

               arr[j][0] *= arr[k][0]% 1000000007;
               arr[j][1] *= arr[k][1]% 1000000007;
               arr[j][2] *= arr[k][2]% 1000000007;
               arr[j][3] *= arr[k][3]% 1000000007;
               arr[j][4] *= arr[k][4]% 1000000007;
               arr[j][5] *= arr[k][5]% 1000000007;
               arr[j][6] *= arr[k][6]% 1000000007;
               arr[j][7] *= arr[k][7]% 1000000007;
               arr[j][8] *= arr[k][8]% 1000000007;
               arr[j][9] *= arr[k][9]% 1000000007;
               arr[j][10] *= arr[k][10]% 1000000007;
               arr[j][11] *= arr[k][11]% 1000000007;
               arr[j][12] *= arr[k][12]% 1000000007;
               arr[j][13] *= arr[k][13]% 1000000007;
               arr[j][14] *= arr[k][14]% 1000000007;
               arr[j][15] *= arr[k][15]% 1000000007;

               arr[j][0] %= 1000000007;
               arr[j][1] %= 1000000007;
               arr[j][2] %= 1000000007;
               arr[j][3] %= 1000000007;
               arr[j][4] %= 1000000007;
               arr[j][5] %= 1000000007;
               arr[j][6] %= 1000000007;
               arr[j][7] %= 1000000007;
               arr[j][8] %= 1000000007;
               arr[j][9] %= 1000000007;
               arr[j][10] %= 1000000007;
               arr[j][11] %= 1000000007;
               arr[j][12] %= 1000000007;
               arr[j][13] %= 1000000007;
               arr[j][14] %= 1000000007;
               arr[j][15] %= 1000000007;

               sum[0] += arr[j][0];
               sum[1] += arr[j][1];
               sum[2] += arr[j][2];
               sum[3] += arr[j][3];
               sum[4] += arr[j][4];
               sum[5] += arr[j][5];
               sum[6] += arr[j][6];
               sum[7] += arr[j][7];
               sum[8] += arr[j][8];
               sum[9] += arr[j][9];
               sum[10] += arr[j][10];
               sum[11] += arr[j][11];
               sum[12] += arr[j][12];
               sum[13] += arr[j][13];
               sum[14] += arr[j][14];
               sum[15] += arr[j][15];
	}
	for(int i=0;i<15;i++){
		cout<<sum[i]<<' ';
	}cout<<sum[15];
    return 0;
}//1 4732602024 6148672003