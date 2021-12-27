// ans.cpp 20 Jul 20, 22:34:19 0 0.51 Judging completed in 5.651s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

vector<int> adjl[100005],adjl_rev[100005],v;
bool vis[100005];
int cur,ans=1;

void dfs(int node){
    vis[node]=true;
    for(int i=0;i<adjl[node].size();i++){
        if(vis[adjl[node][i]])continue;
        dfs(adjl[node][i]);
    }
    v.push_back(node);
}
void dfs2(int node){
    cur++;
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
        adjl[b].push_back(a);
    }
    for(int x=1;x<=n;x++){
        if(vis[x]==false)dfs(x);
    }
    while(v.size()>0){
        if(vis[v.back()]==true){//not visited
            cur=0;
            dfs2(v.back());//everything searched will be same scc
            ans=max(ans,cur);
        }
        v.pop_back();
    }
    cout<<ans;
    return 0;
}