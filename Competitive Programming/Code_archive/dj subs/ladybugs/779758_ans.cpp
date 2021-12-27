// ans.cpp 9 Nov 20, 15:01:45 100 0 Judging completed in 5.997s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[2005],dp[2005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        dp[i]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if((arr[i]&arr[j])==0){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}