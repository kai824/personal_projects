// ans.cpp 24 Jan 20, 16:38:39 6 0 Judging completed in 3.353s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    k%=1000000007;
    cout<<ipow(k,n,1e9+7);
    return 0;
}