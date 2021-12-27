// ans.cpp 14 Nov 17, 20:46:58 100 0.06 Judging completed in 5.908s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dist[1030][1030],h,w,a,b,ex,ey;//distances...
int xx[4]={0,0,1,-1};
int yy[4]={-1,1,0,0};
string mp[1030];
bool ok(int x,int y){//h, w
    return(0<=x&&x<h&&0<=y&&y<w);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    queue<pair<int,int> > bfs;
    cin>>h>>w;
    for(int x=0;x<h;x++){
        cin>>mp[x];
        for(int y=0;y<w;y++){
            if(mp[x][y]=='S'){
                bfs.push(make_pair(x,y));
    dist[x][y]=1;//add 1 extra so that we know 0 means not read
            }
            if(mp[x][y]=='E'){
                ex=x;ey=y;
            }
        }
    }
    while(!bfs.empty()){
        for(int x=0;x<4;x++){
            a=bfs.front().first+xx[x];
            b=bfs.front().second+yy[x];
            if(!ok(a,b))continue;
            if(mp[a][b]=='#'){
            	a+=xx[x];b+=yy[x];
            }
            if(!ok(a,b))continue;
            if(mp[a][b]=='#')continue;
            if(dist[a][b]==0||dist[a][b]>dist[bfs.front().first][bfs.front().second]+1){
                dist[a][b]=dist[bfs.front().first][bfs.front().second]+1;
                bfs.push(make_pair(a,b));
            }
        }
        bfs.pop();
    }
    cout<<dist[ex][ey]-1;
    return 0;
}