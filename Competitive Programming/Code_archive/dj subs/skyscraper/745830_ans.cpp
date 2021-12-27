// ans.cpp 30 Jun 20, 09:40:52 57 1.44 Judging completed in 6.311s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

//#define int long long
#define mp make_pair
#define pii pair<short,short>

vector<pair<pii,short> > adjl[30005][175];//position, power, weight... if power==0, then it's dummy
int dist[30005][175],a,b,c;

priority_queue<pair<int,pii>,vector<pair<int,pii> >, greater<pair<int,pii> > > dijk;
//weight, pos, power

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,s,d,start,end;
    cin>>n>>m;//m doges, n buildings
    for(int x=0;x<n;x++){
      for(int y=0;y<175;y++){
        adjl[x][y].emplace_back(mp(x,0),0);
        dist[x][y]=INT_MAX;
        if(y>0){
          if(x+y<n)adjl[x][y].emplace_back(mp(x+y,y),1);
          if(x-y>=0)adjl[x][y].emplace_back(mp(x-y,y),1);
        }
      }
      dist[x][0]=INT_MAX;
    }
    for(int x=0;x<m;x++){
      cin>>s>>d;//position s, power d
      if(x==0)start=s;
      else if(x==1)end=s;
      if(d>=175){
        for(int i=1;i<=n;i++){
          if(s-(d*i)>=0){
            adjl[s][0].emplace_back(mp(s-(d*i),0),i);
          }else if(s+(d*i)>=n)break;
          if(s+(d*i)<n){
            adjl[s][0].emplace_back(mp(s+(d*i),0),i);
          }
        }
      }else{
        adjl[s][0].emplace_back(mp(s,d),0);
      }
    }

    dijk.emplace(0,mp(start,0));//pos, power...
    dist[start][0]=0;
    while(!dijk.empty()){
      c=dijk.top().first;
      a=dijk.top().second.first;
      b=dijk.top().second.second;
      if(a==end){
        cout<<c;
        return 0;
      }
      dijk.pop();

      for(int i=0;i<adjl[a][b].size();i++){
        if(dist[adjl[a][b][i].first.first][adjl[a][b][i].first.second]>c+adjl[a][b][i].second){
          dist[adjl[a][b][i].first.first][adjl[a][b][i].first.second]=c+adjl[a][b][i].second;
          dijk.emplace(c+adjl[a][b][i].second,adjl[a][b][i].first );
        }
      }
    }
    if(dist[end][0]==INT_MAX)cout<<"-1";
    else cout<<dist[end][0];
    return 0;
}
/*
*/