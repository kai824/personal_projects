// ans.cpp 30 Apr 17, 16:16:56 100 0.12 Judging completed in 6.418s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int xdir[4]={0,0,-1,1};
int ydir[4]={-1,1,0,0};
int main() {
    int h,w,x,y,t;
    cin>>h>>w>>x>>y>>t;
    queue<pair<int,int> > bfs;
    int image[h][w];
    bool ans[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>image[i][j];
            ans[i][j]=0;
        }
    }
    bfs.push(make_pair(x-1,y-1));
    ans[x-1][y-1]=1;
    while(!bfs.empty()){
        for(int i=0;i<4;i++){
            if(bfs.front().first+xdir[i]<0 || bfs.front().first+xdir[i]>=h || bfs.front().second+ydir[i]<0 || bfs.front().second+ydir[i]>=w){
        		continue;
        	}
            if(abs(image[bfs.front().first+xdir[i]][bfs.front().second+ydir[i]]-image[x-1][y-1])<=t && ans[bfs.front().first+xdir[i]][bfs.front().second+ydir[i]]==0){
                bfs.push(make_pair(bfs.front().first+xdir[i],bfs.front().second+ydir[i]));
                ans[bfs.back().first][bfs.back().second]=1;
            }
        }
        bfs.pop();
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
    return 0;
}