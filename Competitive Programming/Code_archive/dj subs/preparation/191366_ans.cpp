// ans.cpp 13 Feb 17, 07:42:40 0 0 Judging completed in 7.137s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,ans=0;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(a*2<=b){
        cout<<a;
        return 0;
    }ans=b/2;
    a-=ans;
    if(b*2<=a){
        ans+=b;
        cout<<ans;
    }
    return 0;
}