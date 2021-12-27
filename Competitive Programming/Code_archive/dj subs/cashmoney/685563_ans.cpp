// ans.cpp 25 Jan 20, 11:50:46 21 1.29 Judging completed in 6.81s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long h,d,a,sum,mod;
    mod=1e9+12;
    h=d=sum=0;
    long long n;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        a=arr[x];
        d+=a*a;
        d%=mod;
        sum+=a;sum%=mod;
    }
    h-=(d*d)%mod;
    for(int x=0;x<n;x++){
        /*for(int y=0;y<n;y++){
            h+=(arr[x]+arr[y])*(arr[x]+arr[y]);
            if(h>=mod)h%=mod;
        }*/
        //d is the sum of the squares...
        a=arr[x];
        h+=d;
        h+=n*((a*a)%mod);
        h%=mod;
        h+=(2*a*sum)%mod;
        h%=mod;
    }
    if(h<0)h+=mod;
    cout<<h;
    return 0;
}