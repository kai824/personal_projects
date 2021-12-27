// ans.cpp 25 Sep 17, 21:21:45 100 0 Judging completed in 2.919s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int xi[8]={0,0,1,1,1,-1,-1,-1};
int yi[8]={1,-1,-1,0,1,-1,0,1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h,w,xx,yy,maxi=0;
    pair<int,int> coords;
    cin>>w>>h>>coords.second>>coords.first;
    coords.first=h-coords.first;
    coords.second--;
    string mp[h];
    for(int x=0;x<h;x++){
        cin>>mp[x];
    }
    queue<pair<pair<int,int>,int> >bfs;
    bfs.push(make_pair(coords,0));
    //coords.first,coords.second,distance...
    while(!bfs.empty()){
        maxi=max(maxi,bfs.front().second);
        for(int x=0;x<8;x++){
            xx=bfs.front().first.first+xi[x];
            yy=bfs.front().first.second+yi[x];
            if(xx>=0 && xx<h && yy>=0 && yy<w && mp[xx][yy]!='*'){
                bfs.push(make_pair(make_pair(xx,yy),bfs.front().second+1));
                mp[xx][yy]='*';
            }
        }
        bfs.pop();
    }
    cout<<maxi;
    return 0;
}