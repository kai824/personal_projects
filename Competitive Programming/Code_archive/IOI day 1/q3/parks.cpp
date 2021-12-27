#include "parks.h"
#include<bits/stdc++.h>
using namespace std;

#define lnt long long
const lnt inf=1e17;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back

vector<int> u,v,a,b;
vector<pii> p1[200005],p2[200005];

int par[200005];
int getr(int x){
  if(par[x]==-1)return x;
  return par[x]=getr(par[x]);
}
bool merge(int a,int b){
  //cerr<<"MERGE "<<a<<' '<<b<<'\n';
  int aa=getr(a),bb=getr(b);
  if(aa==bb)return false;
  u.push_back(a);v.push_back(b);::a.push_back(0);::b.push_back(0);
  par[aa]=bb;
  return true;
}

map<pii,int> mm;//shouldn't tle right?
pii rmm[400005];
int nex=0;
bool vis[400005];
bool evis[400005];
vector<pii> adjl[400005];//damn high upper bound jic...
void draw(int x1,int y1,int x2,int y2){
  int a,b;//labels of the 2 nodes...
  if(mm.find(mp(x1,y1))==mm.end()){
    mm[mp(x1,y1)]=a=nex++;
    rmm[a]=mp(x1,y1);
  }else a=mm[mp(x1,y1)];
  if(mm.find(mp(x2,y2))==mm.end()){
    mm[mp(x2,y2)]=b=nex++;
    rmm[b]=mp(x2,y2);
  }else b=mm[mp(x2,y2)];

  int i=u.size()-1;

  adjl[a].eb(b,i);adjl[b].eb(a,i);//later just anyhow find a spanning tree? should work...
}
void dfs(int nd,int p=-1){
  vis[nd]=true;
  for(pii x:adjl[nd]){
    if(x.f==p)continue;
    if(vis[x.f])continue;
    a[x.s]=rmm[x.f].f;
    b[x.s]=rmm[x.f].s;
    evis[x.s]=true;
    dfs(x.f,nd);
  }
  if(p==-1){
    for(pii x:adjl[nd]){
      if(!evis[x.s]){//edge not used yet!
        a[x.s]=rmm[nd].f;
        b[x.s]=rmm[nd].s;
        break;
      }
    }
  }
}

vector<pair<pii,pair<pii,pii> > > el[400005];
pair<pii,pair<pii,pii> > tmp;

int construct_roads(vector<int> x, vector<int> y) {
  srand(39);
  u.clear();v.clear();a.clear();b.clear();
  if (x.size()==1){
    build(u,v,a,b);
    return 1;
  }
  int n=x.size();
  for(int i=0;i<n;i++){par[i]=-1;
    p1[y[i]].eb(x[i],i);
    p2[x[i]].eb(y[i],i);
  }
  for(int i=0;i<200005;i+=2){
    if(p2[i].size()==0)continue;
    sort(p2[i].begin(),p2[i].end());
    pii prev=mp(-1e6,-1);
    for(auto x:p2[i]){
      if(x.f-prev.f==2){
        //max of x+y...
        tmp.f=mp(x.s,prev.s);
        tmp.s=mp(mp(i-1,prev.f+1),mp(i+1,prev.f+1));
        el[x.f+i].push_back(tmp);
        // if(merge(x.s,prev.s)){
        //   draw(i-1,prev.f+1,i+1,prev.f+1);//x y x y
        // }
      }
      prev=x;
    }
  }

  for(int i=0;i<200005;i+=2){
    if(p1[i].size()==0)continue;
    sort(p1[i].begin(),p1[i].end());
    pii prev=mp(-1e6,-1);
    for(auto x:p1[i]){
      if(x.f-prev.f==2){
        tmp.f=mp(x.s,prev.s);
        tmp.s=mp(mp(prev.f+1,i-1),mp(prev.f+1,i+1));
        el[x.f+i].push_back(tmp);
        // if(merge(x.s,prev.s)){
        //   draw(prev.f+1,i-1,prev.f+1,i+1);//x y x y
        // }
      }
      prev=x;
      swap(prev,prev);
    }
  }
  for(int i=0;i<=400000;i+=2){
    // shuffle el[i]...
    for(int j=0;j<el[i].size();j++){
      swap(el[i][j],el[i][rand()%(j+1)]);
    }
    for(auto x:el[i]){
      if(merge(x.f.f,x.f.s)){
        draw(x.s.f.f,x.s.f.s,x.s.s.f,x.s.s.s);
      }
    }
  }

  int aa=getr(0);
  for(int i=1;i<n;i++){
    if(getr(i)!=aa)return 0;
  }
  //draw the stuff...
  for(int i=0;i<nex;i++){
    if(vis[i]==false)dfs(i);
  }
  for(int i=0;i<u.size();i++){
    if(a[i]==0 && b[i]==0)return 0;//cannot build moment...
  }
  build(u,v,a,b);
  return 1;
}
