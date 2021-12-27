// graphcraft.cpp 19 Nov 19, 16:50:23 100 0.1 Judging completed in 7.62s on AWS Oregon.
#include "graphcraft.h"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
bool crafted[100005],crafting[100005];
ll cost[100005];
vector< pair<int, int> > v[100005];
ll m=1e9+7,n;

ll craft(int item){
    if(crafting[item]==true)return -1;//cycle...
    crafting[item]=true;
    ll w=0;
    for(int x=0;x<v[item].size();x++){
        if(crafted[v[item][x].first]==false){
            if(craft(v[item][x].first)==-1)return -1;
        }
        w+=cost[v[item][x].first]*v[item][x].second;w%=m;
    }
    crafting[item]=false;
    crafted[item]=true;cost[item]=w;
    return w;
}

int graphcraft(int nn, int c, vector< pair<int, int> > V[]) {
    n=nn;
	for(int x=0;x<100000;x++){
		for(int y=0;y<V[x].size();y++){
			v[x].push_back(V[x][y]);
		}
	}
    cost[0]=1;crafted[0]=true;
	return craft(c);
}