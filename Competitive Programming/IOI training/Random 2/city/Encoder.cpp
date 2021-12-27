#include "Encoder.h"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adjl[250005];
ll pre[250005],sub[250005],nex;

ll cnts[250005];
void init(){
	for(int i=1;i<250001;i++){
		cnts[i]=cnts[i-1]+(250001-i);
	}
}

ll convert(int x,int y){//returns no. of smaller pairs...
	y-=x;
	assert(cnts[x]+y<cnts[x+1]);
	return cnts[x]+y;
}

void dfs(int node,int p=-1){
	pre[node]=nex++;
	for(int x:adjl[node]){
		if(x==p)continue;
		dfs(x,node);
	}
	sub[node]=nex-1;
	// cout<<node<<' '<<pre[node]<<' '<<sub[node]<<'\n';
	Code(node,convert(pre[node],sub[node]));
}

void Encode(int n, int a[], int b[]){
	init();
	for(int i=0;i+1<n;i++){
		adjl[a[i]].push_back(b[i]);
		adjl[b[i]].push_back(a[i]);
	}
	dfs(0);
	//Code(i, 0LL): node, label...
}
