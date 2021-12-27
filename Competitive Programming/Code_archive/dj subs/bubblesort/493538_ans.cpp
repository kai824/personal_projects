// ans.cpp 19 Feb 19, 18:14:42 100 0 Judging completed in 3.821s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        cout<<arr[x];
        if(x+1<n)cout<<' ';
    }
    return 0;
}