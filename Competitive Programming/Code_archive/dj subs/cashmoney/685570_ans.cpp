// ans.cpp 25 Jan 20, 11:55:38 0 1.25 Judging completed in 6.204s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long h,d,a,sum,mod;
    mod=1e9+12;
    h=d=sum=0;
    long long n;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        d+=a*a;
        d%=mod;
        sum+=a;sum%=mod;
        
        h+=d;
        h+=(x+1)*((a*a)%mod);
        h%=mod;
        h+=(2*a*sum)%mod;
        h%=mod;
    }
    h*=2;
    h-=(d*d)%mod;
    h%=mod;
    if(h<0)h+=mod;
    cout<<h;
    return 0;
}