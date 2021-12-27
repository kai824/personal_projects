// ans.cpp 18 Oct 17, 20:23:11 60 4.17 Judging completed in 9.277s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v,e,q,a,b,c,ans[500005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>v>>e>>q;
    vector<pair<ll,ll> > adj[v+1];
    //1-indexed since input is 1-indexed...
    for(ll x=0;x<e;x++){
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    for(ll x=0;x<=v;x++){
        ans[x]=-1;
    }
    queue<ll>ds;//dijkstra
    //ans[1] shall not be declared cause reasons...
    ds.push(1);
    ans[1]=1e18;
    while(!ds.empty()){
        for(ll x=0;x<adj[ds.front()].size();x++){
            if(min(ans[ds.front()],adj[ds.front()][x].second )>ans[ adj[ds.front()][x].first ]){
                ans[adj[ds.front()][x].first]=min(ans[ds.front()],adj[ds.front()][x].second );
                ds.push(adj[ds.front()][x].first);
            }
        }
        ds.pop();
    }
    for(ll x=0;x<q;x++){
        cin>>a;
        cout<<ans[a]<<'\n';
    }
    return 0;
}