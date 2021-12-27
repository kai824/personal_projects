// ans.cpp 6 Dec 19, 18:15:44 100 0.74 Judging completed in 5.025s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dist[400005];
bool vis[400005];
vector<int> adjlis[400005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,e,a,b,c;
    cin>>n>>e;
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjlis[a*2+c].push_back(b*2+1-c);
        adjlis[b*2+c].push_back(a*2+1-c);
    }
    queue<int> bfs;
    bfs.push(0);bfs.push(1);
    dist[0]=dist[1]=0;
    vis[0]=vis[1]=true;
    while(!bfs.empty()){
        a=bfs.front();bfs.pop();
        if(a/2==n-1){
            cout<<dist[a];return 0;
        }
        for(int x=0;x<adjlis[a].size();x++){
            if(vis[adjlis[a][x]])continue;
            vis[adjlis[a][x]]=true;
            dist[adjlis[a][x]]=dist[a]+1;
            bfs.push(adjlis[a][x]);
        }
    }
    cout<<-1;
    return 0;
}