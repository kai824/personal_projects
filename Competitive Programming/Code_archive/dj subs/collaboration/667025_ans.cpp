// ans.cpp 28 Dec 19, 16:30:50 23 0.54 Judging completed in 6.716s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

long long cnt=0,k,p;
vector<int> adjl[6005];
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
	k=K;p=P;
	if(n>5000){
		for(long long x=1;x<n;x++){//distance...
			if(x==K){
				ans+=P*(n-x);
				continue;
			}
			ans+=x*(n-x);
		}
		return ans;
	}
	for(int x=1;x<n;x++){
		adjl[A[x-1]].push_back(B[x-1]);
		adjl[B[x-1]].push_back(A[x-1]);
	}
	for(int x=1;x<=n;x++){
		dfs(x,-1,0);
	}
	return ans/2;
}