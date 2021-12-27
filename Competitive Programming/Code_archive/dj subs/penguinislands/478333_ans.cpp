// ans.cpp 17 Jan 19, 17:17:55 0 0.02 Judging completed in 2.301s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll adjmat[201][201];
ll par[10];//for ufds
int getr(int a){
    if(par[a]==-1)return a;
    par[a]=getr(par[a]);
    return par[a];
}
inline void merge(int a,int b){
    par[getr(a)]==getr(b);
}
inline bool connected(int a,int b){
    return (getr(a)==getr(b));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,e,a,b,c,cost=0;
    cin>>n>>e;
    for(int x=0;x<201;x++){
        for(int y=0;y<201;y++){
            adjmat[x][y]=1e15;
        }
    }
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjmat[a][b]=min(adjmat[a][b],c);
        adjmat[b][a]=min(adjmat[b][a],c);
    }
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int z=1;z<=n;z++){
                adjmat[x][y]=min(adjmat[x][y],adjmat[x][z]+adjmat[z][y]);
            }
        }
    }
    vector<pair<ll,pair<int,int> > > v;
    for(int x=1;x<=4;x++){
        for(int y=1;y<=4;y++){
            v.push_back(make_pair(adjmat[x][y],make_pair(x,y)));
        }
    }
    for(int x=0;x<5;x++){
        par[x]=-1;
    }
    sort(v.begin(),v.end());
    for(int x=0;x<v.size();x++){
        if(!connected(v[x].second.first,v[x].second.second)){
            cost+=v[x].first;
            merge(v[x].second.first,v[x].second.second);
        }
    }
    cout<<cost;
    return 0;
}