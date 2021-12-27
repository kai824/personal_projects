// ans.cpp 28 Nov 20, 13:48:47 61 2.42 Judging completed in 21.333s on AWS Oregon.
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
    ll cur,tmp,prev=pa;
    while(pa>0){
        if(pa==f){
          cur=d-(dist[f]-dist[pa]);
          tmp=f;
        }else{
          tmp=prev;
          if(prev%2)tmp--;
          else tmp++;
          cur=d-(dist[f]+dist[tmp]-dist[pa]-dist[pa]);
        }ans=min(ans,make_pair(abs(d-(dist[f]-dist[pa]) ),pa) );
        //cout<<"G:"<<tmp<<' '<<cur<<' '<<pa<<' '<<prev<<'\n';
        if(dist[f]-dist[pa]>d)break;

        it=mp[tmp].lower_bound(cur);
        if(it!=mp[tmp].end()){
          c1=make_pair(abs(it->first-cur),it->second.first);
          if(c1.second==f)c1.second=it->second.second;

          if(c1.second!=-1)ans=min(c1,ans);
        }
        if(it!=mp[tmp].begin()){
          it--;
          c1=make_pair(abs(it->first-cur),it->second.first);
          if(c1.second==f)c1.second=it->second.second;

          if(c1.second!=-1)ans=min(c1,ans);
        }

        prev=pa;
        pa/=2;
    }
    //cout<<ans.first<<' '<<ans.second<<'\n';
    return ans.second;
}