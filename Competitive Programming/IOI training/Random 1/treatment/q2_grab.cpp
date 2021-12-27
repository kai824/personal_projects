#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define int long long
typedef pair<int,int> pii;
#define mp make_pair
#define eb emplace_back

const int mxm=200005,inf=1e17;
int t[mxm],l[mxm],r[mxm],c[mxm];
vector<int> adj[mxm];
int dist[mxm];bool vis[mxm];

vector<pii> adjl[mxm];
void main1(int n,int m){
  vector<pair<int,pii> >disc;int nex=1;
  disc.eb(1,mp(-1,-1));
  disc.eb(n+1,mp(-1,-1));
  for(int i=0;i<m;i++){
    cin>>t[i]>>l[i]>>r[i]>>c[i];
    disc.eb(l[i],mp(i,0));//edge from l[i] to r[i]+1
    disc.eb(r[i]+1,mp(i,1));
  }
  sort(disc.begin(),disc.end());
  for(int i=0;i<disc.size();i++){
    if(i>0 && disc[i].f>disc[i-1].f)nex++;
    if(disc[i].s.f==-1)continue;
    if(disc[i].s.s==0){
      l[disc[i].s.f]=nex;
    }else r[disc[i].s.f]=nex;
  }
  for(int i=0;i<m;i++){
    adjl[l[i]].eb(r[i],c[i]);
  }
  for(int i=1;i<=nex;i++)dist[i]=inf;
  for(int i=2;i<=nex;i++)adjl[i].eb(i-1,0);
  priority_queue<pii,vector<pii>,greater<pii> > pq;
  int a;
  pq.emplace(1,0);dist[1]=0;
  while(!pq.empty()){
    a=pq.top().f;
    if(dist[a]<pq.top().s){
      pq.pop();continue;
    }
    pq.pop();
    for(pii x:adjl[a]){
      if(dist[x.f]>dist[a]+x.s){
        dist[x.f]=dist[a]+x.s;
        pq.emplace(x.f,dist[x.f]);
      }
    }
  }
  if(dist[nex]==inf)cout<<"-1\n";
  else cout<<dist[nex]<<'\n';
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m;
  cin>>n>>m;
  //funny how subtasks 1-3 can be done with dijkstra, and ST4 is... 2d segtree with lazy nodes? idk
  if(m>5000){
    main1(n,m);
    return 0;
  }

  for(int i=0;i<m;i++){
    cin>>t[i]>>l[i]>>r[i]>>c[i];
    if(l[i]==1)adj[m].push_back(i);
    if(r[i]==n)adj[i].push_back(m+1);
  }c[m]=c[m+1]=0;

  for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
      //cout<<"Iteration "<<i<<' '<<j<<'\n';
      if(t[i]>t[j])swap(i,j);//ensures t[j]>=t[i]
      int a,b;
      a=l[i]+t[j]-t[i];
      b=r[i]-t[j]+t[i];
      if(l[i]==1)a=1;
      if(r[i]==n)b=n;
      //compare range [a,b] with [l[j],r[j]]
      b++;r[j]++;
      if(b>=l[j])adj[i].push_back(j);
      if(r[j]>=a)adj[j].push_back(i);
      b--;r[j]--;
      if(i>j)swap(i,j);
    }
  }
  for(int i=0;i<m+2;i++)dist[i]=inf;
  dist[m]=0;

  while(true){
    int a=-1;
    for(int i=0;i<m+2;i++){
      if(vis[i])continue;
      if(a==-1 || dist[i]<dist[a])a=i;
    }
    if(a==-1)break;
    vis[a]=true;
    for(int x:adj[a]){
      dist[x]=min(dist[x],dist[a]+c[x]);
    }
  }

  if(dist[m+1]==inf)cout<<"-1\n";
  else cout<<dist[m+1]<<'\n';
}
