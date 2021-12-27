// ans.cpp 14 Dec 19, 12:04:49 0 0 Judging completed in 3.714s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1;
ll mod=1e9+7;
int main() {
    int n,k;
    cin>>n>>k;
    for(ll x=n;x>n-k;x--){
        ans*=x;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}