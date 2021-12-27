// ans.cpp 13 Nov 18, 21:46:53 80 1 Judging completed in 3.521s on AWS Oregon.
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
	int tc,n,a,ans;
	pair<int,int> arr[10];//value, it in original
	cin>>tc;
	//cout<<"started\n";
	for(int x=1;x<=10;x++){
		start.clear();
		while(!bfs.empty()){
			bfs.pop();
		}
		for(int y=1;y<=x;y++){
			start.push_back(y);
		}
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
				if(bfs.front().second.first+1>5)break;
				if(m[x].find(start)==m[x].end()){
					//cout<<"k\n";
					m[x][start]=bfs.front().second.first+1;
					bfs.push(make_pair(start, make_pair(bfs.front().second.first+1,y)  ));
				}
			}
			bfs.pop();
		}
		//cout<<x<<'\n';
	}
	//cout<<"ready\n";
	while(tc--){
		m[0].clear();
		while(!bfs.empty()){
			bfs.pop();
		}
		start.clear();
		cin>>n;
		for(int x=n-1;x>=0;x--){
			cin>>arr[x].first;
			arr[x].second=x;
		}
		for(int x=0;x<n;x++){
			start.push_back(arr[x].first);
		}
		sort(arr,arr+n);
		for(int x=0;x<n;x++){
			start[arr[x].second]=x+1;
		}
		ans=11;
		m[0][start]=0;
		bfs.push(make_pair(start,make_pair(0,0)));
		while(!bfs.empty()){
			if(m[n].find(bfs.front().first)!=m[n].end()){//exists...
				ans=min(ans,m[n][bfs.front().first]+bfs.front().second.first);
			}
			for(int y=2;y<=n;y++){
				if(y==bfs.front().second.second)continue;
				start=bfs.front().first;
				for(int z=0;z<y;z++){
					if(z>=y-1-z)break;
					swap(start[z],start[y-1-z]);
				}
				if(bfs.front().second.first+1>5)break;
				if(m[0].find(start)==m[0].end()){
					//cout<<"k\n";
					m[0][start]=bfs.front().second.first+1;
					bfs.push(make_pair(start, make_pair(bfs.front().second.first+1,y)  ));
				}
			}
			bfs.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}