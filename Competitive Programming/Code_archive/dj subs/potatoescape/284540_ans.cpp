// ans.cpp 9 Dec 17, 14:08:42 100 0.04 Judging completed in 4.856s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > adjlis[100005];
bool visited[100005],visited2[100005];
int dist[100005];
int dfs(int node,int current,bool a){
    
    visited[node]=true;
    int ans=current;dist[node]=ans;
    for(int x=0;x<adjlis[node].size();x++){
        if(visited[adjlis[node][x].first])continue;
        ans=max(dfs(adjlis[node][x].first,current+adjlis[node][x].second,false),ans);
    }
    
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e,a,b,c;
    cin>>n>>e;
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjlis[a].push_back(make_pair(b,c));
        adjlis[b].push_back(make_pair(a,c));
    }
    dfs(0,0,true);
    int aaa=0;
    visited[0]=false;
    for(int x=1;x<n;x++){
    	visited[x]=false;
        if(dist[aaa]<dist[x]){
            aaa=x;
        }
    }
    cout<<dfs(aaa,0,false);
    return 0;
}