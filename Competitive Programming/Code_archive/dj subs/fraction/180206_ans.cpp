// ans.cpp 12 Jan 17, 21:55:57 37 0 Judging completed in 7.373s on AWS Ireland.
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