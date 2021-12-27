// ans.cpp 14 Dec 19, 12:51:24 10 0.01 Judging completed in 3.407s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1;
ll mod=1e9+7;
int main() {
    int n,k;
    cin>>n>>k;
    for(ll x=k;x>k-n;x--){
        ans*=x;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}