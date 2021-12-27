// ans.cpp 7 Oct 17, 20:24:27 14.29 0 Judging completed in 6.344s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    d=min(e/50,d);
    e-=(d*50);
    c=min(e/20,c);
    e-=(c*20);
    b=min(e/10,b);
    e-=(b*10);
    a=min(e/5,a);
    cout<<"-1";
    return 0;
}