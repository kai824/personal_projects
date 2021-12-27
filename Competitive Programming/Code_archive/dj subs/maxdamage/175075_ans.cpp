// ans.cpp 26 Dec 16, 23:05:54 66.67 0 Judging completed in 2.34s on AWS Oregon.
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main() {
    char a;
    double b,c,d,e,f,g;
    cin>>a>>b>>c>>d>>e>>f>>g;
    double ans=((4*b)+c)*((d+e+f+g)/100);
    if(a=='G'){
        ans*=1.6;
    }else{
        ans*=1.7;
    }
    cout<<ans<<setprecision(2);
    return 0;
}