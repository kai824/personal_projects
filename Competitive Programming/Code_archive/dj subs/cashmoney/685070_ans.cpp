// ans.cpp 24 Jan 20, 17:27:30 0 1.25 Judging completed in 6.619s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
typedef __int128 ll;

ll mod=1e9+12;
ll h,d,p,a,total;
int aa;
int arr[10000005];

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>arr[x];
        total+=(ll)arr[x];
    }
    for(int x=0;x<n;x++){
        aa=arr[x];
				a=(ll)aa;
        h+=a*a*(n-1);h+=a*(total-a);
        //h%=mod;

        d+=a*a;
        //d%=mod;
    }
    d=d*d;
    h-=d;
		h%=mod;
    cout<<(long long)h;
    return 0;
}