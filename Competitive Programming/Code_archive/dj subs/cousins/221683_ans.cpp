// ans.cpp 7 Oct 17, 21:51:07 17 0.29 Judging completed in 6.578s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int trinum(int x){
    return ((x*(x+1))/2);
}
int main() {
    int n,prev=0,ans=0;
    cin>>n;
    string arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        sort(arr[x].begin(),arr[x].end());
    }
    sort(arr,arr+n);
    for(int x=1;x<n;x++){
        if(arr[x]!=arr[x-1]){
            ans+=trinum(x-prev-1);
            prev=x;
        }
    }
    ans+=trinum(n-prev-1);
    cout<<ans;
    return 0;
}