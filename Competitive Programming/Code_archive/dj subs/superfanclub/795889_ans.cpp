// ans.cpp 28 Nov 20, 14:08:27 61 2.39 Judging completed in 14.904s on AWS Oregon.
#include "superfanclub.h"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int pa,n;
ll dist[270000];//"dist" from root node
map<ll,int> mp[270000];//dist, to 2 nodes...
map<ll,int>::iterator it;

void init(int N, int s[]) {//start from s[2] to s[1<<n]
    dist[1]=0;
    n=N;
    //mp[1][0]=make_pair(1,-1);
    for(int x=2;x<=(1<<n)-1;x++){
        pa=x/2;//parent...
        dist[x]=dist[pa]+s[x];
        //mp[x][0]=make_pair(x,-1);
        while(pa>0){
            if(mp[pa].find(dist[x]-dist[pa])==mp[pa].end()){
              mp[pa][dist[x]-dist[pa]]=x;
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
          ans=min(ans,make_pair(abs(cur),int(tmp)) );
        }ans=min(ans,make_pair(abs(d-(dist[f]-dist[pa]) ),pa) );
        //cout<<"G:"<<tmp<<' '<<cur<<' '<<pa<<' '<<prev<<'\n';
        if(dist[f]-dist[pa]>d)break;
        if(cur>=0){
            it=mp[tmp].lower_bound(cur);
            if(it!=mp[tmp].end()){
              c1=make_pair(abs(it->first-cur),it->second);
    
              ans=min(c1,ans);
            }
            if(it!=mp[tmp].begin()){
              it--;
              c1=make_pair(abs(it->first-cur),it->second);
    
              ans=min(c1,ans);
            }
        }

        prev=pa;
        pa/=2;
    }
    //cout<<ans.first<<' '<<ans.second<<'\n';
    return ans.second;
}