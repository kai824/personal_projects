// dreaming.cpp 31 Jan 20, 15:47:46 18 0.08 Judging completed in 4.939s on AWS Oregon.
#include<bits/stdc++.h>
#include "dreaming.h"
using namespace std;

vector<int> diameters;//more of radius...
vector<pair<int,int> >adjl[100005];
int parent[100005],dist[100005];
int deepest,max_dist,end1,end2;
bool vis[100005];

void dfs(int node,int dd,int prev){
	dist[node]=dd;
	parent[node]=prev;
	if(dd>=max_dist){
		max_dist=dd;
		deepest=node;
	}
	vis[node]=true;
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x].first==prev)continue;
		dfs(adjl[node][x].first,dd+adjl[node][x].second,node);
	}
}

int find_diameter(int node){//actually returns radius
	deepest=node;max_dist=0;
	dfs(node,0,-1);
	end1=deepest;max_dist=0;//max dist is now to test diameter
	dfs(end1,0,-1);
	end2=deepest;
	while(dist[parent[deepest]]*2>max_dist){
		deepest=parent[deepest];
	}
	return min(max(max_dist-dist[parent[deepest]],dist[parent[deepest]]),max(dist[deepest],max_dist-dist[deepest]));
}

int travelTime(int n, int m, int l, int A[], int B[], int T[]){
	for(int x=0;x<m;x++){
		adjl[A[x]].push_back(make_pair(B[x],T[x]));
		adjl[B[x]].push_back(make_pair(A[x],T[x]));
	}
	for(int x=0;x<n;x++){
		if(vis[x]==false){
			diameters.push_back(find_diameter(x));
		}
	}
	sort(diameters.begin(),diameters.end(),greater<int>() );
	if(diameters.size()==1){
		return diameters[0];
	}
	if(diameters.size()==2){
		return diameters[0]+diameters[1]+l;
	}
	return max(diameters[0]+diameters[1]+l,2*l+diameters[1]+diameters[2]);
}