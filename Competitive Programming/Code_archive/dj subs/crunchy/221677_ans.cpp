// ans.cpp 7 Oct 17, 21:40:52 100 0.01 Judging completed in 3.84s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    string arr[n];
    for(x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    for(x=0;x<n;x++){
        cout<<arr[x];
    }
    return 0;
}