// ans.cpp 14 Dec 19, 10:57:00 100 0.43 Judging completed in 7.014s on AWS Oregon.
#include <bits/stdc++.h>
#include "hunter.h"
using namespace std;

vector<int> adjl[30005];
bool vis[30005];
int it1=0,it2=0,arr1[30005],arr2[30000];//array of leaf nodes...
int N,M;
void dfs(int node){
	vis[node]=true;
	bool leaf=true;
	for(int i=0;i<adjl[node].size();i++){
		if(vis[adjl[node][i]]==true)continue;
		dfs(adjl[node][i]);
		leaf=false;
	}
	if(leaf==true){
	    if(node<M+N){
	        arr1[it1]=node;it1++;
	    }else{
	        arr2[it2]=node;it2++;
	    }
	}
}

void hunter(int n,int m,int s,int d,vector<int>a,vector<int> b){N=n;M=m;
	for(int x=0;x<a.size();x++){
		adjl[a[x]].push_back(b[x]);
		adjl[b[x]].push_back(a[x]);
	}
	dfs(0);
	/*if(s==4){
	    for(int x=0;x<n;x++){
	        search_towns(arr[x],arr[cur_it-1-x]);
	    }
	}*/
	for(int x=0;x<n;x++){
		search_towns(arr1[x],arr2[x]);
	}
}