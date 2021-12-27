// ans.cpp 23 Feb 19, 17:14:29 21 0.47 Judging completed in 5.622s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> adjlis[5005];
ll bb[1000005],ans=0,n,worst,worst2;
bool visited[5005];

bool dfs2(int node, ll badness){//cast in stone, by not changing the visited array back
	visited[node]=1;//prevent cycles
	badness+=bb[node];
	if(badness>ans){
		ans=badness;
	}
	if(node==worst)return true;//by returning true, the whole root upwards will not change the visited array...
	for(int x=0;x<adjlis[node].size();x++){
		if(visited[adjlis[node][x]]==0){
			if(dfs2(adjlis[node][x],badness)==true)return true;
		}
	}
	visited[node]=0;
	return false;
}

void dfs(int node, ll badness){
	visited[node]=1;//prevent cycles
	badness+=bb[node];
	if(badness>ans){
		ans=badness;
		worst=node;
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
	dfs(1,0);
	worst2=worst;
	dfs(worst2,0);//find furthest node from worst2
	dfs2(worst2,0);
	ll current_ans=ans;
	for(int x=1;x<=n;x++){
		if(visited[x]==0){
			dfs(x,current_ans);
		}
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

/*
6
1 2 3 -4 5 6
1 4
1 2
2 3
4 5
4 6
* 
8
3 -20 4 9 7 5 2 1
1 2
1 3
3 8
2 5
2 4
4 6
4 7
 */