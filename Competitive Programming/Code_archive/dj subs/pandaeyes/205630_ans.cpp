// ans.cpp 1 May 17, 21:33:02 0 0.03 Judging completed in 7.385s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,ans=0,prev=-1;
    cin>>n;
    pair<int,int> arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x].first>>arr[x].second;
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        if(arr[x].first<prev)continue;
        if(x+1>=n){
            ans++;
            continue;
        }
        if(arr[x].second<arr[x+1].second){
            ans++;
            prev=arr[x].second;
        }else{
            ans++;
            prev=arr[x+1].second;
        }
    }
    cout<<ans;
    return 0;
}