// ans.cpp 4 Jul 17, 17:02:22 100 0 Judging completed in 3.192s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,l,ans=0;
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
    cin>>l;
    for(int x=0;x<n;x++){
        if(a[x]+b[n-1-x]>l){
            ans+=a[x]+b[n-1-x]-l;
        }
    }
    ans*=100;
    cout<<ans;
    return 0;
}