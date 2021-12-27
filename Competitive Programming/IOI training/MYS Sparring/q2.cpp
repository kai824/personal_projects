#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=1000000007,mxn=200005;
typedef pair<int,int> pii;
#define f first
#define s second

int dd,d;
vector<int> adjl[mxn];

pii dc[mxn];//count no. of nodes in subtree where dist to subtree root <d, and =d-1: including itself...
deque<int> dq[mxn];int it[mxn];//rmb which child subtree was copied from, so that we can undo later...
void dfs(int node,int prev=-1){
  it[node]=-1;
  for(int x:adjl[node]){
    if(x==prev)continue;
    dfs(x,node);
    if(it[node]==-1 || dq[x].size()>dq[it[node]].size()){
      it[node]=x;
    }
  }
  if(it[node]!=-1)swap(dq[node],dq[it[node]]);
  dc[node].f=1;
  for(int x:adjl[node]){
    if(x==prev)continue;
    dc[node].f+=dc[x].f-dc[x].s;
    if(x==it[node])continue;
    for(int i=0;i<dq[x].size();i++){
      dq[node][i]+=dq[x][i];
    }
  }
  dq[node].push_front(1);//this node itself...
  while(dq[node].size()>d){
    dc[node].f-=dq[node].back();
    dq[node].pop_back();
  }
  if(dq[node].size()==d){
    dc[node].s=dq[node].back();
  }else dc[node].s=0;
}

int32_t main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n,a,b;
  cin>>n;
  for(int i=1;i<n;i++){
    cin>>a>>b;
    adjl[a].push_back(b);
  }
  cin>>dd;d=dd/2;
  dfs(1);
}
