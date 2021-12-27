// ans.cpp 29 Sep 17, 13:28:43 0 1 Judging completed in 7.49s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,it=0,ans=INT_MAX,current;
    cin>>n>>k;
    int arr[n+1];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    arr[n]=0;
    for(int x=1;x<k;x++){
        if(arr[x]<=arr[it]){
            it=x;
        }
    }
    current=it;
    ans=arr[it];
    while(current<=n){
        it=current+1;
        for(int x=current+2;x<min(current+k,n+1);x++){
            if(arr[x]<=arr[it])it=x;
        }
        ans=min(ans,arr[it]);
        it=current;
    }
    cout<<ans;
    return 0;
}