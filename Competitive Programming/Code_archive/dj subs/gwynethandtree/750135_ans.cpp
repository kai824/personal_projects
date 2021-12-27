// ans.cpp 22 Jul 20, 19:07:46 100 0.17 Judging completed in 4.749s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

vector<int> adjl[100005];
int lvl[100005],parent[100005]/*parent in centroid tree*/,subt[100005],nn;
int dist[100005][18],ans[100005];

int dfs1(int node,int prev=-1){
  subt[node]=1;
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    if(lvl[adjl[node][i]]!=-1)continue;
    subt[node]+=dfs1(adjl[node][i],node);
  }
  return subt[node];
}
int dfs2(int node,int prev=-1){//find centroid
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    if(lvl[adjl[node][i]]!=-1)continue;
    if(subt[adjl[node][i]]>=nn/2){//that subtree has a lot of nodes
      return dfs2(adjl[node][i],node);
    }
  }
  return node;
}
void dfs3(int node,int l,int prev=-1){
  for(int i=0;i<adjl[node].size();i++){
    if(adjl[node][i]==prev)continue;
    if(lvl[adjl[node][i]]!=-1)continue;
    dist[adjl[node][i]][l]=dist[node][l]+1;
    dfs3(adjl[node][i],l,node);
  }
}

void build(int u,int p,int l){//current node, current parent, current level...
  nn=dfs1(u);//current "subtree"
  int cent=dfs2(u);//find centroid
  lvl[cent]=l;
  parent[cent]=p;
  dist[cent][l]=0;
  dfs3(cent,l);//update dist[node][l]
  for(int i=0;i<adjl[cent].size();i++){
    if(lvl[adjl[cent][i]]!=-1)continue;//already done sth about that node
    build(adjl[cent][i],cent,l+1);
  }
}

void update(int x){//mark as active
  int x2=x;
  while(x2!=-1){
    ans[x2]=min(ans[x2],dist[x][lvl[x2]]);//ans may become smaller since new node may be closer
    x2=parent[x2];
  }
}
int query(int x){
  int x2=x,qq=1e9;
  while(x2!=-1){
    qq=min(qq,dist[x][lvl[x2]]+ans[x2]);
    x2=parent[x2];
  }
  return qq;
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int x=1;x<n;x++){
        cin>>a>>b;
        adjl[a].push_back(b);
        adjl[b].push_back(a);
        lvl[x]=-1;
        ans[x]=1e9;
    }
    lvl[n]=-1;
    ans[n]=1e9;
    build(1,-1,0);
    update(1);

    /*for(int x=1;x<=n;x++){
        cout<<parent[x]<<' '<<lvl[x]<<'\n';
    }*/
    for(int x=0;x<m;x++){
        cin>>a>>b;
        if(a==1){
            update(b);
            ;
        }else{
            cout<<query(b)<<'\n';
        }
    }
    return 0;
}

/*
5 4
1 2
2 3
2 4
4 5
2 1
2 5
1 2
2 5
*/