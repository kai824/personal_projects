// ans.cpp 19 Oct 17, 18:17:51 80 1 Judging completed in 10.019s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> start;
	queue<pair<vector<int>,int> >bfs;
	map<vector<int>,bool>m;
	bool sorted;
	int tc,n,a;
	cin>>tc;
	while(tc--){
		start.clear();
		m.clear();
		while(!bfs.empty()){
			bfs.pop();
		}
		cin>>n;
		for(int x=0;x<n;x++){
			start.push_back(0);
		}
		for(int x=n-1;x>=0;x--){
			cin>>start[x];
		}
		bfs.push(make_pair(start,0));
		m[start]=true;
		while(!bfs.empty()){
			sorted=true;
			for(int x=0;x<n-1;x++){
				if(bfs.front().first[x]>bfs.front().first[x+1]){
					sorted=false;
					break;
				}
			}
			
			if(sorted){
				cout<<bfs.front().second<<'\n';
				break;
			}
			for(int x=2;x<=n;x++){
				start=bfs.front().first;
				for(int y=0;y<x;y++){
					if(y>=x-1-y)break;
					swap(start[y],start[x-1-y]);
				}
				if(m[start]!=true){
					m[start]=true;
					bfs.push(make_pair(start,bfs.front().second+1));
				}
			}
			bfs.pop();
		}
	}
	return 0;
}