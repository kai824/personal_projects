// ans.cpp 11 Jul 20, 12:49:57 0 0.38 Judging completed in 5.988s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<pii> adjl[100005];
int dist[100005];

priority_queue<pii,vector<pii>,greater<pii> > dijk;//distance, node

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    for(int x=2;x<=n;x++)dist[x]=INT_MAX;
    for(int x=0;x<m;x++){
        cin>>a>>b>>c;
        adjl[a].emplace_back(b,c);
        adjl[b].emplace_back(a,c);
    }
    dijk.emplace(0,1);
    while(!dijk.empty()){
        a=dijk.top().first;
        b=dijk.top().second;
        dijk.pop();
        for(int i=0;i<adjl[b].size();i++){
            if(dist[adjl[b][i].first]>a+adjl[b][i].second){
                dist[adjl[b][i].first]=a+adjl[b][i].second;
                dijk.emplace(adjl[b][i].first,a+adjl[b][i].second);
            }
        }
    }
    if(dist[n]==INT_MAX)cout<<"-1";
    else cout<<dist[n];
    return 0;
}