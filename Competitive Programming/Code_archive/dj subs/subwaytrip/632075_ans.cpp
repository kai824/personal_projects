// ans.cpp 6 Dec 19, 17:11:08 0 1.08 Judging completed in 5.801s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

int dist[400005];
pair<int,int> arr[400005];//opposite of mp
map<pair<int,int>,int> mp;
//map pair(node,colour) to our node number...

vector<pair<int,int> > adjlis[400005];//adjlis

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m,a,b,c,d,cur=0;
	cin>>n>>m;
	deque<int> bfs;
	for(int x=0;x<m;x++){
		cin>>a>>b>>c;
		adjlis[a].push_back(make_pair(b,c));
		adjlis[b].push_back(make_pair(a,c));
		if(mp.find(make_pair(a,c))==mp.end()){
			mp[make_pair(a,c)]=cur;
			dist[cur]=INT_MAX;
			if(a==1){
				dist[cur]=0;
				bfs.push_back(cur);
			}
			arr[cur]=make_pair(a,c);
			cur++;
		}else{
			d=mp[make_pair(a,c)];
			if(a==1 && dist[d]>0){
				dist[d]=0;
				bfs.push_back(d);
			}
		}
		swap(a,b);
		if(mp.find(make_pair(a,c))==mp.end()){
			mp[make_pair(a,c)]=cur;
			dist[cur]=INT_MAX;
			if(a==1){
				dist[cur]=0;
				bfs.push_back(cur);
			}
			arr[cur]=make_pair(a,c);
			cur++;
		}else{
			d=mp[make_pair(a,c)];
			if(a==1 && dist[d]>0){
				dist[d]=0;
				bfs.push_back(d);
			}
		}
	}
	while(bfs.size()>0){
		d=bfs.front();
		a=arr[bfs.front()].first;
		b=arr[bfs.front()].second;
		bfs.pop_front();
		if(a==n){
			if(dist[d]==INT_MAX)cout<<-1;
			else cout<<dist[d]+1;
			return 0;
		}
		for(int x=0;x<adjlis[a].size();x++){
			c=mp[adjlis[a][x]];
			if(dist[c]<=dist[d])continue;
			if(adjlis[a][x].second==b){
				dist[c]=dist[d];
				bfs.push_front(c);
			}else{
				dist[c]=dist[d]+1;
				bfs.push_back(c);
			}
		}
	}
	cout<<-1;
	return 0;
}