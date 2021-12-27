// ans.cpp 3 Mar 20, 09:48:23 100 0 Judging completed in 4.015s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;int arr[n];for(int x=0;x<n;x++)cin>>arr[x];sort(arr,arr+n);
    for(int x=0;x<n-1;x++)cout<<arr[x]<<' ';
    cout<<arr[n-1]<<'\n';
    
}