// ans.cpp 24 Jan 20, 17:24:47 0 1.21 Judging completed in 6.144s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
typedef __int128 ll;

ll mod=1e9+12;
ll h,d,p,a;
int aa;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>aa;
				a=(ll)aa;
        h+=a*a*(n-1);h+=2*a*p;
        //h%=mod;

        p+=a;
        //p%=mod;

        d+=a*a;
        //d%=mod;
    }
    d=d*d;
    h*=2;
    h-=d;
		h%=mod;
    cout<<(long long)h;
    return 0;
}