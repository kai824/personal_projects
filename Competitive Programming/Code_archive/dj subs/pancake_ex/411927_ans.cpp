// ans.cpp 13 Nov 18, 22:06:07 80 2.29 Judging completed in 4.979s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#pragma O3
typedef long long ll;
inline ll convert(vector<int> a){
	int ans=0;
	for(int x=0;x<a.size();x++){
		ans*=10;
		ans+=a[x];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> start;
	queue<pair<vector<int>,pair<int,int> > >bfs;
	unordered_map<ll,int> m[11];
	//permutation, distance from ideal
	bool sorted;
	int tc,n,a,ans;
	ll tmp;
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
		m[x][convert(start)]=0;
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
				tmp=convert(start);
				if(m[x].find(tmp)==m[x].end()){
					//cout<<"k\n";
					m[x][tmp]=bfs.front().second.first+1;
					bfs.push(make_pair(start, make_pair(bfs.front().second.first+1,y)  ));
				}
			}
			bfs.pop();
		}
		//cout<<x<<'\n';
	}
	//cout<<"ready\n";
	while(tc--){
		//m[0].clear();
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
		//m[0][start]=0;
		bfs.push(make_pair(start,make_pair(0,0)));
		while(!bfs.empty()){
		    tmp=convert(bfs.front().first);
			if(m[n].find(tmp)!=m[n].end()){//exists...
				ans=(m[n][tmp]+bfs.front().second.first);
				break;
			}
			for(int y=2;y<=n;y++){
				if(y==bfs.front().second.second)continue;
				start=bfs.front().first;
				for(int z=0;z<y;z++){
					if(z>=y-1-z)break;
					swap(start[z],start[y-1-z]);
				}
				if(bfs.front().second.first+1>5)break;
				//if(m[0].find(start)==m[0].end()){
					//cout<<"k\n";
					//m[0][start]=bfs.front().second.first+1;
					bfs.push(make_pair(start, make_pair(bfs.front().second.first+1,y)  ));
				//}
			}
			bfs.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}