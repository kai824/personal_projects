// ans.cpp 26 Dec 17, 14:34:29 70 0 Judging completed in 3.419s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,a=0,b=1,ans=0;
    cin>>n;
    while(b<n){
        swap(a,b);
        b+=a;
    }//a is now the largest fibonacci number smaller than n...
    while(n>0){
        ans+=n/a;
        n%=a;
        swap(a,b);
        a-=b;
    }
    cout<<ans*3;
    return 0;
}