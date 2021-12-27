// ans.cpp 23 Dec 19, 11:39:02 100 0.15 Judging completed in 4.216s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int sub[100005],lvl[100005],parent[100005],ans[100005];
vector<int> adjl[100005];

int dst[100005][20];

int dfs1 (int u , int p) {//finds size of subtree...
    sub[u] = 1; // Subtree size is 1
    int v;
    for (int i=0;i<adjl[u].size();i++) {
        v=adjl[u][i];
        if ( lvl [v] != -1) continue ; // Already added to
        if ( v == p ) continue ;
        sub [u] += dfs1 (v,u) ; // Increase size of subtree
    }
    return sub [u];
}

int dfs2(int u,int p,int n){
    int v;
    for(int i=0;i<adjl[u].size();i++){
        v=adjl[u][i];
        if(lvl[v]!=-1)continue;
        if(v!=p && sub[v]>n/2){
            return dfs2(v,u,n);
        }
    }
    return u;
}
void dfs3(int node,int l,int d,int prev){//node, level,distance...
    dst[node][l]=d;
    for(int i=0;i<adjl[node].size();i++){
        if(lvl[adjl[node][i]]!=-1)continue;
        //a centroid, which will be a parent in centroid tree...
        if(adjl[node][i]==prev)continue;//visited before in the same dfs...
        dfs3(adjl[node][i],l,d+1,node);
    }
}

void build(int u,int p,int l){//current node, current parent, current level...
    int n=dfs1(u,p);
    int cent = dfs2(u,p,n);
    if(p==-1)p=cent;
    parent[cent]=p;
    lvl[cent]=l;
    dfs3(cent,l,0,-1);//for the distance...
    for(int i=0;i<adjl[cent].size();i++){
        if(lvl[adjl[cent][i]]!=-1)continue;
        build(adjl[cent][i],cent,l+1);
    }
}

void update(int x){
    int l = lvl[x];
    int y=x;
    while(l!=-1){
        ans[y]=min(ans[y],dst[x][l]);
        y=parent[y];
        l--;
    }
}
int query(int x){
    int l = lvl[x];
    int y=x,res=ans[x];
    while(l!=-1){
        //ans[y]=min(ans[y],dst[x][l]);
        res=min(res,ans[y]+dst[x][l]);
        y=parent[y];
        l--;
    }
    return res;
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