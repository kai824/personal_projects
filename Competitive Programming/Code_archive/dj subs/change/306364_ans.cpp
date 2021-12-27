// ans.cpp 26 Dec 17, 14:45:40 71.43 0 Judging completed in 5.665s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int main() {
    ll a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    if(d*50<=e){
        e-=d*50;
    }else{
        d=e/50;
        e%=50;
    }
    if(c*20<=e){
        e-=c*20;
    }else{
        c=e/20;
        e%=20;
    }
    if(b*10<=e){
        e-=b*10;
    }else{
        b=e/10;
        e%=10;
    }
    if(a*5<=e){
        e-=a*5;
    }else{
        a=e/5;
        e%=5;
    }
    if(e==0){
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<a+b+c+d;
    }else{
        cout<<"-1";
    }
    return 0;
}