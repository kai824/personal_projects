// ans.cpp 7 Mar 18, 19:38:19 100 0.14 Judging completed in 6.252s on AWS Oregon.
#include <bits/stdc++.h>
#include "network.h"
using namespace std;
vector<int> layers[1005];
vector<int> nodes;
deque<int> route;
void findRoute(int n,int a,int b){
    nodes.push_back(-1);
    for(int x=1;x<=n;x++){
        if(x!=a){
            int k=ping(a,x);
            layers[k+1].push_back(x);
            nodes.push_back(k+1);
        }else{
            layers[0].push_back(a);
            nodes.push_back(0);
        }
    }
    int cur_node=b;
    while(nodes[cur_node]!=0){
        route.push_front(cur_node);
        int level=nodes[cur_node];
        for(int i=0;i<layers[level-1].size();i++){
            int v=layers[level-1][i];
            int k=ping(cur_node,v);
            if(k==0){
                cur_node=v;
                break;
            }
        }
    }
    for(int i=0;i<route.size();i++){
        travelTo(route[i]);
    }
}