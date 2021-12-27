// ans.cpp 26 Oct 16, 21:14:51 50 0 Judging completed in 5.788s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,n,e;
    cin>>n>>e;
    int c[n][n];
    for(int a=0;a<n;a++){
        for(int b=0;b<1;b++){
            c[a][b]=0;
        }
    }
    for(int d=0;d<e;d++){
        cin>>a>>b;
        c[a-1][b-1]=1;
        c[b-1][a-1]=1;
    }
    for(int d=0;d<n;d++){
        for(int f=0;f<n;f++){
            if (c[d][f]==1) cout<<1;
            else cout<<0;
        }
        cout<<"\n";
    }
    return 0;
}

