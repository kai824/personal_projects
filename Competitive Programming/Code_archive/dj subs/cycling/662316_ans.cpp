// ans.cpp 24 Dec 19, 11:52:16 0 0.76 Judging completed in 6.407s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> adjl[500000];
pii dist[500000];
//distance, max cost of edge so far

pii tmp[500000];
//max cost, node number...

bool valid[500000];
bool vis[500000];
int parent[500000];
int getr(int x){
	if(parent[x]==-1)return x;
	parent[x]=getr(parent[x]);
	return parent[x];
}
inline void merge(int a,int b){
	a=getr(a);b=getr(b);
	if(a==b)return;
	parent[a]=b;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,e,s,a,b,c,ans=0,it=0;
    cin>>n>>e>>s;
    for(int x=0;x<n;x++){
        dist[x].first=INT_MAX;
		dist[x].second=INT_MAX;
        //maxi[x]=0;
    }dist[s]=make_pair(0,0);
	pair<int,pair<int,int> >el[e];
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        adjl[a].emplace_back(b,c);
        adjl[b].emplace_back(a,c);
		el[x].first=c;
		el[x].second.first=a;
		el[x].second.second=b;
    }
    priority_queue<pair<pii,int>,vector<pair<pii,int> >,greater<pair<pii,int> > > pq;
    pq.push(make_pair(make_pair(0,0),s));//distances, node
    while(!pq.empty()){
        a=pq.top().second;
		pq.pop();
        for(int x=0;x<adjl[a].size();x++){
            if(make_pair(dist[a].first+adjl[a][x].second,max(dist[a].second,adjl[a][x].second) )<dist[ adjl[a][x].first ]){
				dist[adjl[a][x].first]=make_pair(dist[a].first+adjl[a][x].second,max(dist[a].second,adjl[a][x].second) );
				pq.push(make_pair(dist[adjl[a][x].first],adjl[a][x].first) );
			}
        }
    }
	for(int x=0;x<n;x++){
		valid[x]=false;
		parent[x]=-1;
		tmp[x]=make_pair(dist[x].second,x);
		cout<<dist[x].first<<' '<<dist[x].second<<'\n';
	}
	sort(tmp,tmp+n);it=1;//since starting node doesn't count
	sort(el,el+e);
	for(int x=0;x<e;x++){
		if(it>=n)break;
		if(el[x].first>=tmp[it].first){
			cout<<tmp[it].first<<' '<<tmp[it].second<<'\n';
			if(getr(s)==getr(tmp[it].second)){
				valid[tmp[it].second]=false;
			}else{
				valid[tmp[it].second]=true;
			}
			it++;
			x--;
			continue;
		}
		merge(el[x].second.first,el[x].second.second);
	}
	for(int x=0;x<n;x++){
		if(valid[x])ans=x;
	}
	for(int x=0;x<n;x++){
		if(valid[x]){
			cout<<x;
			if(x<ans)cout<<' ';
		}
	}
    return 0;
}

/*
4 4 0
0 1 5
1 2 1
0 3 3
2 3 4
*/