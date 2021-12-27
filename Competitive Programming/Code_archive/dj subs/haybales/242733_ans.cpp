// ans.cpp 5 Nov 17, 21:34:08 100 0 Judging completed in 3.959s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,sum=0,ans=0;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        sum+=arr[x];
    }
    sum/=n;
    for(int x=0;x<n;x++){
        ans+=abs(arr[x]-sum);
    }
    cout<<ans/2;
    return 0;
}