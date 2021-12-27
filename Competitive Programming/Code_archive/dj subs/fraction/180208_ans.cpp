// ans.cpp 12 Jan 17, 21:57:04 37 1 Judging completed in 7.096s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,c=2;
    cin>>a>>b;
    while(true){
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