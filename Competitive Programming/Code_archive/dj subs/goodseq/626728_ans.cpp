// ans.cpp 4 Dec 19, 10:11:27 0 0.01 Judging completed in 3.601s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=1;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    for(int x=1;x<n;x++){
        if(arr[x]!=arr[x-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}