// ans.cpp 7 Dec 19, 10:08:37 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> adjl[1050];
int dist[1050];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,e,a,b,c,cur,ans=INT_MAX;
    cin>>n>>e;
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjl[a].emplace_back(b,c);
        adjl[b].emplace_back(a,c);
    }
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    for(int x=1;x<=n;x++){
        pq.push(make_pair(0,x));//distance, node...
        for(int i=1;i<=n;i++){
            dist[i]=INT_MAX;
        }dist[x]=0;
        while(!pq.empty()){
            a=pq.top().second;
            pq.pop();
            for(int x=0;x<adjl[a].size();x++){
                if(dist[a]+adjl[a][x].second<dist[adjl[a][x].first){
                    dist[adjl[a][x].first]=dist[a]+adjl[a][x].second;
                    pq.push(make_pair(dist[adjl[a][x].first],adjl[a][x].second));
                }
            }
        }
        cur=0;
        for(int i=1;i<=n;i++){
            cur+=dist[i];
        }
        ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}