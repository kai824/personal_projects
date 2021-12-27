// ans.cpp 2 Jun 19, 20:31:50 100 0.11 Judging completed in 70.611s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll r,c,ans=0,curr=0;
    cin>>r>>c;
    ll mat[r][c];
    ll cur[c];//1 1d maxsum for each column
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            cin>>mat[x][y];
            cur[y]=0;
        }
    }
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            cur[y]+=mat[x][y];
            cur[y]=max(cur[y],mat[x][y]);
        }
        curr=0;
        for(int y=0;y<c;y++){
            curr+=cur[y];
            curr=max(0LL,curr);
            ans=max(ans,curr);
        }
    }
    cout<<ans;
    return 0;
}