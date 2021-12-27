#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define int long long
typedef pair<int,int> pii;
#define mp make_pair
#define eb emplace_back

const int mxm=100005,inf=1e17;

pair<pii,pii> pts[mxm];int nex=0;

int dist[mxm];

#define ls(x) (x&(-x))
#define min(a,b) ((a<b)?a:b)
namespace{//diagonal 1
  vector<pair<pii,int> > v[2];
  int ft[2][mxm];
  int ind[2][mxm],rig[2][mxm];

  void init(int i){
    sort(v[i].rbegin(),v[i].rend());//descending for fenwick purposes...
    vector<pii> haiz;
    for(int j=v[i].size()-1;j>=0;j--){//
      ind[i][v[i][j].s]=j;//the easy one...
      haiz.eb(v[i][j].f.s,j);
      cout<<v[i][j].f.s<<' '<<v[i][j].f.f<<' '<<v[i][j].s<<'\t';
    }cout<<'\n';
    sort(haiz.begin(),haiz.end());
    int cur=haiz.size();
    for(int j=0;j<haiz.size();j++){
      while(cur>0 && v[i][cur-1].f.f>=haiz[j].f)cur--;
      rig[i][haiz[j].s]=max(cur,haiz[j].s+1);
    }
    for(int j=haiz.size()-1;j>=0;j--)cout<<rig[i][j]<<'\t';cout<<'\n';

    for(int j=1;j<=nex;j++)ft[i][j]=inf;
  }

  void update(int i,int u,int nv){
    int p=ind[i][u]+1;//find index in v...
    //cerr<<"Update "<<i<<' '<<p<<'\n';
    for(;p<=nex;p+=ls(p))ft[i][p]=min(ft[i][p],nv);
  }
  int query(int i,int p){
    int ans=inf;
    p=rig[i][ind[i][p]]+1;
    //cerr<<"Query "<<i<<' '<<p<<'\n';
    for(;p;p-=ls(p))ans=min(ans,ft[i][p]);
    return ans;
  }
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,m,ans=inf;
  cin>>n>>m;

  for(int i=0;i<m;i++){
    int t,l,r,c;
    cin>>t>>l>>r>>c;r++;
    pts[nex++]=mp(mp(r,l),mp(t,c));
  }
  sort(pts,pts+nex);
  for(int i=0;i<nex;i++){
    int t=pts[i].s.f;
    int l=pts[i].f.s,r=pts[i].f.f;
    v[0].eb(mp(t+r,t+l),i);
    v[1].eb(mp(-t+r,-t+l),i);
  }
  for(int i=0;i<2;i++)init(i);

  for(int i=0;i<nex;i++){
    //compute dist[i]...
    dist[i]=inf;
    for(int j=0;j<2;j++){
      dist[i]=min(dist[i],query(j,i));
    }
    if(pts[i].f.s==1)dist[i]=min(dist[i],0);
    dist[i]+=pts[i].s.s;
    cout<<pts[i].f.s<<' '<<pts[i].f.f<<'\t'<<dist[i]<<'\n';

    //update...
    for(int j=0;j<2;j++){
      if(dist[i]<inf)update(j,i,dist[i]);
    }

    if(pts[i].f.f==n+1)ans=min(ans,dist[i]);
  }

  if(ans==inf)cout<<"-1\n";
  else cout<<ans<<'\n';
}
