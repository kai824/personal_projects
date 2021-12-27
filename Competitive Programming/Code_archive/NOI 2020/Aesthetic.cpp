#include"bits/stdc++.h"
using namespace std;

#define int long long
#define mp make_pair
#define pii pair<int,int>

vector<pair<int,pii> > adjl[300005],adjl2[300005];//nex node, weight, and how much can increase by

int n,m,dist[300005],distn[300005],depth[300005],back[300005],parent[300005];
pii xx[300005];

void dfs(int node,int dd,int prev=-1){//find the dfs tree in adjl2
  //returns if node n is a descendant...
  depth[node]=back[node]=dd;
  parent[node]=prev;
  sort(adjl2[node].begin(),adjl2[node].end());
  for(int i=0;i<adjl2[node].size();i++){
    if(i>0 && adjl2[node][i].first==adjl2[node][i-1].first){
      continue;
    }
    if(adjl2[node][i].first==prev)continue;
    if(depth[adjl2[node][i].first]!=-1){
      back[node]=min(back[node],depth[adjl2[node][i].first]);
      continue;
    }
    xx[adjl2[node][i].first]=adjl2[node][i].second;
    dfs(adjl2[node][i].first,dd+1,node);
    back[node]=min(back[node],back[adjl2[node][i].first]);
  }
}
bool backtrack(int node,int l){
  if(node==1)return false;
  if(back[node]>=depth[node]){//no back edge...
    if(dist[parent[node]]+distn[node]+xx[node].first+xx[node].second>=l){
      //cerr<<"Bridge between "<<node<<" "<<parent[node]<<'\n';
      return true;
    }
  }
  return backtrack(parent[node],l);
}
bool poss(int l){
  for(int x=1;x<=n;x++){
    adjl2[x].clear();
    back[x]=depth[x]=-1;
  }
  for(int x=1;x<=n;x++){
    for(int i=0;i<adjl[x].size();i++){
      if(dist[x]+adjl[x][i].second.first+distn[adjl[x][i].first]<l){
        adjl2[x].push_back(adjl[x][i]);//edge is L-relevant
        adjl2[adjl[x][i].first].push_back(make_pair(x,adjl[x][i].second) );
        //cerr<<"Taken edge "<<x<<' '<<adjl[x][i].first<<'\n';
      }
    }
  }
  dfs(1,0);
  if(depth[n]==-1){//can't even reach node n LOL
    return false;
  }
  for(int x=1;x<=n;x++){
    //cerr<<depth[x]<<' '<<parent[x]<<'\n';
  }
  return backtrack(n,l);
}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    int a,b,c,inc=0;
    vector<pair<pii,int> >el;
    for(int x=0;x<m;x++){
      cin>>a>>b>>c;
      el.emplace_back(mp(a,b),c);
    }
    while(el.size()>0){
      a=el.back().first.first;
      b=el.back().first.second;
      adjl[a].emplace_back(b,mp(el.back().second,inc));
      adjl[b].emplace_back(a,mp(el.back().second,inc));
      inc=max(inc,el.back().second);
      el.pop_back();
    }

    int node;
    priority_queue<pii,vector<pii>,greater<pii> > dijk;
    for(int x=1;x<=n;x++)dist[x]=distn[x]=1e18;
    dist[1]=distn[n]=0;
    dijk.emplace(0,1);
    while(!dijk.empty()){
      node=dijk.top().second;
      dijk.pop();
      for(int i=0;i<adjl[node].size();i++){
        if(dist[node]+adjl[node][i].second.first<dist[adjl[node][i].first]){
          dist[adjl[node][i].first]=dist[node]+adjl[node][i].second.first;
          dijk.emplace(dist[adjl[node][i].first],adjl[node][i].first);
        }
      }
    }
    dijk.emplace(0,n);
    while(!dijk.empty()){
      node=dijk.top().second;
      dijk.pop();
      for(int i=0;i<adjl[node].size();i++){
        if(distn[node]+adjl[node][i].second.first<distn[adjl[node][i].first]){
          distn[adjl[node][i].first]=distn[node]+adjl[node][i].second.first;
          dijk.emplace(distn[adjl[node][i].first],adjl[node][i].first);
        }
      }
    }

    int lo,hi,mid;
    lo=dist[n];
    hi=dist[n]+inc;

    /*cout<<poss(4);
    cout<<lo<<' '<<hi<<'\n';
    return 0;*/

    //cout<<lo<<' '<<hi<<'\n';
    /*for(int i=1;i<=20;i++){
      cout<<poss(i);
    }return 0;*/

    while(lo<hi){
      mid=hi-((hi-lo)/2);
      //find the largest case where poss(lo)==true
      if(poss(mid)){//exists a way to force path length above mid
        lo=mid;
      }else hi=mid-1;
    }
    cout<<lo;
    return 0;
}

/*
6 8
5 6 2
3 1 4
1 2 2
6 2 3
5 3 3
3 2 1
4 6 3
2 4 2

5 6
1 2 1
4 3 1
2 4 1
3 2 1
1 3 1
4 5 1
*/
