// ans.cpp 5 Nov 16, 11:07:11 54 0 Judging completed in 10.139s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,d;
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