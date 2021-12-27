// graphcraft.cpp 19 Nov 19, 16:37:01 0 0 Compilation failed on AWS Oregon.
#include "graphcraft.h"
#include <vector>
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
            if(craft(v[item][x].first])==-1)return -1;
        }
        w+=cost[v[item][x].first]*v[item][x].second;w%=m;
    }
    crafting[item]=false;
    crafted[item]=true;cost[item]=w;
    return w;
}

int graphcraft(int nn, int c, vector< pair<int, int> > V[]) {
    n=nn;
    cost[0]=1;crafted[0]=true;
    return craft(c);
}