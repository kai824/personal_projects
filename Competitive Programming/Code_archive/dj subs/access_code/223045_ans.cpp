// ans.cpp 17 Oct 17, 15:27:04 100 0 Judging completed in 5.799s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll m=1000000007;
ll ipow(ll a,ll b){//2305843009213693952
    ll ans=1,current,p=2305843009213693952;
    for(ll x=60;(x>=0&&b>0);x--){
        p/=2;
        current=a;
        if(p>b)continue;
        for(int y=0;y<x;y++){
            current=current*current;
            current%=m;
        }
        current%=m;
        ans*=current;
        ans%=m;
        b-=p;
    }
    return(ans%m);
}
int main() {
    ll n,k;
    cin>>n>>k;
    cout<<ipow(ipow(2,k),n-1);
    return 0;
}