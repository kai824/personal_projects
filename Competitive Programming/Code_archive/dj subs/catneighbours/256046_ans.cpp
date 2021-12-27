// ans.cpp 14 Nov 17, 17:51:50 0 2.13 Judging completed in 6.149s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h,w,n,ans=0;
    cin>>h>>w>>n;
    map<pair<int,int>,bool> mp;
    int arr[h][w];
    for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
            cin>>arr[x][y];
        }
    }
    for(int x=0;x<h;x++){
        for(int y=0;y<w;y++){
            if(x+1<h){
                if(mp[make_pair(min(arr[x][y],arr[x+1][y]),max(arr[x][y],arr[x+1][y]))]==0){
                    mp[make_pair(min(arr[x][y],arr[x+1][y]),max(arr[x][y],arr[x+1][y]))]=true;
                    ans++;
                }
            }
            if(y+1<w){
                if(mp[make_pair(min(arr[x][y],arr[x][y+1]),max(arr[x][y],arr[x][y+1]))]==0){
                    mp[make_pair(min(arr[x][y],arr[x][y+1]),max(arr[x][y],arr[x][y+1]))]=true;
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}