// ans.cpp 13 Nov 18, 21:13:54 0 1.05 Judging completed in 3.676s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> start;
	queue<pair<vector<int>,pair<int,int> > >bfs;
	map<vector<int>,int> m[11];
	//permutation, distance from ideal
	bool sorted;
	int tc,n,a;
	cin>>tc;
	for(int x=1;x<=10;x++){
		while(!bfs.empty()){
			bfs.pop();
		}
		start.push_back(x);
		bfs.push(make_pair(start,make_pair(0,0)));
		m[x][start]=0;
		while(!bfs.empty()){
			//cout<<"L\n";
			for(int y=2;y<=x;y++){
				if(y==bfs.front().second.second)continue;
				start=bfs.front().first;
				for(int z=0;z<y;z++){
					if(z>=y-1-z)break;
					swap(start[z],start[y-1-z]);
				}
				if(m[x].find(start)==m[x].end()){
					//cout<<"k\n";
					m[x][start]=bfs.front().second.first+1;
					bfs.push(make_pair(start, make_pair(bfs.front().second.first+1,y)  ));
				}
			}
			bfs.pop();
		}
	}
	cout<<"ready\n";
	while(tc--){
		start.clear();
		cin>>n;
		for(int x=0;x<n;x++){
			start.push_back(0);
		}
		for(int x=n-1;x>=0;x--){
			cin>>start[x];
		}
		cout<<m[n][start]<<'\n';
	}
	return 0;
}