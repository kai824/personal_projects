// ans.cpp 31 May 17, 11:01:31 28.57 0 Judging completed in 6.022s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    d=min(e/50,d);
    e-=(d*50);
    c=min(e/20,c);
    e-=(c*20);
    b=min(e/10,b);
    e-=(b*10);
    b=min(e/5,b);
    e-=(a*5);
    if(e==0){
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<a+b+c+d;
    }else{
        cout<<"-1";
    }
    return 0;
}