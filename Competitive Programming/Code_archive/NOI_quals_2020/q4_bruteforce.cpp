#include "bits/stdc++.h"
using namespace std;

#define int long long

vector<pair<int,int> > adjl[20];
int n,k;//distance from root node...

bool vis[20];

void dfs(int node,int dist,int prev=-1){
  vis[node]=true;
  for(int x=0;x<adjl[node].size();x++){
    if(adjl[node][x].second+dist>k)continue;//too far...
    if(adjl[node][x].first==prev)continue;
    dfs(adjl[node][x].first,dist+adjl[node][x].second,node);
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int a,b,c,d,bb=-1;
  bool broke;
  cin>>n>>k;//where k is the max distance...
  if(n>17){
    cout<<n<<'\n';
    for(int x=1;x<=n;x++){
      cout<<x;
      if(x<n)cout<<' ';
    }
    return 0;
  }
  for(int x=1;x<n;x++){
    cin>>a>>b>>c;
    adjl[a].emplace_back(b,c);
    adjl[b].emplace_back(a,c);
  }
  a=INT_MAX;//ans...
  queue<pair<int,int> > bfs;
  for(int b=1;b<(1LL<<n);b++){//brute force every bitmask of taking nodes...
    for(int x=1;x<=n;x++){
      vis[x]=false;
    }
    c=0;
    for(int x=0;x<n;x++){
      if((1LL<<x)&b){
        c++;
        dfs(x+1,0);
      }
    }
    broke=false;
    for(int x=1;x<=n;x++){
      if(vis[x]==false){
        broke=true;
        break;
      }
    }
    if(broke==false){
      if(c<a){
        a=c;
        bb=b;//use this bitmask...
      }
    }
  }
  cout<<a<<'\n';
  broke=true;//first thing...
  for(int x=0;x<n;x++){
    if(((1LL<<x)&bb)==0)continue;
    if(broke==false)cout<<' ';
    broke=false;
    cout<<x+1;
  }
  return 0;
}
/*
9 4
1 2 10
2 3 4
8 9 4
8 7 3
7 3 5
3 4 1
4 5 3
5 6 2

ans:
cost 4
*/
