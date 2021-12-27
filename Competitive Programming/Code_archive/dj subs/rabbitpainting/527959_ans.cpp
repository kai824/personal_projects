// ans.cpp 2 Jun 19, 20:19:22 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll r,c,ans=0,curr;
    cin>>r>>c;
    ll mat[r][c];
    ll maxx[c],cur[c];//1 1d maxsum for each column
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            cin>>mat[x][y];
            maxx[y]=0;cur[y]=0;
        }
    }
    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            cur[y]+=mat[x][y];
            cur[y]=max(cur[y],0);
            maxx[y]=max(maxx[y],cur[y]);
        }
        curr=0;
        for(int y=0;y<c;y++){
            curr+=maxx[y];
            curr=max(0,curr);
            ans=max(ans,curr);
        }
    }
    cout<<ans;
    return 0;
}