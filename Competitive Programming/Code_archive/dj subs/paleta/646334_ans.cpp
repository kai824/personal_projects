// ans.cpp 14 Dec 19, 12:04:37 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1;
ll mod=1e9+7;
int main() {
    int n,k;
    cin>>n>>k;
    for(ll x=n;x>n-k;x-){
        ans*=x;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}