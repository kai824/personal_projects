// ans.cpp 16 Apr 17, 13:58:39 2 0 Judging completed in 7.074s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    long long n,ans=0;
    cin>>n;
    int a[n],b[n];
    for(int x=0;x<n;x++){
        cin>>a[x];
    }
    for(int x=0;x<n;x++){
        cin>>b[x];
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int x=0;x<n;x++){
        ans+=(a[x]*b[x]);
    }
    cout<<ans<<'\n';
    return 0;
}