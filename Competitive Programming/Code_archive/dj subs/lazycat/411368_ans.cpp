// ans.cpp 12 Nov 18, 20:43:27 100 0.05 Judging completed in 3.237s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
string grid[31];
int id[31][31];//stores id for the food thing
int dist[31][31][1024];//1024 since bitmask
//0 for unvisited
int n,f,solved,nx,ny,nb;
int xx[4]={-1,1,0,0};
int yy[4]={0,0,-1,1};
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>grid[x];
    }
    pair<int,int> s,e;
    for(int x=0;x<n;x++){
        for(int y=0;y<n;y++){
            if(grid[x][y]=='F'){
                id[x][y]=f;
                f++;
            }
            if(grid[x][y]=='S'){
                s.first=x;
                s.second=y;
            }
            if(grid[x][y]=='B'){
                e.first=x;
                e.second=y;
            }
        }
    }
    solved=(1<<f)-1;//everything relevant set to 1...
    deque<pair<pair<int,int>,pair<int,int> > >bfs;
    //x coord, y coord, distance, bitmask
    bfs.push_back(make_pair(s,make_pair(1,0)));
    dist[s.first][s.second][0]=1;
    while(bfs.size()>0){
        for(int x=0;x<4;x++){
            nx=bfs[0].first.first+xx[x];
            ny=bfs[0].first.second+yy[x];
            if(nx<0 || ny<0 || nx>=n || ny>=n){
                //out of range
                continue;
            }
            if(grid[nx][ny]=='X'){
                //wall
                continue;
            }
            nb=bfs[0].second.second;//new bitmask
            if(grid[nx][ny]=='F'){
                nb|=(1<<id[nx][ny]);
            }
            if(dist[nx][ny][nb]==0||dist[nx][ny][nb]>bfs[0].second.first+1){
                //unvisited or found shorter path
                dist[nx][ny][nb]=bfs[0].second.first+1;
                bfs.push_back(make_pair(make_pair(nx,ny),make_pair(dist[nx][ny][nb],nb)));
            }
        }
        bfs.pop_front();
    }
    if(dist[e.first][e.second][solved]==0)cout<<"-1";
    else cout<<dist[e.first][e.second][solved]-1;
    return 0;
}