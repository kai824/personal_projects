// ans.cpp 20 Oct 17, 08:24:26 0 1.01 Judging completed in 5.433s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,e,a,b,c;
    cin>>n>>e;
    vector<pair<ll,ll> >adj[n];
    ll costs[n],q;
    for(ll x=0;x<e;x++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    queue<ll>ds;//dijkstra
    ds.push(0);
    costs[0]=0;
    while(!ds.empty()){
        a=ds.front();
        ds.pop();
        for(ll x=0;x<adj[a].size();x++){
            if(costs[a]+adj[a][x].second<costs[adj[a][x].first]){
                costs[adj[a][x].first]=costs[a]+adj[a][x].second;
                ds.push(adj[a][x].first);
            }
        }
    }
    cin>>q;
    for(ll x=0;x<q;x++){
        while(!ds.empty()){ds.pop();}
        cin>>b>>c;
        for(ll y=0;y<n;y++){
            costs[y]=1e9;
        }
        ds.push(b);
        costs[b]=0;
        while(!ds.empty()){
            a=ds.front();
            ds.pop();
            for(ll x=0;x<adj[a].size();x++){
                if(costs[a]+adj[a][x].second<costs[adj[a][x].first]){
                    costs[adj[a][x].first]=costs[a]+adj[a][x].second;
                    ds.push(adj[a][x].first);
                }
            }
        }
        cout<<costs[c]-1<<'\n';
    }
    return 0;
}