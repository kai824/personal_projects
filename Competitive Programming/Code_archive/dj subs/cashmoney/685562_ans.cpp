// ans.cpp 25 Jan 20, 11:49:19 21 0 Judging completed in 4.735s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long h,d,sum,mod;
    mod=1e9+12;
    h=d=sum=0;
    long long n;
    cin>>n;
    long long arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        d+=arr[x]*arr[x];
        d%=mod;
        sum+=arr[x];sum%=mod;
    }
    h-=(d*d)%mod;
    for(int x=0;x<n;x++){
        /*for(int y=0;y<n;y++){
            h+=(arr[x]+arr[y])*(arr[x]+arr[y]);
            if(h>=mod)h%=mod;
        }*/
        //d is the sum of the squares...
        h+=d;
        h+=n*((arr[x]*arr[x])%mod);
        h%=mod;
        h+=(2*arr[x]*sum)%mod;
        h%=mod;
    }
    if(h<0)h+=mod;
    cout<<h;
    return 0;
}