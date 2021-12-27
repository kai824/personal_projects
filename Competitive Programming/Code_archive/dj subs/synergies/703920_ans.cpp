// ans.cpp 22 Feb 20, 13:35:27 0 0.07 Judging completed in 3.766s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,a,ans=0;
    vector<ll> v;
    cin>>n;
    for(ll x=0;x<n;x++){
        cin>>a>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    ans+=min(n-1,v[0]);
    for(ll x=1;x<n;x++){
        ans+=min(n-1-x,v[x]-v[x-1]);
    }
    cout<<ans;
    return 0;
}