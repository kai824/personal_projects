// ans.cpp 11 Jul 20, 12:53:54 100 0.39 Judging completed in 4.636s on AWS Oregon.
#include "bits/stdc++.h"
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
                dijk.emplace(a+adjl[b][i].second,adjl[b][i].first);
            }
        }
    }
    if(dist[n]==INT_MAX)cout<<"-1";
    else cout<<dist[n];
    return 0;
}
/*
4 4
1 2 5
2 3 5
2 4 7
3 4 1
*/