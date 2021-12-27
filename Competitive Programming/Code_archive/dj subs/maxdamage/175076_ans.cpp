// ans.cpp 26 Dec 16, 23:12:41 100 0 Judging completed in 3.079s on AWS Oregon.
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main() {
    char a;
    double b,c,d,e,f,g;
    cin>>a>>b>>c>>d>>e>>f>>g;
    double ans=((d+e+f+g)/100);
    ans*=((4*b)+c);
    if(a=='G'){
        ans*=1.6;
    }else{
        ans*=1.7;
    }
    #include <iomanip>
	cout << fixed << setprecision(2);
    cout<<ans;
    return 0;
}