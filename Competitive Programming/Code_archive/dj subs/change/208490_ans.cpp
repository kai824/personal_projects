// ans.cpp 31 May 17, 11:09:20 71.43 0 Judging completed in 6.478s on AWS Oregon.
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
    e-=(a*5);
    if(e==0){
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<a+b+c+d;
    }else{
        cout<<"-1";
    }
    return 0;
}