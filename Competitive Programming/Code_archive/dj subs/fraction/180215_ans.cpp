// ans.cpp 12 Jan 17, 22:02:42 37 1 Judging completed in 7.802s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,c=2;
    cin>>a>>b;
    while(true){
        if(((c*2)-3>a)||((c*2)-3>b)) break;
        if((a%c==0)&&(b%c==0)){
            a=a/c;
            b=b/c;
        }
        else break;
    }
    c=3;
    while(true){
        if(((c*2)-3>a)||((c*2)-3>b)) break;
        if((a%c==0)&&(b%c==0)){
            a=a/c;
            b=b/c;
        }
        else c=c+2;
    }
    cout<<a<<"/"<<b;
    return 0;
}