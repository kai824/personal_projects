// ans.cpp 5 Nov 16, 10:33:25 20 0.04 Judging completed in 4.242s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    cin>>a;
    b=a/1000000+(a/10000)%10+(a/100)%10+a%10;
    c=(a/100000)%10+(a/1000)%10+(a/10)%10;
    a=b-c;
    if(a<0) a=a*(-1);
    if(a%11==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}