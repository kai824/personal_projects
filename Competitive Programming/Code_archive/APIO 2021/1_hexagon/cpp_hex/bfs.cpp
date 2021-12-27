#include "hexagon.h"
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back
typedef long long ll;

const ll mod=1000000007;
const int xx[7]={0,1,1,0,-1,-1,0};
const int yy[7]={0,0,1,1,0,-1,-1};
//int ang[7]={0,0,1,2,4,5,6};//* pi/4 useless

const bool debug=true;
int dist[10][10];

ll ans;
int draw_territory(int n, int A, int B,vector<int> d, vector<int> l){//direction, length
  ll a=A,b=B;
  pii mx,my,cur;//min max x y
  mx=my=cur=mp(0,0);
  //int tot_ang=0;
  for(int i=0;i<n;i++){
    cur.f+=xx[d[i]]*l[i];
    cur.s+=yy[d[i]]*l[i];
    mx.f=min(mx.f,cur.f);
    mx.s=max(mx.s,cur.f);
    my.f=min(my.f,cur.s);
    my.s=max(my.s,cur.s);
  }
  int x=mx.s-mx.f+1,y=my.s-my.f+1;
  char mm[x][y];//map...
  memset(mm,'.',sizeof(mm));
  cur=mp(-mx.f,-my.f);

  mm[cur.f][cur.s]='x';
  for(int i=0;i<n;i++){
    for(int j=0;j<l[i];j++){
      cur.f+=xx[d[i]];
      cur.s+=yy[d[i]];
      mm[cur.f][cur.s]='x';
    }
  }

  //find all the "inside" cells
  deque<pii> fill;bool touch;//touching edge?
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      if(mm[i][j]=='x' || mm[i][j]=='-')continue;
      //fill with all '-'
      fill.clear();
      fill.eb(i,j);
      mm[i][j]='-';
      touch=false;
      while(fill.size()>0){
        cur=fill.front();
        fill.pop_front();
        if(min(cur.f,cur.s)==0)touch=true;
        if(cur.f==x-1 || cur.s==y-1)touch=true;
        for(int k=1;k<=6;k++){
          if(min(cur.f+xx[k],cur.s+yy[k])<0)continue;
          if(cur.f+xx[k]>=x || cur.s+yy[k]>=y)continue;
          if(mm[cur.f+xx[k]][cur.s+yy[k]]!='.')continue;
          mm[cur.f+xx[k]][cur.s+yy[k]]='-';
          fill.eb(cur.f+xx[k],cur.s+yy[k]);
        }
      }

      if(touch)continue;
      //fill whole space...
      fill.clear();
      fill.eb(i,j);
      mm[i][j]='x';
      while(fill.size()>0){
        cur=fill.front();
        fill.pop_front();
        if(min(cur.f,cur.s)==0)touch=true;
        if(cur.f==x-1 || cur.s==y-1)touch=true;
        for(int k=1;k<=6;k++){
          if(mm[cur.f+xx[k]][cur.s+yy[k]]=='x')continue;
          mm[cur.f+xx[k]][cur.s+yy[k]]='x';
          fill.eb(cur.f+xx[k],cur.s+yy[k]);
        }
      }
    }
  }

  cur=mp(-mx.f,-my.f);
  if(debug){
    mm[cur.f][cur.s]='o';
    for(int i=0;i<x;i++){
      for(int j=0;j<y;j++)cout<<mm[i][j];
      cout<<'\n';
    }
  }
  deque<pair<ll,pii> >ff;//final part...
  ans=0;
  ff.eb(0,cur);ans+=a;
  mm[cur.f][cur.s]='o';
  while(ff.size()>0){
    ll dis=ff.front().f;
    cur=ff.front().s;
    ff.pop_front();

    if(debug){
      dist[cur.f][cur.s]=dis;
    }
    for(int k=1;k<=6;k++){
      if(min(cur.f+xx[k],cur.s+yy[k])<0)continue;
      if(cur.f+xx[k]>=x || cur.s+yy[k]>=y)continue;
      if(mm[cur.f+xx[k]][cur.s+yy[k]]!='x')continue;
      mm[cur.f+xx[k]][cur.s+yy[k]]='o';
      ans+=(dis+1ll)*b+(ll)a;
      ans%=mod;
      ff.eb(dis+1,mp(cur.f+xx[k],cur.s+yy[k]));
    }
  }

  if(debug){
    for(int i=0;i<x;i++){
      for(int j=0;j<y;j++){
        if(i==-mx.f && j==-my.f){
          cout<<0<<'\t';
          continue;
        }else if(dist[i][j]>0)cout<<dist[i][j]<<'\t';
        else cout<<".\t";
      }cout<<'\n';
    }
  }
  return ans;
}
/*
17 2 3
1 1
2 2
3 2
4 1
5 1
4 1
3 1
2 2
1 3
6 2
2 3
3 1
4 6
5 3
6 3
6 2
1 1
*/
