// ans.cpp 3 Feb 20, 22:54:56 100 0.19 Judging completed in 5.365s on AWS Oregon.
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
    if(b+1<n){
        cout<<-1;return 0;
    }
    sort(arr,arr+n,greater<long long>());
    for(int x=1;x<n && x<=b;x++){
        ans+=arr[0];
        ans+=arr[x];
    }
    cout<<ans;
    return 0;
}