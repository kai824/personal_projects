// ans.cpp 25 Dec 17, 15:19:34 0 0 Compilation failed on AWS Oregon.
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
	if(( (s+e)%2) ==0){
		return((((((s+e)/2)%m)*((e-s+1)%m)))%m);
	}else{
		return(((((s+e)%m)*(((e-s+1)/2)%m)))%m);
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll p,q;
    cin>>p>>q;
    cout<<( sumi(p,q)%m))%m;
    return 0;
}