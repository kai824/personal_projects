// ans.cpp 12 Nov 18, 10:11:12 100 0.07 Judging completed in 3.088s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int ans=0;
int n,k,a,b;
bool cat[100005];
bool visited[100005];
vector<int> adjlist[100005];
void dfs(int node,int annoyed){//current node to dfs, number of retarded cats
	if(cat[node]){
		annoyed++;
	}else{
		annoyed=0;
	}
	int bottom_stuff=0;
	if(annoyed>k)return;
	visited[node]=1;
	for(int x=0;x<adjlist[node].size();x++){
		if(visited[adjlist[node][x]])continue;
		bottom_stuff++;
		dfs(adjlist[node][x],annoyed);
	}
	if(bottom_stuff==0){
		//leaf node reached
		ans++;
	}
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>k;	
	for(int x=0;x<n;x++){
		cin>>a;
		if(a==0)cat[x+1]=0;
		else cat[x+1]=1;
	}
	for(int x=1;x<n;x++){
		cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}