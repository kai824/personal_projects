// ans.cpp 30 Oct 19, 14:53:49 100 0 Judging completed in 3.617s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[105][105];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    pair<pair<int,int>,int> el[m];//edge list
    for(int x=0;x<=n;x++){
        for(int y=0;y<=n;y++){
            arr[x][y]=1e9;
        }
    }
    for(int x=0;x<m;x++){
        cin>>el[x].first.first>>el[x].first.second>>el[x].second;
        arr[el[x].first.first][el[x].first.second]=el[x].second;
		arr[el[x].first.second][el[x].first.first]=el[x].second;
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int z=1;z<=n;z++){
                arr[y][z]=min(arr[y][z],arr[y][x]+arr[x][z]);
            }
        }
    }
    for(int x=0;x<m;x++){
        if(arr[el[x].first.first][el[x].first.second]<el[x].second){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}