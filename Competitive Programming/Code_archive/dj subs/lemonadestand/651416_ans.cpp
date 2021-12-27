// ans.cpp 16 Dec 19, 16:39:38 0 0 Judging completed in 3.612s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,ans=1,max_capacity=1;
    cin>>n>>k;
    int arr[k];
    for(int x=0;x<k;x++){
        cin>>arr[x];
    }
    sort(arr,arr+k);
    for(int x=1;x<k;x++){
        while(max_capacity+arr[x-1]<=arr[x] && max_capacity<n){
            ans++;
            max_capacity+=arr[x-1];
            if(max_capacity>=arr[x])break;
        }
    }
    while(max_capacity<n){
        ans++;
        max_capacity+=arr[k-1];
    }
    cout<<ans;
    return 0;
}