// ans.cpp 6 Mar 18, 12:46:00 0 0 Compilation failed on AWS Oregon.
#include "network.h"
using namespace std;
int dist[1005],prev[1005],c;
bitset<1005> visited;
void ans(int end){
    if(prev[end]==-1)return;
    ans(prev[end]);
    travelTo(end);
}
void findRoute (int n, int a, int b){
    if(a==b)return;
    queue<int> bfs;//stores stuff explored...
    dist[a]=-1;
    prev[a]=-1;
    visited[a]=1;
    for(int x=0;x<n;x++){
        if(a==x)continue;
        dist[x]=ping(a,x);
        if(dist[x]==0){
            bfs.push(x);
            visited[x]=1;
            prev[x]=a;
            if(x==b){
                travelTo(b);
                return;
            }
        }
    }
    
    while(!bfs.empty()){
        c=bfs.front();bfs.pop();
        for(int x=0;x<n;x++){
            if(visited[x]==1)continue;
            if(dist[x]>dist[c]+1)continue;
            if(ping(c,x)==0){
                visited[x]=1;
                prev[x]=c;
                if(x==b){
                    ans(b);
                    return;
                }
            }
        }
    }
}