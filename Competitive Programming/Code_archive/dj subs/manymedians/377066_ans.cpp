// ans.cpp 12 Jul 18, 09:23:24 0 0 Compilation failed on AWS Oregon.
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
    sorted(sarr,sarr+n);
    for(int x=0;x<n;x++){
        it[sarr[x].second]=x;
    }
    for(int x=0;x<n;x++){
        if(it[x]<=n/2)cout<<sarr[(n/2)+1].first;
        else cout<<sarr[n/2].first;
        if(x+1<n)cout<<' ';
    }
    return 0;
}