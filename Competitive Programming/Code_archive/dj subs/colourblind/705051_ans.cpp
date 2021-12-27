// ans.cpp 25 Feb 20, 07:58:03 0 0.93 Judging completed in 7.516s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<ll,ll> pii;

vector<pii> v;//for binary search
vector<pair<ll,pair<pii,pii> > > edges;
ll k1,k2,ans=0;//ans is how much k-similarity can you handle...

ll values[705][705][6];
//min max min max...
pii parent[705][705];
pii getr(pii node){
  if(parent[node.first][node.second]==mp(-1ll,-1ll))return node;
  parent[node.first][node.second]=getr(parent[node.first][node.second]);
  return parent[node.first][node.second];
}
bool first=true;
inline void merge(pii a,pii b){
  a=getr(a);b=getr(b);
  if(a==b)return;//shouldn't happen
  for(int z=0;z<6;z+=2){
    ans=max(ans,values[b.first][b.second][z+1]-values[a.first][a.second][z]);
    ans=max(ans,values[a.first][a.second][z+1]-values[b.first][b.second][z]);
  }
  for(int z=0;z<6;z+=2){
    values[b.first][b.second][z]=min(values[b.first][b.second][z],values[a.first][a.second][z]);
  }
  for(int z=1;z<6;z+=2){
    values[b.first][b.second][z]=max(values[b.first][b.second][z],values[a.first][a.second][z]);
  }
  parent[a.first][a.second]=b;
}


void init(int H,int W,int Q,int S,vector<vector<ll> >R,vector<vector<ll> >G,vector<vector<ll> >B){
	//a lot of weird shit...
	swap(H,W);
  //pixels[0]=R;pixels[1]=G;pixels[2]=B;
  for(int x=0;x<H;x++){
    for(int y=0;y<W;y++){
      parent[x][y]=mp(-1,-1);
      values[x][y][0]=values[x][y][1]=R[x][y];
      values[x][y][2]=values[x][y][3]=G[x][y];
      values[x][y][4]=values[x][y][5]=B[x][y];
    }
  }
  for(int x=0;x<H;x++){
    for(int y=0;y<W;y++){
        if(x<H-1){
      k1=max(abs(R[x][y]-R[x+1][y]),max(abs(G[x][y]-G[x+1][y]),abs(B[x][y]-B[x+1][y])));
      edges.push_back(mp(k1,mp(mp(x,y),mp(x+1,y)) ));}
      if(y<W-1){
      k2=max(abs(R[x][y]-R[x][y+1]),max(abs(G[x][y]-G[x][y+1]),abs(B[x][y]-B[x][y+1])));
      edges.push_back(mp(k2,mp(mp(x,y),mp(x,y+1)) ));}
    }
  }
  sort(edges.begin(),edges.end());
  for(int i=0;i<edges.size();i++){
    if(getr(edges[i].second.first)==getr(edges[i].second.second)){
        if(i==edges.size()-1||edges[i].first!=edges[i+1].first){
          if(ans>0)v.emplace_back(edges[i].first,ans);
          //cout<<v.back().first<<' '<<v.back().second<<'\n';
        }
      continue;
    }
    merge(edges[i].second.first,edges[i].second.second);
    if(i==edges.size()-1||edges[i].first!=edges[i+1].first){
      if(ans>0)v.emplace_back(edges[i].first,ans);
      //cout<<v.back().first<<' '<<v.back().second<<'\n';
    }
  }
}

ll lo,hi,mid;
bool query(ll C){
  /*if(C==0)return false;
  if(edges.size()==0)return false;
  //if(v.size()==0)return true;
  if(C<v[0].first||v.size()==0){
    return false;
  }
  lo=0;hi=v.size()-1;
  while(lo<hi){
    mid=hi-(hi-lo)/2;
    if(v[mid].first<=C){
      lo=mid;
    }else hi=mid-1;
  }
  if(v[lo].second>C){
    return true;
  }*/
  return false;
}