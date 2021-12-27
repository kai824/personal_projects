// ans.cpp 5 Feb 17, 21:08:28 20 0 Judging completed in 3.795s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    long long int a[n][m];
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cin>>a[x][y];
        }
        sort(a[x],a[x]+m);
    }
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cout<<a[x][y];
            if(y+1<m)cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}