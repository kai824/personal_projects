// ans.cpp 15 Jan 19, 21:50:22 100 0.05 Judging completed in 2.379s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10001][401];
//city no., no. of nights spent
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m,h,j,k;
    cin>>n>>m>>h;
    dp[0][0]=1;
    for(ll x=0;x<n-1;x++){
        if(x>0){//cout<<dp[x][0];
            for(ll y=1;y<m;y++){
                dp[x][y]+=dp[x][y-1];//can spend extra nights...
                dp[x][y]=min(dp[x][y],500000001LL);
                //cout<<' '<<dp[x][y];
            }
        }//cout<<'\n';
        for(ll y=0;y<h;y++){
            cin>>j>>k;
            if(j==x)continue;
            for(ll z=0;z+k<m;z++){
                dp[j][z+k]+=dp[x][z];
            }
        }
    }
    cout<<dp[n-1][0];
    for(ll y=1;y<m;y++){
        dp[n-1][y]+=dp[n-1][y-1];
        dp[n-1][y]=min(dp[n-1][y],500000001LL);
        cout<<' '<<dp[n-1][y];
    }
    return 0;
}