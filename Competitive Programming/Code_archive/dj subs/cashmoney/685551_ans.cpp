// ans.cpp 25 Jan 20, 11:39:32 0 0 Judging completed in 5.176s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long h,d,mod;
    mod=1e9+12;
    h=d=0;
    int n;
    cin>>n;
    long long arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        d+=arr[x]*arr[x];
        d%=mod;
    }
    h-=d;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            h+=(arr[x]+arr[y])*(arr[x]+arr[y]);
            if(h>=mod)h%=mod;
        }
    }
    cout<<h;
    return 0;
}