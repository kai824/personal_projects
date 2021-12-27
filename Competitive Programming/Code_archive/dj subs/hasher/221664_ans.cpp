// ans.cpp 7 Oct 17, 20:58:19 0 0.03 Judging completed in 9.609s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,hash;
    cin>>n;
    pair<int,string> arr[1000000];
    for(int x=0;x<n;x++){
        cin>>arr[x].second;
        hash=0;
        for(int y=0;y<arr[x].second.length();y++){
            hash=hash^((int)arr[x].second[y]);
        }
        arr[x].first=hash;
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        cout<<arr[x].second<<'\n';
    }
    return 0;
}