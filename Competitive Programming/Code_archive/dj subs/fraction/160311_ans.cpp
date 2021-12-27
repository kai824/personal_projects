// ans.cpp 7 Nov 16, 18:30:56 37 1 Judging completed in 7.617s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    uint64_t a,b,c=2;
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