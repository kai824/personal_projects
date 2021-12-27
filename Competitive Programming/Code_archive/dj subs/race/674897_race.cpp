// race.cpp 7 Jan 20, 15:17:16 100 0.49 Judging completed in 7.624s on AWS Oregon.
#include "race.h"
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int k,ans=INT_MAX,a;

vector<pii> adjl[200005];//n up to 200k
pair<map<int,int>,pii> stuff[200005];
//maps traversed weight to number of edges...
//lazy add for the edge weight, and the no. of edges

map<int,int>::iterator it,it2;

void dfs(int node,int prev){//set, and the lazy adding
	stuff[node].second=make_pair(0,0);
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x].first==prev)continue;
		dfs(adjl[node][x].first,node);
		stuff[adjl[node][x].first].second.first+=adjl[node][x].second;
		stuff[adjl[node][x].first].second.second++;//no. of edges...
	}
	a=node;
	stuff[node].first[0]=0;
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x].first==prev)continue;
		if(stuff[adjl[node][x].first].first.size()>stuff[a].first.size()){
			a=adjl[node][x].first;
		}
	}
	if(a!=node){
		swap(stuff[a],stuff[node]);
	}
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x].first==prev)continue;
		a=adjl[node][x].first;
		for(it=stuff[a].first.begin();it!=stuff[a].first.end();it++){
			it2=stuff[node].first.find( k-(it->first+stuff[node].second.first+stuff[a].second.first) );
			if(it2==stuff[node].first.end())continue;
			else{
				ans=min(ans,it2->second+it->second+stuff[a].second.second+stuff[node].second.second);
			}
		}
		for(it=stuff[a].first.begin();it!=stuff[a].first.end();it++){
			if(stuff[node].first.find(it->first+stuff[a].second.first-stuff[node].second.first)==stuff[node].first.end()){
				stuff[node].first[it->first+stuff[a].second.first-stuff[node].second.first]=it->second+stuff[a].second.second-stuff[node].second.second;
			}else{
				stuff[node].first[it->first+stuff[a].second.first-stuff[node].second.first]=min(stuff[node].first[it->first+stuff[a].second.first-stuff[node].second.first],it->second+stuff[a].second.second-stuff[node].second.second);
			}
		}
		stuff[a].first.clear();
	}
	/*cout<<'\n'<<node<<'\n';
	cout<<"add "<<stuff[node].second.first<<' '<<stuff[node].second.second<<'\n';
	for(it=stuff[node].first.begin();it!=stuff[node].first.end();it++){
		cout<<it->first<<' '<<it->second<<'\n';
	}
	cout<<'\n';*/
}

int best_path(int n, int K, int h[][2], int l[]){
	//h is like adjlist with weights(L).
	k=K;//for global variable...
	for(int x=0;x<n-1;x++){
		adjl[h[x][0]].push_back(make_pair(h[x][1],l[x]));
		adjl[h[x][1]].push_back(make_pair(h[x][0],l[x]));
	}
	dfs(0,-1);
	if(ans==INT_MAX) return -1;
	else return ans;
}