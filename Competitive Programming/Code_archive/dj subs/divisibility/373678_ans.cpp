// ans.cpp 30 Jun 18, 23:49:57 0 0 Judging completed in 3.86s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dp[2][101];
bool bit=0;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,a;
    cin>>n>>k;
    for(int x=0;x<n;x++){
        cin>>a;
        a=abs(a%k);
        if(x==0){
            dp[bit][a]=1;
            dp[bit][k-a]=1;
            bit=!bit;
            continue;
        }
        for(int y=0;y<k;y++){
            dp[bit][y]=0;
            if(y>=a)dp[bit][y]+=dp[!bit][y-a];
            else dp[bit][y]+=dp[!bit][y-a+k];
            if(y+a<k)dp[bit][y]+=dp[!bit][y+a];
            else dp[bit][y]+=dp[!bit][y+a-k];
        }
        bit=!bit;
    }
    if(dp[!bit][0]==0)cout<<"Not divisible";
    else cout<<"Divisible";
    return 0;
}