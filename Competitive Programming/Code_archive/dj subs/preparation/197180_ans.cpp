// ans.cpp 6 Mar 17, 11:41:23 54 1 Judging completed in 7.539s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,c,d;
    cin>>a>>b;
    if (a>b){
        c=a;
        a=b;
        b=c;
    }
    c=0;
    while((b>1)&&(a>0)){
        a=a-1;
        b=b-2;
        c=c+1;
        if(a>b){
            d=a;
            a=b;
            b=d;
        }
    }
    if((b==1)&&(a>=2)) c=c+1;
    cout<<c;
    return 0;
}