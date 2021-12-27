// ans.cpp 3 Feb 20, 21:57:08 0 0.17 Judging completed in 4.88s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,b;
    long long ans=0;
    cin>>n>>b;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n,greater<int>());
    for(int x=1;x<n && x<=b;x++){
        ans+=arr[0];
        ans+=arr[x];
    }
    cout<<ans;
    return 0;
}