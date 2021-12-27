// ans.cpp 14 Nov 18, 17:41:57 0 0.19 Judging completed in 2.626s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dp[2][200001];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    //dp it, diff = min value wasted
    int n,total=0;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
		total+=arr[x];
    }
    bool bit=0;//so that it'll be like x%2
    for(int x=0;x<n;x++){
        for(int y=-100000;y<=100000;y++){
            dp[bit][y+100000]=dp[!bit][y+100000]+arr[x];
            //since you're wasting it
            if(y+arr[x]<=100000){
                dp[bit][y+100000]=min(dp[bit][y+100000],dp[!bit][y+100000+arr[x]]);
            }
            if(y-arr[x]<=-100000){
                dp[bit][y+100000]=min(dp[bit][y+100000],dp[!bit][y+100000-arr[x]]);
            }
        }
        bit=!bit;
    }
    cout<<(total-dp[!bit][100000])/2;
    return 0;
}