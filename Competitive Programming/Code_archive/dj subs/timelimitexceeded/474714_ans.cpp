// ans.cpp 5 Jan 19, 22:35:09 100 0.02 Judging completed in 2.425s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,a,m=LLONG_MIN;
    cin>>n;
    for(long long x=0;x<min(1000000LL,n);x++){
        cin>>a;
        m=max(m,a);
    }
    cout<<m;
    return 0;
}