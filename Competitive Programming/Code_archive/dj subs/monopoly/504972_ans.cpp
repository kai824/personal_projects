// ans.cpp 15 Mar 19, 22:53:52 0 0.16 Judging completed in 4.194s on AWS Oregon.
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
    }
    char c;
    cin>>tc;
    while(tc--){
        cin>>a>>c>>b;
        d=(c-'A')*(a-1)+b+1;
        cout<<dp[d]<<'\n';
    }
    return 0;
}