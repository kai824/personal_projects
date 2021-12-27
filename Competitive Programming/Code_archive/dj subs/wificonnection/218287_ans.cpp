// ans.cpp 7 Aug 17, 17:45:26 100 0.68 Judging completed in 5.929s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,r,a,b,ans=0;
    cin>>n>>r;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        if((sqrt(a*a+b*b))<=r)ans++;
    }
    cout<<ans;
    return 0;
}