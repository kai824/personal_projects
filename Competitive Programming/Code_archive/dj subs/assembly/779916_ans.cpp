// ans.cpp 9 Nov 20, 15:53:55 100 0 Judging completed in 3.038s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
    //ifstream cin("data.txt");
    int n,e1,e2,x1,x2;
    cin>>n>>e1>>e2;
    int dp[n+2][2];
    int a1[n],a2[n],t1[n-1],t2[n-1];
    for(int i=0;i<n;i++)cin>>a1[i];
    for(int i=0;i<n;i++)cin>>a2[i];
    for(int i=0;i<n-1;i++)cin>>t2[i];
    for(int i=0;i<n-1;i++)cin>>t1[i];
    dp[1][0]=e1+a1[0];
    dp[1][1]=e2+a2[0];
	//cout<<dp[1][0]<<' '<<dp[1][1]<<'\n';
    for(int i=2;i<=n;i++){
        dp[i][0]=min(dp[i-1][0]+a1[i-1],dp[i-1][1]+a1[i-1]+t1[i-2]);
        dp[i][1]=min(dp[i-1][1]+a2[i-1],dp[i-1][0]+a2[i-1]+t2[i-2]);
		if(i==n){
			//cout<<dp[i-1][1]<<' '<<a2[i-1]<<'\n';
		}
		//cout<<"out "<<dp[i][0]<<' '<<dp[i][1]<<'\n';
    }
	//for(int i=1;i<=n;i++){
	//	cout<<"out2 "<<dp[i][0]<<' '<<dp[i][1]<<'\n';
	//}
    cin>>x1>>x2;
    cout<<min(dp[n][0]+x1,dp[n][1]+x2);
}
/*5
2 10
2 3 4 19 20
7 8 9 1 2
1 1 1 1
1 1 1 1
5 10
*/