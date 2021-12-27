#include"bits/stdc++.h"
using namespace std;
/* dec 17 2019...*/
typedef pair<int,int> pii;
typedef long long ll;

/*
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
*/
vector<pii> adjl[1005];//adj list
ll distf[1005],distb[1005];//distance from node 1 and node n...

int main(){
	freopen ("pump.in","r",stdin);
	freopen ("pump.out","w",stdout);
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,a,b,c,d;
	ll ans=LLONG_MIN;
	cin>>n>>m;
	pair<pii,pii> edge[m];
	for(int x=1;x<=n;x++){
		distf[x]=distb[x]=1e15;
	}
	distf[1]=distb[n]=0;
	for(int x=0;x<m;x++){
		cin>>edge[x].second.first>>edge[x].second.second>>edge[x].first.second>>edge[x].first.first;
		//the 2 nodes, cost, flow rate...
	}
	sort(edge,edge+m,greater<pair<pii,pii> >() );
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq1,pq2;//dist, node...
	for(int i=0;i<m;i++){
		a=edge[i].second.first;b=edge[i].second.second;c=edge[i].first.second;
		adjl[a].emplace_back(b,c);
		adjl[b].emplace_back(a,c);
		ans=max(ans,1000000ll*edge[i].first.first/min(distf[a]+distb[b]+c,distf[b]+distb[a]+c) );//flow rate/cost * 1e6

		while(!pq1.empty()){pq1.pop();}
		while(!pq2.empty()){pq2.pop();}
		if(distf[a]>distf[b]+c){
			distf[a]=distf[b]+c;
			pq1.push(make_pair(distf[a],a));
		}
		if(distf[b]>distf[a]+c){
			distf[b]=distf[a]+c;
			pq1.push(make_pair(distf[b],b));
		}
		while(!pq1.empty()){
			d=pq1.top().second;
			pq1.pop();
			for(int x=0;x<adjl[d].size();x++){
				if(distf[d]+adjl[d][x].second<distf[adjl[d][x].first]){
					distf[adjl[d][x].first]=distf[d]+adjl[d][x].second;
					pq1.push(make_pair(distf[adjl[d][x].first],adjl[d][x].first));
				}
			}
		}
		if(distb[a]>distb[b]+c){
			distb[a]=distb[b]+c;
			pq2.push(make_pair(distb[a],a));
		}
		if(distb[b]>distb[a]+c){
			distb[b]=distb[a]+c;
			pq2.push(make_pair(distb[b],b));
		}
		while(!pq2.empty()){
			d=pq2.top().second;
			pq2.pop();
			for(int x=0;x<adjl[d].size();x++){
				if(distb[d]+adjl[d][x].second<distb[adjl[d][x].first]){
					distb[adjl[d][x].first]=distb[d]+adjl[d][x].second;
					pq2.push(make_pair(distb[adjl[d][x].first],adjl[d][x].first));
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
