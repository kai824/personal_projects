// ans.cpp 28 Nov 20, 12:17:19 0 2.43 Judging completed in 23.406s on AWS Oregon.
#include "superfanclub.h"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int pa,n;
ll dist[270000];//"dist" from root node
set<pair<ll,int> > ms[270000];//set of distance,node to all children...
set<pair<ll,int> >::iterator it;

void init(int N, int s[]) {//start from s[2] to s[1<<n]
    dist[1]=0;
    n=N;
    ms[1].emplace(0,1);
    for(int x=2;x<=(1<<n)-1;x++){
        pa=x/2;//parent...
        dist[x]=dist[pa]+s[x];
        ms[x].emplace(0,x);
        while(pa>0){
            ms[pa].emplace(dist[x]-dist[pa],x);
            pa/=2;
        }
    }
}

pair<ll,int> c1,ans;

int find_closest(int f,ll d){
    ans=make_pair(d,f);
    pa=f;
    ll cur;
    while(pa>0){
        cur=d-(dist[f]-dist[pa]);
        ms[pa].erase(make_pair(dist[f]-dist[pa],f) );
        it=ms[pa].lower_bound(make_pair(cur,-1) );
        if(it!=ms[pa].end()){
          c1=make_pair(abs(cur-it->first),it->second);
          ans=min(ans,c1);
        }
        if(it!=ms[pa].begin()){
            it--;
            c1=make_pair(abs(cur-it->first),it->second);
            ans=min(ans,c1);
        }

        ms[pa].insert(make_pair(dist[f]-dist[pa],f) );
        pa/=2;
    }
    return ans.second;
}