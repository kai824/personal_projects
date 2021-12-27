// ans.cpp 9 Nov 20, 15:33:36 100 0.25 Judging completed in 3.357s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int n,p,q,arr[2005],p1,p2;

int dp[2005][2005];
bool check(int w){
    //O(NP) dp, state is min no. of large cam needed
    for(int i=0;i<=n;i++){
        if(i==0){
            for(int j=0;j<=p;j++){
                dp[i][j]=0;
            }
            continue;
        }
        for(int j=0;j<=p;j++)dp[i][j]=INT_MAX;
    }
    
    p1=p2=1;
    for(int i=1;i<=n;i++){
        while(arr[i-1]-arr[p1-1]+1>w)p1++;
        while(arr[i-1]-arr[p2-1]+1>(w<<1) )p2++;
        
        for(int j=0;j<=p;j++){
            if(j>0)dp[i][j]=min(dp[i][j],dp[p1-1][j-1]);//take small camera
            if(dp[p2-1][j]<q)dp[i][j]=min(dp[i][j],dp[p2-1][j]+1);//take big camera
            if(i==n && dp[i][j]<=q)return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>p>>q;//n, small cam, large cam of 2w
    p=min(n,p);q=min(n,q);//scam
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    int lo=1,hi=arr[n-1]-arr[0]+1,mid;
    while(lo<hi){//bsta for w...
        mid=lo+(hi-lo)/2;
        if(check(mid)){//can take pic of everything
            hi=mid;
        }else{
            lo=mid+1;
        }
    }
    cout<<lo;
    return 0;
}