// ans.cpp 23 Dec 19, 21:20:44 100 0.16 Judging completed in 4.266s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

#pragma O3
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")

long double arr[605];//expected value
vector<int> adjl[605];
int n,m,s,t,prev;

inline void dfs(int start){
    long double sum;
	arr[n]=0;
	start=min(start,n-1);
    for(int node=start;node>=1;node--){
        sum=0;
    	for(int x=0;x<adjl[node].size();x++){
    		sum+=arr[adjl[node][x]];
    	}
    	arr[node]=sum/adjl[node].size();
    	arr[node]+=1;
    }
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	long double ans=1e15,maxi;int it,p;
	cin>>n>>m;
	for(int x=0;x<m;x++){
		cin>>s>>t;
		adjl[s].push_back(t);
	}
	cout.precision(11);
	for(int x=0;x<=n;x++){
		arr[x]=-1;
	}arr[n]=0;
	dfs(n-1);
	ans=arr[1];
	for(int x=n-1;x>=1;x--){
		maxi=0;it=0;
		if(adjl[x].size()==1)continue;
		for(int i=0;i<adjl[x].size();i++){
			if(arr[adjl[x][i]]>maxi){
			    maxi=arr[adjl[x][i]];
			    it=i;
			}
		}
		p=adjl[x][it];
		swap(adjl[x][it],adjl[x].back());adjl[x].pop_back();
		dfs(x);
		ans=min(ans,arr[1]);
		adjl[x].push_back(p);
		swap(adjl[x][it],adjl[x].back());
		dfs(x);
	}
	cout<<ans;
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