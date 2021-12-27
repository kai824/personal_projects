// ans.cpp 11 Jun 19, 15:59:07 100 0.49 Judging completed in 5.549s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<pair<ll,ll>,int> state;
//toll, dist, node
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
	int v,e,a,b,c,l;
	cin>>v>>e;
	pair<ll,ll> dist[v+5];
	for(int x=0;x<v+5;x++){
		dist[x].first=dist[x].second=1e16;
	}
	vector<pair<int, pair<ll,ll> > >adjmat[v+5];
	for(int x=0;x<e;x++){
		cin>>a>>b>>c>>l;
		adjmat[a].push_back(make_pair(b,make_pair(c,l)));
		adjmat[b].push_back(make_pair(a,make_pair(c,l)));
	}
	priority_queue<state, vector<state>, greater<state> > dijk;
	dijk.push(make_pair(make_pair(0,0),1));
	dist[1]=make_pair(0,0);
	while(!dijk.empty()){
		state top=dijk.top();
		dijk.pop();
		for(int x=0;x<adjmat[top.second].size();x++){
			pair<int,pair<ll,ll> > end=adjmat[top.second][x];
			if(make_pair(top.first.first+end.second.first,top.first.second+end.second.second)<dist[end.first]){
				dist[end.first]=make_pair(top.first.first+end.second.first,top.first.second+end.second.second);
				dijk.push(make_pair(dist[end.first],end.first));
			}
		}
	}
	for(int x=v;x<=v;x++){
		cout<<dist[x].first<<' '<<dist[x].second<<'\n';
	}
    return 0;
}