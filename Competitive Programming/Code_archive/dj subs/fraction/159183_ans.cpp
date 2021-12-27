// ans.cpp 5 Nov 16, 11:18:44 37 0 Judging completed in 5.714s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c=2;
    cin>>a>>b;
    while(1==1){
        if((c>a)||(c>b)) break;
        if(((a/c)*c==a)&&((b/c)*c==b)){
            a=a/c;
            b=b/c;
        }
        else c=c+1;
    }
    cout<<a<<"/"<<b;
    return 0;
}