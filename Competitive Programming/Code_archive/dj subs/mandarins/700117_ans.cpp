// ans.cpp 14 Feb 20, 21:52:57 100 0 Judging completed in 3.26s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll ipow(ll a,ll b,ll m){
    ll current,ans=1;
    for(ll y=63;(y>=0 && b>0);y--){
        current=a;
        if((1LL<<y)>b)continue;
        for(ll z=0;z<y;z++){
            current=current*current;
            current=current%m;
        }
        current=current%m;
        ans*=current;
        ans%=m;
        b-=(1LL<<y);
    }
    return ans;
}
int main() {
    ll n,k;cin>>n>>k;
    k++;
    //calculate k power n...
    k%=(long long)(1e9+7);
    cout<<ipow(k,n,1e9+7);
    return 0;
}