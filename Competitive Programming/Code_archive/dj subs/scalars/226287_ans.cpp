// ans.cpp 21 Oct 17, 14:28:52 100 0 Judging completed in 5.86s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return(a>b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,ans=0;
    cin>>n;
    long long a[n],b[n];
    for(long long x=0;x<n;x++){
        cin>>a[x];
    }
    for(long long x=0;x<n;x++){
        cin>>b[x];
    }
    sort(a,a+n);
    sort(b,b+n,cmp);
    for(long long x=0;x<n;x++){
        ans+=(a[x]*b[x]);
    }
    cout<<ans<<'\n';
    return 0;
}