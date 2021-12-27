// ans.cpp 28 Dec 19, 16:19:15 5 0.16 Judging completed in 8.297s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

int cnt=0,k,p;
vector<int> adjl[5000];
long long ans=0;
void dfs(int node,int prev,int depth){
	if(depth==k){
		cnt++;
		ans+=p;
	}else{
		ans+=depth;
	}
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x]!=prev){
			dfs(adjl[node][x],node,depth+1);
		}
	}
}

long long find_cost(int n, int P, int K, int A[], int B[]){
	for(int x=1;x<n;x++){
		adjl[A[x-1]].push_back(B[x-1]);
		adjl[B[x-1]].push_back(A[x-1]);
	}
	k=K;p=P;
	for(int x=1;x<=n;x++){
		dfs(x,-1,0);
	}
	return ans/2;
}