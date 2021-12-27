// ans.cpp 29 May 17, 21:55:36 100 0 Judging completed in 2.806s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k,ans=0,current=0,p1,p2;
    cin>>n>>k;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    if(k>n){
        for(int x=0;x<n;x++){
            ans+=arr[x];
        }
        cout<<ans;
        return 0;
    }
    for(int x=0;x<k;x++){
        current+=arr[x];
    }
    p1=0;p2=k;
    while(p2<=n){
        ans=max(ans,current);
        current-=arr[p1];
        p1++;
        if(p2<n)current+=arr[p2];
        p2++;
    }
    cout<<ans;
    return 0;
}