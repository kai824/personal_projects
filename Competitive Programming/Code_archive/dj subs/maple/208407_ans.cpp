// ans.cpp 30 May 17, 22:34:36 0 0 Judging completed in 7.026s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string a;
    pair<int,string> arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x].second;
    }
    for(int x=0;x<n;x++){
        cin>>arr[x].first;
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        cout<<arr[x].second<<'\n';
    }
    return 0;
}