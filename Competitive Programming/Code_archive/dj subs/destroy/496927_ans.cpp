// ans.cpp 23 Feb 19, 18:02:56 33 3.01 Judging completed in 6.754s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adjlis[5005];
ll bb[1000005],ans=0,n;
bool visited[5005];
void dfs2(int node,ll badness){
	visited[node]=1;
	badness+=bb[node];
	ans=max(ans,badness);
	if(badness<0){
	    visited[node]=0;
	    return;
	}
	for(int x=0;x<adjlis[node].size();x++){
		if(visited[adjlis[node][x]]==0){
			dfs2(adjlis[node][x],badness);
		}
	}
	visited[node]=0;
}
void dfs(int node, ll badness){
	visited[node]=1;//prevent cycles
	badness+=bb[node];
	ans=max(ans,badness);
	if(badness<0){
	    visited[node]=0;
	    return;
	}
	
	for(int x=1;x<=n;x++){
		if(visited[x]==0){
			dfs2(x,badness);
		}
	}
	
	for(int x=0;x<adjlis[node].size();x++){
		if(visited[adjlis[node][x]]==0){
			dfs(adjlis[node][x],badness);
		}
	}
	visited[node]=0;//since can now go there again by other means...
}
void brute_force(int n){
	int a,b;
	for(int x=1;x<=n;x++){
		cin>>bb[x];
	}
	for(int x=1;x<n;x++){
		cin>>a>>b;
		adjlis[b].push_back(a);
		adjlis[a].push_back(b);
	}
	for(int x=1;x<=n;x++){
		dfs(x,0LL);
	}
	cout<<ans;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll a,b,current,ans=0;
	cin>>n;
	if(n<=5000){
		brute_force(n);
		return 0;
	}
	ll front_max[2+n],back_max[2+n];//represents the values...
	for(int x=1;x<=n;x++){
		cin>>bb[x];
	}
	/*for(int x=1;x<n;x++){
		cin>>a>>b;
		adjmat[a].push_back(b);
		adjmat[b].push_back(a);
	}*/
	//assume line here...
	front_max[0]=0;back_max[n+1]=0;current=0;
	for(int x=1;x<=n;x++){
		current+=bb[x];
		if(current<0)current=0;
		front_max[x]=max(current,front_max[x-1]);//1d max sum
	}
	current=0;
	for(int x=n;x>0;x--){
		current+=bb[x];
		if(current<0)current=0;
		back_max[x]=max(current,back_max[x+1]);
	}
	for(int x=0;x<=n;x++){
		ans=max(front_max[x]+back_max[x+1],ans);
	}
	cout<<ans;
	return 0;
}