// ans.cpp 28 Nov 20, 14:29:19 100 0.76 Judging completed in 9.682s on AWS Oregon.
#include "superfanclub.h"
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define eb emplace_back

int pa,n;
ll dist[270000];//"dist" from root node
vector<pair<ll,int> >mp[270000],v;//dist, to 2 nodes...
vector<pair<ll,int> >::iterator it;

void init(int N, int s[]) {//start from s[2] to s[1<<n]
    dist[1]=0;
    n=N;
    //mp[1][0]=make_pair(1,-1);
    for(int x=2;x<=(1<<n)-1;x++){
        pa=x/2;//parent...
        dist[x]=dist[pa]+s[x];
        //mp[x][0]=make_pair(x,-1);
        while(pa>0){
            mp[pa].eb(dist[x]-dist[pa],x);
            pa/=2;
        }
    }
    for(int x=1;x<=(1<<n)-1;x++){
      if(mp[x].size()==0)continue;
      sort(mp[x].begin(),mp[x].end());
      v.clear();
      v.push_back(mp[x][0]);
      for(int i=1;i<mp[x].size();i++){
        if(mp[x][i].first>mp[x][i-1].first)v.push_back(mp[x][i]);
      }
      swap(v,mp[x]);
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
            it=lower_bound(mp[tmp].begin(),mp[tmp].end(),make_pair(cur,-1));
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