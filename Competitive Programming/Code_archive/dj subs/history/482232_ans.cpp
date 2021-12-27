// ans.cpp 26 Jan 19, 17:51:48 10 0 Judging completed in 2.092s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a;
    cin>>n>>m;
    map<int,int> mp;//map item to the "time"
    for(int x=0;x<n;x++){
        cin>>a;
        mp[a]=x+1;
    }
    int arr[25],best[25];
    for(int x=0;x<m;x++){
        for(int y=0;y<n;y++){
            cin>>a;
            arr[y]=mp[a];//find the time...
        }
        best[0]=1;
        for(int y=1;y<n;y++){
            best[y]=1;
            for(int z=0;z<y;z++){
                best[y]=max(best[y],best[z]);
                if(arr[y]>arr[z]){
                    best[y]=max(best[y],best[z]+1);
                }
            }
        }
        cout<<best[n-1]<<'\n';
    }
    return 0;
}