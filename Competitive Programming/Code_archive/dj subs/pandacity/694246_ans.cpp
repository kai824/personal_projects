// ans.cpp 3 Feb 20, 21:57:32 0 0.18 Judging completed in 4.354s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,b;
    long long ans=0;
    cin>>n>>b;
    long long arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n,greater<long long>());
    for(int x=1;x<n && x<=b;x++){
        ans+=arr[0];
        ans+=arr[x];
    }
    cout<<ans;
    return 0;
}