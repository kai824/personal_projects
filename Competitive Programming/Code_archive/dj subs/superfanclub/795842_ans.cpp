// ans.cpp 28 Nov 20, 12:32:50 0 2.43 Judging completed in 13.737s on AWS Oregon.
#include "superfanclub.h"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int pa,n;
ll dist[270000];//"dist" from root node
map<ll,pair<int,int> > mp[270000];//dist, to 2 nodes...
map<ll,pair<int,int> >::iterator it;

void init(int N, int s[]) {//start from s[2] to s[1<<n]
    dist[1]=0;
    n=N;
    mp[1][0]=make_pair(1,-1);
    for(int x=2;x<=(1<<n)-1;x++){
        pa=x/2;//parent...
        dist[x]=dist[pa]+s[x];
        mp[x][0]=make_pair(x,-1);
        while(pa>0){
            if(mp[pa].find(dist[x]-dist[pa])==mp[pa].end()){
              mp[pa][dist[x]-dist[pa]]=make_pair(x,-1);
            }else{
              if(mp[pa][dist[x]-dist[pa]].second==-1)mp[pa][dist[x]-dist[pa]].second=x;
              //2 smallest nodes will do, since pick smallest node ID
            }
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
        it=mp[pa].lower_bound(cur);
        if(it!=mp[pa].end()){
          c1=make_pair(abs(it->first-cur),it->second.first);
          if(c1.second==f)c1.second=it->second.second;
          
          if(c1.second!=-1)ans=min(c1,ans);
        }
        if(it!=mp[pa].begin()){
          it--;
          c1=make_pair(abs(it->first-cur),it->second.first);
          if(c1.second==f)c1.second=it->second.second;

          if(c1.second!=-1)ans=min(c1,ans);
        }

        pa/=2;
    }
    return ans.second;
}