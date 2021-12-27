// ans.cpp 20 Jul 20, 22:43:06 100 0.58 Judging completed in 4.504s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

vector<int> adjl[100005],adjl_rev[100005],v;
bool vis[100005],ind[100005];
//ind as in cur scc points to other scc and hence not valid
int ans=1e9,nex=0,siz[100005],grp[100005];//siz as in size of current scc

void dfs(int node){
    vis[node]=true;
    for(int i=0;i<adjl[node].size();i++){
        if(vis[adjl[node][i]])continue;
        dfs(adjl[node][i]);
    }
    v.push_back(node);
}
void dfs2(int node){
    grp[node]=nex;
    siz[nex]++;
    vis[node]=false;
    for(int i=0;i<adjl_rev[node].size();i++){
        if(vis[adjl_rev[node][i]]==false)continue;
        dfs2(adjl_rev[node][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int x=0;x<m;x++){
        cin>>a>>b;
        adjl[a].push_back(b);
        adjl_rev[b].push_back(a);
    }
    for(int x=1;x<=n;x++){
        if(vis[x]==false)dfs(x);
    }
    while(v.size()>0){
        if(vis[v.back()]==true){//not visited
            dfs2(v.back());//everything searched will be same scc
            nex++;
        }
        v.pop_back();
    }
    for(int x=1;x<=n;x++){
        for(int i=0;i<adjl[x].size() && ind[grp[x]]==false;i++){
            if(grp[x]!=grp[adjl[x][i]]){
                //cur scc point to other scc
                ind[grp[x]]=true;
            }
        }
    }
    for(int x=0;x<nex;x++)if(ind[x]==false)ans=min(ans,siz[x]);
    cout<<ans;
    return 0;
}