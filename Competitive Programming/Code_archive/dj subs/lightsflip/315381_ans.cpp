// ans.cpp 11 Jan 18, 20:49:10 100 1.85 Judging completed in 10.508s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool on[2005][2005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q,a,b,c,d;
    cin>>n>>m>>q;
    for(int x=0;x<q;x++){
        cin>>a>>b>>c>>d;
        c++;d++;
        on[a][b]=!on[a][b];
        on[c][d]=!on[c][d];
        on[a][d]=!on[a][d];
        on[c][b]=!on[c][b];
    }
    cout<<on[0][0]<<' ';
    for(int x=1;x<m;x++){
        on[0][x]^=on[0][x-1];
        cout<<on[0][x];
        if(x+1<m)cout<<' ';
    }cout<<'\n';
    for(int x=1;x<n;x++){
        for(int y=0;y<m;y++){
            if(y!=0){
                on[x][y]^=on[x][y-1];
                on[x][y]^=on[x-1][y-1];
            }
            on[x][y]^=on[x-1][y];
            cout<<on[x][y];
            if(y+1<m)cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}