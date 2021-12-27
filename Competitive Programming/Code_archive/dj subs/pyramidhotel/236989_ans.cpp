// ans.cpp 30 Oct 17, 09:39:42 100 0.12 Judging completed in 3.748s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[1000005],dp[1000005],ans=1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>arr[x];
        dp[x]=1;
    }
    for(int x=n-2;x>=0;x--){
        if(arr[x]>=dp[x+1]+1){
            dp[x]=max(dp[x],dp[x+1]+1);
            ans=max(ans,dp[x]);
        }else{
            dp[x]=max(dp[x],arr[x]);
            ans=max(ans,dp[x]);
        }
    }
    cout<<ans;
    return 0;
}