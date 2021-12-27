// ans.cpp 19 Oct 17, 22:19:46 100 0 Judging completed in 6.848s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool visited[1005],pasture[1005];
       //visited? ,pasture?
int distances[1005];
int main() {
    int n,a,b,c;
    cin>>n;
    pair<int,int> e[n];
    for(int x=1;x<n;x++){
        cin>>a>>b>>c;
        e[a]=make_pair(b,c);
        if(b==0||c==0)pasture[a]=true;
    }
    a=0;
    queue<int>bfs;
    bfs.push(1);
    visited[1]=true;
    distances[1]=1;
    while(!bfs.empty()){
        if(pasture[bfs.front()]){
            a=max(a,distances[bfs.front()]);
        }
        if(e[bfs.front()].first!=0 && visited[e[bfs.front()].first]==false){
            bfs.push(e[bfs.front()].first);
            distances[e[bfs.front()].first]=distances[bfs.front()]+1;
        }
        if(e[bfs.front()].second!=0 && visited[e[bfs.front()].second]==false){
            bfs.push(e[bfs.front()].second);
            distances[e[bfs.front()].second]=distances[bfs.front()]+1;
        }
        bfs.pop();
    }
    cout<<a;
    return 0;
}