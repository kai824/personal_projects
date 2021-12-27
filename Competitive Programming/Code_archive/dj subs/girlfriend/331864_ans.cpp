// ans.cpp 1 Mar 18, 21:48:22 0 0.04 Judging completed in 6.209s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dist[100005];
bitset<100005>vis,visi;
vector<pair<int,int> > adjl[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,e,s,d,a,b,c;
    cin>>n>>e>>s>>d;
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjl[a].push_back(make_pair(b,c));
    }
    dist[s]=1;
    queue<int> bfs;
    queue<int> bfs2;
    bfs.push(s);
    visi[s]=1;
    while(!bfs.empty()){
        a=bfs.front();//bfs.pop();
        for(int x=0;x<adjl[a].size();x++){
        	if(dist[adjl[a][x].first]!=0 && vis[adjl[a][x].first]==0 && adjl[a][x].first!=d){
            	bfs2.push((adjl[a][x].first));
            	vis[adjl[a][x].first]=1;
            }
            if(dist[a]+adjl[a][x].second>dist[adjl[a][x].first]){
            	if(visi[adjl[a][x].first]==1)continue;
            	visi[adjl[a][x].first]=1;
                bfs.push(adjl[a][x].first);
                dist[adjl[a][x].first]=dist[a]+adjl[a][x].second;
            }
        }
        bfs.pop();
    }
    while(!bfs2.empty()){
    	a=bfs2.front();bfs2.pop();
    	for(int x=0;x<adjl[a].size();x++){
    		if(vis[adjl[a][x].first]==1)continue;
    		vis[adjl[a][x].first]=1;
    		bfs2.push(adjl[a][x].first);
    		if(adjl[a][x].first==d){
    			cout<<"-2";
    			return 0;
    		}
    	}
    }
    if(dist[d]==0){
        cout<<"-1";
        return 0;
    }
    cout<<dist[d]-1;
    return 0;
}