// ans.cpp 5 Nov 16, 11:03:22 0 0 Judging completed in 4.935s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
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
    }
    if((b==1)&&(a>=2)) c=c+1;
    cout<<c;
    return 0;
}