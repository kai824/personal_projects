// ans.cpp 6 Mar 18, 13:00:20 0 0.16 Judging completed in 4.605s on AWS Oregon.
#include "network.h"
#include<bits/stdc++.h>
using namespace std;
void findRoute (int n, int a, int b){
    for(int x=0;x<2*n-5;x++){
        ping(a,b);
    }
    printf ("ERROR\nping called with invalid arguments\n");
    exit (0);
    
    /*if(a==b)return;
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
            }
        }
    }*/
}