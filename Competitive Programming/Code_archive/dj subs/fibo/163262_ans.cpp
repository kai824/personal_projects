// ans.cpp 19 Nov 16, 09:59:03 100 0 Judging completed in 6.952s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    uint64_t f0=0,f1=1,f2;
    if(n==0){
        cout<<f0;
    }else if(n==1){
        cout<<f1;
    }else{
        for(int a=1;a<n;a++){
            f2=f0+f1;
            f0=f0%m;
            f1=f1%m;
            f2=f2%m;
            f0=f1;
            f1=f2;
        }
        cout<<f2%m;
    }
    return 0;
}