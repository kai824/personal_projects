#include"bits/stdc++.h"
using namespace std;
#define pii pair<int,int>
#define mp make_pair

int dist[1000005],ans,max_d,nex;//no. of grids dist d away...
int xx[4]={0,0,-1,1};
int yy[4]={-1,1,0,0};

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,r,c,a,b;
  cin>>n>>m>>r>>c;
  pii pp[n];//n children...
  bool marked[r][c];
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++)marked[i][j]=false;
  }
  for(int i=0;i<n;i++){
    cin>>pp[i].first>>pp[i].second;
  }
  sort(pp,pp+n);

  deque<pair<int,pii> > bfs;//distance, coord...
  for(int i=0;i<m;i++){
    cin>>a>>b;
    a--;b--;//make 0-indexed
    if(marked[a][b])continue;
    marked[a][b]=true;
    dist[0]++;
    bfs.emplace_back(0,mp(a,b) );
  }
  while(bfs.size()>0){
    a=bfs.front().second.first;
    b=bfs.front().second.second;
    for(int i=0;i<4;i++){
      if(a+xx[i]<0 || b+yy[i]<0)continue;
      if(a+xx[i]>=r || b+yy[i]>=c)continue;//ensure in grid...

      if(marked[a+xx[i]][b+yy[i]])continue;//visited...
      marked[a+xx[i]][b+yy[i]]=true;
      bfs.emplace_back(bfs.front().first+1,mp(a+xx[i],b+yy[i]) );
      dist[bfs.front().first+1]++;
      max_d=bfs.front().first+1;
    }
    bfs.pop_front();
  }

  priority_queue<int,vector<int>,greater<int> > pq;//store the "upper limits..."
  for(int i=0;i<=max_d;i++){//at distance i...
    //update the pq storing kids who can sleep here......
    while(nex<n && pp[nex].first<=i){
      pq.push(pp[nex].second);
      nex++;
    }
    while(!pq.empty() && pq.top()<i)pq.pop();
    while(dist[i]>0 && !pq.empty()){
      pq.pop();
      ans++;
      dist[i]--;
    }
  }
  cout<<ans;
  return 0;
}
/*
4 2 2 4
0 0
2 2
1 2
3 4
1 1
1 3
*/
