// ans.cpp 16 Apr 17, 14:42:28 98 1 Judging completed in 5.726s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    int n,ans=INT_MAX;
    cin>>n;
    int adjmat[n][n];
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            cin>>adjmat[x][y];
        }
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            for(int z=0;z<n;z++){
                adjmat[y][z]=max(adjmat[y][z],min(adjmat[y][x],adjmat[x][z]));
            }
        }
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            ans=min(ans,adjmat[x][y]);
        }
    }
    cout<<ans;
    return 0;
}