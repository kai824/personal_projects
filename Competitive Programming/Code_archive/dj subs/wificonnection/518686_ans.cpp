// ans.cpp 27 Apr 19, 11:17:04 100 0.14 Judging completed in 4.149s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,r,a,b,ans=0;
    cin>>n>>r;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        if((sqrt(a*a+b*b))<=r)ans++;
    }
    cout<<ans;
    return 0;
}