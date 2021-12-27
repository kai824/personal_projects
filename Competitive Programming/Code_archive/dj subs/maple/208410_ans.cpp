// ans.cpp 30 May 17, 22:38:24 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
struct a{
    char x[20];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned int n;
    cin>>n;
    pair<unsigned int,a> arr[n];
    for(unsigned int x=0;x<n;x++){
        cin>>arr[x].second.x;
    }
    for(unsigned int x=0;x<n;x++){
        cin>>arr[x].first;
    }
    sort(arr,arr+n);
    for(unsigned int x=0;x<n;x++){
        cout<<arr[x].second.x<<'\n';
    }
    return 0;
}