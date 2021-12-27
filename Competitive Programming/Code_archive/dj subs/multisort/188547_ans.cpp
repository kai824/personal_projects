// ans.cpp 7 Feb 17, 12:54:00 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cin>>a[x][y];
        }
        sort(a[x],a[x]+m);
    }
    sort(a,a+n);
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            cout<<a[x][y];
            if(y+1<m)cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}