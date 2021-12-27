// ans.cpp 30 May 17, 22:36:03 100 1.28 Judging completed in 9.647s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string a;
    cin>>n;
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