// ans.cpp 1 Mar 18, 21:53:06 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dist[100005];
bool xxx;
bitset<100005>vis,visi;
vector<pair<int,int> > adjl[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,e,s,d,a,b,c;
    cin>>n>>e>>s>>d;
    if(s==d){
        cout<<0;
        return 0;
    }
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjl[a].push_back(make_pair(b,c));
    }
    dist[s]=1;
    queue<pair<int,bool> > bfs;
    queue<int> bfs2;
    bfs.push(make_pair(s,0));
    visi[s]=1;
    while(!bfs.empty()){
        a=bfs.front().first;//bfs.pop();
        for(int x=0;x<adjl[a].size();x++){
        	if(dist[adjl[a][x].first]!=0 && vis[adjl[a][x].first]==0 && bfs.front().second==false){
            	bfs2.push((adjl[a][x].first));
            	vis[adjl[a][x].first]=1;
            }
            if(dist[a]+adjl[a][x].second>dist[adjl[a][x].first]){
            	if(visi[adjl[a][x].first]==1)continue;
            	visi[adjl[a][x].first]=1;
            	xxx=bfs.front().second;
            	if(adjl[a][x].first==d)xxx=true;
                bfs.push(make_pair(adjl[a][x].first,xxx);
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