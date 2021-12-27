// ans.cpp 12 Jul 18, 09:28:01 100 0.08 Judging completed in 3.654s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    int arr[n],it[n];//arr, sorted arr
    pair<int,int> sarr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        sarr[x].first=arr[x];
        sarr[x].second=x;
    }
    sort(sarr,sarr+n);
    for(int x=0;x<n;x++){
        it[sarr[x].second]=x;
    }
    for(int x=0;x<n;x++){
        if(it[x]<n/2)cout<<sarr[(n/2)].first;
        else cout<<sarr[(n/2)-1].first;
        cout<<'\n';
    }
    return 0;
}