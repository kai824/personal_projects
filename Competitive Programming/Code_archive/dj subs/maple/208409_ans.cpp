// ans.cpp 30 May 17, 22:37:17 100 0.64 Judging completed in 8.311s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned int n;
    string a;
    cin>>n;
    pair<unsigned int,string> arr[n];
    for(unsigned int x=0;x<n;x++){
        cin>>arr[x].second;
    }
    for(unsigned int x=0;x<n;x++){
        cin>>arr[x].first;
    }
    sort(arr,arr+n);
    for(unsigned int x=0;x<n;x++){
        cout<<arr[x].second<<'\n';
    }
    return 0;
}