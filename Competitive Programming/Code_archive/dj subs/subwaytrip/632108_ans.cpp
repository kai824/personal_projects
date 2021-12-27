// ans.cpp 6 Dec 19, 17:59:41 0 0.57 Judging completed in 5.28s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int dist[400005];
pair<int,int> arr[400005];//opposite of mp
//map<pair<int,int>,int> mp;
unordered_map<int,int> mp[100005];

//map pair(node,colour) to our node number...

vector<pair<int,bool> > adjlis[400005];//end, weight

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,b,c,d,cur=0;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		mp[x][-1]=cur;
		dist[cur]=INT_MAX;
		arr[cur]=make_pair(x,-1);
		cur++;
	}
	deque<int> bfs;
	for(int x=0;x<m;x++){
		cin>>a>>b>>c;
		if(mp[a].find(c)==mp[a].end()){
			mp[a][c]=cur;
			dist[cur]=INT_MAX;
			arr[cur]=make_pair(a,c);
			cur++;
			if(mp[a].find(-1)==mp[a].end()){
				mp[a][-1]=cur;
				dist[cur]=INT_MAX;
				if(a==1)dist[cur]=0;
				arr[cur]=make_pair(a,-1);
				cur++;
			}
			adjlis[mp[a][c]].emplace_back(mp[a][-1],0);
			adjlis[mp[a][-1]].emplace_back(mp[a][c],1);
		}
		swap(a,b);
		if(mp[a].find(c)==mp[a].end()){
			mp[a][c]=cur;
			dist[cur]=INT_MAX;
			arr[cur]=make_pair(a,c);
			cur++;
			if(mp[a].find(-1)==mp[a].end()){
				mp[a][-1]=cur;
				dist[cur]=INT_MAX;
				if(a==1)dist[cur]=0;
				arr[cur]=make_pair(a,-1);
				cur++;
			}
			adjlis[mp[a][c]].emplace_back(mp[a][-1],0);
			adjlis[mp[a][-1]].emplace_back(mp[a][c],1);
		}
		adjlis[mp[a][c]].emplace_back(mp[b][c],0);
		adjlis[mp[b][c]].emplace_back(mp[a][c],0);
	}
	bfs.push_back(mp[1][-1]);
	dist[mp[1][-1]]=0;
	while(bfs.size()>0){
		a=bfs.front();
		bfs.pop_front();
		//cout<<a<<' '<<arr[a].first<<' '<<arr[a].second<<'\n';
		if(a==mp[n][-1]){
			if(dist[a]==INT_MAX)cout<<-1;
			else cout<<dist[a]+1;
			return 0;
		}
		for(int x=0;x<adjlis[a].size();x++){
			c=adjlis[a][x].first;
			if(dist[c]<=dist[a])continue;
			if(adjlis[a][x].second){
				dist[c]=dist[a]+1;
				bfs.push_back(c);
			}else{
				dist[c]=dist[a];
				bfs.push_front(c);
				if(c==mp[n][-1]){
					cout<<dist[c];return 0;
				}
			}
		}
	}
	cout<<-1;
	return 0;
}