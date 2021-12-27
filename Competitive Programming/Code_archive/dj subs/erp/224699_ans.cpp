// ans.cpp 20 Oct 17, 08:29:48 26 0.11 Judging completed in 4.869s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,e,a,b,c;
    cin>>n>>e;
    vector<pair<int,int> >adj[n];
    int costs[n],q;
    for(int x=0;x<n;x++){
    	costs[x]=INT_MAX;
    }
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    queue<int>ds;//dijkstra
    ds.push(0);
    costs[0]=0;
    while(!ds.empty()){
        a=ds.front();
        ds.pop();
        for(int x=0;x<adj[a].size();x++){
            if(costs[a]+adj[a][x].second<costs[adj[a][x].first]){
                costs[adj[a][x].first]=costs[a]+adj[a][x].second;
                ds.push(adj[a][x].first);
            }
        }
    }
    cin>>q;
    for(int x=0;x<q;x++){
        cin>>b>>c;
        cout<<max(costs[b],costs[c])-min(costs[b],costs[c])-1<<'\n';
    }
    return 0;
}