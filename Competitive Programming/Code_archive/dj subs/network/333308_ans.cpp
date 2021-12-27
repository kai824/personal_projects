// ans.cpp 6 Mar 18, 13:02:27 25 0.16 Judging completed in 5.8s on AWS Oregon.
#include "network.h"
#include<bits/stdc++.h>
using namespace std;
int dist[1005],prev[1005],c,e;
bitset<1005> visited;
void ans(int end){
    travelTo(prev[end]);
    if(prev[prev[end]]==-1)return;
    ans(prev[end]);
}
void findRoute (int n, int a, int b){
    if(a==b)return;
    swap(a,b);
    e=a;
    queue<int> bfs;//stores stuff explored...
    dist[a]=-1;
    prev[a]=-1;
    visited[a]=1;
    for(int x=1;x<=n;x++){
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
        for(int x=1;x<=n;x++){
            if(visited[x]==1)continue;
            if(dist[x]>dist[c]+1)continue;
            if(ping(c,x)==0){
                visited[x]=1;
                prev[x]=c;
                if(x==b){
                    ans(b);
                    return;
                }
                bfs.push(x);
            }
        }
    }
}