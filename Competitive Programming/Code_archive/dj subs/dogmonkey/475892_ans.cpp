// ans.cpp 10 Jan 19, 21:03:13 100 0 Judging completed in 4.255s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m,ans=1;
    cin>>n>>m;
    if(abs(n-m)>1){
        cout<<0;
        return 0;
    }
    if(n==m)ans=2;
    for(ll x=1;x<=n;x++){
        ans*=x;
        ans%=1000000007;
    }
    for(ll x=1;x<=m;x++){
        ans*=x;
        ans%=1000000007;
    }
    cout<<ans;
    return 0;
}