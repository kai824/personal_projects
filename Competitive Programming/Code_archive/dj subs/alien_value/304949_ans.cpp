// ans.cpp 25 Dec 17, 14:49:24 4 0 Judging completed in 4.568s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll m=1000000007;
ll ipow(ll base,ll exponent){
    base%=m;
    ll result=1;
    while(exponent){
        if (exponent%2==1) result *= base;
        base *= base;
        base %= m;
        result %= m;
        exponent >>= 1;
    }
    return result;
}
ll sumi(ll s,ll e){
    return (((((s+e))*((e-s+1)))/2)%m);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll p,q;
    cin>>p>>q;
    cout<<(ipow(2,q-p)*( sumi(p,q)%m))%m;
    return 0;
}