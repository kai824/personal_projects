// ans.cpp 19 Oct 19, 18:40:05 0 0.08 Judging completed in 4s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> pii;
string mp[1005];
pii parent[1005][1005];
int siz[1005][1005];

pii get_root(int a,int b){
    if(parent[a][b].first==-1 && parent[a][b].second==-1)return make_pair(a,b);
    parent[a][b]=get_root(parent[a][b].first,parent[a][b].second);
    return parent[a][b];
}

int get_sizz(int a,int b){
  pii rt=get_root(a,b);
  return siz[rt.first][rt.second];
}
inline void combine(int a1,int a2,int b1,int b2){
    pii rt=get_root(a1,a2),rt2=get_root(b1,b2);
    if(rt==rt2)return;
    parent[rt.first][rt.second]=rt2;
    siz[rt2.first][rt2.second]+=siz[rt.first][rt.second];
    siz[rt.first][rt.second]=0;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    pair<int,int> rain;
    for(int x=0;x<1005;x++){
        for(int y=0;y<1005;y++){
            parent[x][y]=make_pair(-1,-1);
            siz[x][y]=1;
        }
    }
    cin>>n>>m;
    for(int x=0;x<n;x++){
        cin>>mp[x];
        for(int y=0;y<m;y++){
            if(mp[x][y]=='R'){
              rain=make_pair(x,y);
            }
            if(mp[x][y]=='X')continue;
            if(x>0){
                if(mp[x-1][y]!='X')combine(x,y,x-1,y);
            }
            if(y>0){
                if(mp[x][y-1]!='X')combine(x,y,x,y-1);
            }
        }
    }
    bool valid,invalid;
    int ans=0,cur;
    int xx[4]={0,0,-1,1},
        yy[4]={-1,1,0,0};
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
          if(mp[x][y]!='X')continue;
          valid=false;
          cur=0;
          for(int z=0;z<4;z++){
              if(min(x+xx[z],y+yy[z])<0 || x+xx[z]>=n || y+yy[z]>=m){
                  continue;
              }
              if(mp[x+xx[z]][y+yy[z]]=='X')continue;
              if(get_root(rain.first,rain.second)==get_root(x+xx[z],y+yy[z])){
                valid=true;continue;
              }
              invalid=false;
              for(int z2=0;z2<z;z2++){
                  if(min(x+xx[z2],y+yy[z2])<0 || x+xx[z2]>=n || y+yy[z2]>=m){
                  continue;
              }
              if(mp[x+xx[z2]][y+yy[z2]]=='X')continue;
              if(get_root(rain.first,rain.second)==get_root(x+xx[z2],y+yy[z2])){
                valid=true;continue;
              }
                if(get_root(x+xx[z2],y+yy[z2])==get_root(x+xx[z],y+yy[z])){
                  invalid=true;break;
                }
              }
              if(invalid)continue;
              cur+=get_sizz(x+xx[z],y+yy[z]);
          }
          if(valid)ans=max(ans,cur);
        }
    }
    cout<<ans+get_sizz(rain.first,rain.second)+1;
    return 0;
}