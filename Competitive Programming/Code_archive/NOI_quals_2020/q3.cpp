#include "bits/stdc++.h"
using namespace std;

#define int long long
typedef pair<int,int> pii;

int n,m,k,special[100005];
pii vis[100005];//distance, start node...
vector<pii> adjl[100005];

void main2(){//multi-source dijkstra...
  priority_queue<pair<int,pii>,vector<pair<int,pii> >,greater<pair<int,pii> > > pq;
  //distance, start node, node...
  int a,b,c,ans=1e15;
  for(int x=0;x<m;x++){
    cin>>a>>b>>c;
    adjl[a].emplace_back(b,c);
    adjl[b].emplace_back(a,c);
  }
  for(int x=0;x<k;x++){
    cin>>a;
    if(a==1 || a==2)continue;//since we can always just connect city 1 and 2...
    pq.emplace(0,make_pair(a,a));
    vis[a]=make_pair(0,a);
  }
  while(!pq.empty()){
    a=pq.top().first;//dist
    b=pq.top().second.first;//start node
    c=pq.top().second.second;//cur node...
    pq.pop();
    if(vis[c]!=make_pair(a,b)){
      //ppl have updated us, so we're now outdated and useless...
      continue;
    }
    for(int x=0;x<adjl[c].size();x++){
      if(vis[adjl[c][x].first].second!=0){
        if(vis[adjl[c][x].first].second!=b){//it comes from a different starting node!!
          ans=min(ans,a+adjl[c][x].second+vis[adjl[c][x].first].first);
          //distance we need to go there, and old distance needed
          if(a+adjl[c][x].second<vis[adjl[c][x].first].first){
            vis[adjl[c][x].first]=make_pair(a+adjl[c][x].second,b);
            pq.emplace(a+adjl[c][x].second,make_pair(b,adjl[c][x].first));
          }
        }
        continue;
      }
      vis[adjl[c][x].first]=make_pair(a+adjl[c][x].second,b);
      pq.emplace(a+adjl[c][x].second,make_pair(b,adjl[c][x].first));
    }
  }
  cout<<ans+1<<'\n';//since there's also the 1-2 edge...
}

int adjmat[505][505];

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  cin>>n>>m>>k;
  int a,b,c,d,ans=1e15;
  int aa,bb,cc,dd;
  if(n>500){
    main2();
    return 0;
  }
  for(int x=1;x<=n;x++){
    for(int y=1;y<=n;y++)adjmat[x][y]=1e15;
  }
  for(int x=0;x<m;x++){
    cin>>a>>b>>c;
    adjmat[a][b]=min(adjmat[a][b],c);
    adjmat[b][a]=min(adjmat[b][a],c);
  }
  for(int x=1;x<=n;x++){
    for(int y=1;y<=n;y++){
      for(int z=1;z<=n;z++){
        adjmat[y][z]=min(adjmat[y][z],adjmat[y][x]+adjmat[x][z]);
      }
    }
  }
  for(int x=0;x<k;x++){
    cin>>special[x];
  }
  vector<pair<int,pair<int,int> > > v;
  for(int x=0;x<k;x++){
    for(int y=x+1;y<k;y++){
      a=special[x];
      b=special[y];
      v.emplace_back(adjmat[a][b],make_pair(a,b));
    }
  }
  sort(v.begin(),v.end());
  for(int x=0;x<10 && x<v.size();x++){
    for(int y=x+1;y<10 && y<v.size();y++){//try to take v[x] and v[y];
      a=v[x].second.first;b=v[x].second.second;
      c=v[y].second.first;d=v[y].second.second;
      if(a==c || a==d || b==c || b==d){
        continue;//not valid...
      }
      if(v[x].first+v[y].first<ans){
        ans=v[x].first+v[y].first;
        aa=a;bb=b;
        cc=c;dd=d;
      }
    }
  }
  cout<<ans<<'\n';
  return 0;
}
/*
5 4 4
1 2 1
3 4 2
4 5 5
5 3 8
3 1 5 2
*/
