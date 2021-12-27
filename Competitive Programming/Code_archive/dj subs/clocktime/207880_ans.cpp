// ans.cpp 24 May 17, 17:03:51 100 0 Judging completed in 8.217s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    c+=d;
    b+=c/60;
    a+=b/60;
    c%=60;
    b%=60;
    a%=24;
    cout<<a<<' '<<b<<' '<<c;
    return 0;
}