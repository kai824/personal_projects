// ans.cpp 21 Dec 19, 11:24:32 0 0.02 Judging completed in 3.765s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

long double arr[605];//expected value
long double mini[605];//minimum expected value
vector<int> adjl[605];

void dfs(int node){
	if(arr[node]!=-1)return;
	arr[node]=0;//sum...
	long double maxi=0,max2=0,sum;
	for(int x=0;x<adjl[node].size();x++){
		dfs(adjl[node][x]);
		arr[node]+=arr[adjl[node][x]];
		maxi=max(maxi,arr[adjl[node][x]]);//cut off one node
		max2=max(max2,arr[adjl[node][x]]-mini[adjl[node][x]]);//use shortcut of a parent
	}
	sum=arr[node];
	arr[node]/=adjl[node].size();arr[node]+=1;
	if(adjl[node].size()==1)maxi=-1;//cannot cut off the only path...
	mini[node]=1+min(arr[node]-1,min( (sum-maxi)/(adjl[node].size()-1),(sum-max2)/adjl[node].size() ) );
	//cout<<"g:"<<node<<' '<<arr[node]<<' '<<mini[node]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,s,t;
	cin>>n>>m;
	for(int x=0;x<=n;x++){
		arr[x]=mini[x]=-1;
	}
	for(int x=0;x<m;x++){
		cin>>s>>t;
		adjl[s].push_back(t);
	}
	cout.precision(11);
	arr[n]=mini[n]=0;
	dfs(1);
	cout<<arr[1]<<' '<<mini[1];
	return 0;
}

/*
4 6
1 4
2 3
1 3
1 2
3 4
2 4

10 33
3 7
5 10
8 9
1 10
4 6
2 5
1 7
6 10
1 4
1 3
8 10
1 5
2 6
6 9
5 6
5 8
3 6
4 8
2 7
2 9
6 7
1 2
5 9
6 8
9 10
3 9
7 8
4 5
2 10
5 7
3 5
4 7
4 9
*/