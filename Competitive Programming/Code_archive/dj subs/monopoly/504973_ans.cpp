// ans.cpp 15 Mar 19, 22:56:34 41 0.16 Judging completed in 2.375s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc,a,b,d,dp[100005],cursum=1;
    dp[0]=1;
    for(int x=1;x<100005;x++){
        dp[x]=cursum%1000000007;
        cursum+=dp[x];
        if(x>=6)cursum-=dp[x-6];
        cursum%=1000000007;
        if(cursum<0)cursum+=1000000007;
		//if(x<10)cout<<dp[x]<<' ';
    }//cout<<'\n';
    char c;
    cin>>tc;
    while(tc--){
        cin>>a>>c>>b;
        d=(c-'A')*(a-1)+b;
		d%=(a-1)*4;
        cout<<dp[d]<<'\n';
    }
    return 0;
}