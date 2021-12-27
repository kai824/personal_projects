// ans.cpp 5 Nov 16, 10:40:17 0 0.03 Judging completed in 2.675s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a;
    int b,c,d=0;
    cin>>a;
    while(a>0){
        if(d==0){
            d=1;
            b=b+a%10;
            a=a/10;
        }
        else{
            d=0;
            c=c+a%10;
            a=a/10;
        }
    }
    a=b-c;
    if(a<0) a=a*(-1);
    if(a%11==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}