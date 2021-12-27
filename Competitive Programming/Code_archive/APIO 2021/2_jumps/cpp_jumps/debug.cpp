#include "jumps.h"

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back
#define pb push_back
//each time, call init(n,h) and then query minimum_jumps(a,b,c,d)

//put the brute force bfs method here...
vector<int> adjl[10];
int dis[10],N;
void init2(int n,vector<int>h){
  N=n;
  for(int i=0;i<n;i++)adjl[i].clear();
  vector<pii> v;
  v.eb(h.back(),h.size()-1);
  for(int i=h.size()-2;i>=0;i--){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()>0)adjl[i].push_back(v.back().s);
    v.eb(h[i],i);
  }
  v.clear();

  v.eb(h[0],0);
  for(int i=1;i<n;i++){
    while(v.size()>0 && v.back().f<=h[i]){
      v.pop_back();
    }
    if(v.size()>0)adjl[i].push_back(v.back().s);
    v.eb(h[i],i);
  }
}
deque<int> bfs;
int mj2(int a,int b,int c,int d){
  int n=N;
  for(int i=0;i<n;i++)dis[i]=1e9;
  bfs.clear();
  for(int i=a;i<=b;i++){
    bfs.push_back(i);
    dis[i]=0;
  }
  int k;
  while(bfs.size()>0){
    k=bfs.front();
      if(c<=k && k<=d)return dis[k];
    bfs.pop_front();
    for(int x:adjl[k]){
      if(dis[x]==1e9){
        dis[x]=dis[k]+1;
        bfs.push_back(x);
      }
    }
  }
  return -1;
}

vector<int> hhh;
void shuffle(){
  int j;
  for(int i=0;i+1<hhh.size();i++){
    j=rand()%(hhh.size()-1-i);
    swap(hhh[i],hhh[i+j+1]);
  }
}
int main() {
  srand(42);
  int n=7,q=3;
  for(int i=1;i<=n;i++){
    hhh.push_back(i);
  }

  int cnt=0;
  while(cnt<3){
    shuffle();
    init(n,hhh);
    init2(n,hhh);

    for(int i=0;i<q;i++){
      int a,b,c,d;
      a=rand()%(n-1);b=rand()%(n-1);
      if(a>b)swap(a,b);
      c=b+1+rand()%(n-1-b);d=b+1+rand()%(n-1-b);
      if(c>d)swap(c,d);
      if(minimum_jumps(a,b,c,d)!=mj2(a,b,c,d)){
        cnt++;
        cout<<"Testcase "<<cnt<<":\n";
        cout<<n<<' '<<"1\n";
        for(int x:hhh)cout<<x<<' ';cout<<'\n';
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<'\n';
        cout<<"Outputs: "<<minimum_jumps(a,b,c,d)<<' '<<mj2(a,b,c,d)<<"\n\n";
        break;
      }
    }
  }
  return 0;
}
