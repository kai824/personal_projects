// ans.cpp 13 Feb 17, 07:47:48 0 1 Judging completed in 4.927s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,tc;
    cin>>tc;
    for(int x=0;x<tc;x++){
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
    cout<<endl;
    }
    return 0;
}