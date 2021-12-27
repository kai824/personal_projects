// ans.cpp 15 Mar 19, 22:57:22 100 0.18 Judging completed in 2.567s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll tc,a,b,d,dp[400005],cursum=1;
    dp[0]=1;
    for(int x=1;x<400005;x++){
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