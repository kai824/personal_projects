// ans.cpp 23 Oct 16, 20:52:14 0 0 Judging completed in 4.171s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,n,e;
    cin>>n>>e;
    int c[n][n];
    for(int d=1;d<=e;d++){
        cin>>a>>b;
        c[a][b]=1;
        c[b][a]=1;
    }
    for(int d=1;d<=n;d++){
        for(int f=1;f<=n;f++){
            if (c[d][f]==1) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
    }
    return 0;
}