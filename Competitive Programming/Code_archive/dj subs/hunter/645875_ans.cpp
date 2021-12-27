// ans.cpp 14 Dec 19, 10:50:19 90.99 1.04 Judging completed in 6.732s on AWS Oregon.
#include <bits/stdc++.h>
#include "hunter.h"
using namespace std;

vector<int> adjl[30005];
bool vis[30005];
int cur_it=0,arr[30005];//array of leaf nodes...

void dfs(int node){
	vis[node]=true;
	bool leaf=true;
	for(int i=0;i<adjl[node].size();i++){
		if(vis[adjl[node][i]]==true)continue;
		dfs(adjl[node][i]);
		leaf=false;
	}
	if(leaf==true){
		arr[cur_it]=node;
		cur_it++;
	}
}

void hunter(int n,int m,int s,int d,vector<int>a,vector<int> b){
	for(int x=0;x<a.size();x++){
		adjl[a[x]].push_back(b[x]);
		adjl[b[x]].push_back(a[x]);
	}
	dfs(0);
	if(s==4){
	    for(int x=0;x<n;x++){
	        search_towns(arr[x],arr[cur_it-1-x]);
	    }
	}
	for(int x=0;x<n;x++){
		search_towns(arr[x],arr[x+n]);
	}
}