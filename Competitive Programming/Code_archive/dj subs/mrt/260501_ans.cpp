// ans.cpp 18 Nov 17, 11:53:04 100 0.18 Judging completed in 3.189s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,e,q,a,b,c;
    cin>>n>>e>>q;
    int adjmat[n+5][n+5];
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            adjmat[x][y]=1000000005;
            if(x==y)adjmat[x][y]=0;
        }
    }
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjmat[a][b]=c;
        adjmat[b][a]=c;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                adjmat[j][k]=min(adjmat[j][k],adjmat[j][i]+adjmat[i][k]);
            }
        }
    }
    for(int x=0;x<q;x++){
        cin>>a>>b;
        if(adjmat[a][b]==1000000005)cout<<-1<<'\n';
        else cout<<adjmat[b][a]<<'\n';
    }
    return 0;
}