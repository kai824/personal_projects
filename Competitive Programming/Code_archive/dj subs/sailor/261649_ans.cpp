// ans.cpp 18 Nov 17, 21:36:19 16.67 0.01 Judging completed in 3.972s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bitset<10005> visited,visited2,not_leaf;
vector<short int>adjl[10005],adjl2[10005];
short int scc[10005],nex=1,nodes;
short int no[10005];
vector<short int> v;//used as the "stack"
void dfs(short int start){
    if(visited[start]==1)return;
    visited[start]=1;
    
    for(short int x=0;x<adjl[start].size();x++){
        if(visited[adjl[start][x]]==1)continue;
        dfs(adjl[start][x]);
    }
    
    v.push_back(start);
}

void dfs2(short int start){
	if(visited2[start]==1)return;
	nodes++;
    visited2[start]=1;
    scc[start]=nex;
    for(short int x=0;x<adjl2[start].size();x++){
    	if(visited2[adjl2[start][x]]==1){
    		if(scc[adjl2[start][x]]!=0 && scc[adjl2[start][x]]!=nex){
    			//from another node...
    			not_leaf[scc[adjl2[start][x]]]=true;
    		}
    		continue;
    	}
    	dfs2(adjl2[start][x]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    short int n,m,a,b,ans=0;
    cin>>n>>m;
    for(short int x=0;x<m;x++){
        cin>>a>>b;
        adjl[a].push_back(b);
        adjl2[b].push_back(a);
    }
    
    //first pass...
    for(short int x=1;x<=n;x++){
        dfs(x);
    }
    //second pass...
    while(v.size()>0){
    	if(visited2[v.back()]==0){
    		nodes=0;
    		dfs2(v.back());
    		no[nex]=nodes;
    		nex++;
    	}
    	v.pop_back();
    }
    for(short int x=1;x<nex;x++){
    	if(not_leaf[x]==false){
    		ans=max(ans,no[x]);
    	}
    }
    cout<<ans;
    return 0;
}