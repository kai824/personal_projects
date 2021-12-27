// ans.cpp 7 Dec 19, 10:49:29 100 0.15 Judging completed in 4.429s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int parent[4005],depth[4005],ans;//ufds, depth...
bool vis[4005];
int parents[4005][13],val[4005][13];
vector<pair<int,int> > adjl[4005];
pair<int,pair<int,int> > el[400005];

int getr(int x){
	if(parent[x]==-1)return x;
	parent[x]=getr(parent[x]);
	return parent[x];
}
inline bool merge(int a,int b){
	a=getr(a);b=getr(b);
	if(a==b)return false;
	parent[a]=b;
	return true;
}

void dfs(int node,int prev,int maxi,int dep){
	vis[node]=true;depth[node]=dep;
	parents[node][0]=prev;
	val[node][0]=maxi;
	for(int x=1;x<13;x++){
		if(parents[node][x-1]==-1){
			parents[node][x]=-1;val[node][x]=INT_MAX;
		}else{
			val[node][x]=max(val[node][x-1],val[ parents[node][x-1] ][x-1]);
			parents[node][x]=parents[ parents[node][x-1] ][x-1];
		}
	}
	for(int x=0;x<adjl[node].size();x++){
		if(!vis[adjl[node][x].first]){
			dfs(adjl[node][x].first,node,adjl[node][x].second,dep+1);
		}
	}
}
ll query(ll x,ll k,ll next_bit){
	if(x==-1)return -1;
	if(k==0)return x;
	if(k<(1<<next_bit)){//next_bit too huge...
		return query(x,k,next_bit-1);
	}
	//k>=1<<nextbit, so parent[x][next_bit] is relevant...
	ans=max(ans,val[x][next_bit]);
	return query(parents[x][next_bit],k-(1<<next_bit),next_bit-1);
}
ll query2(ll x,ll k,ll next_bit){//not counted
	if(x==-1)return -1;
	if(k==0)return x;
	if(k<(1<<next_bit)){//next_bit too huge...
		return query2(x,k,next_bit-1);
	}
	//k>=1<<nextbit, so parent[x][next_bit] is relevant...
	return query2(parents[x][next_bit],k-(1<<next_bit),next_bit-1);
}

inline ll lca(ll a,ll b){
	ll c,d;
	//Ensure that b is deeper down the graph...
	if(depth[a]>depth[b]){//not what you want...
		swap(a,b);
	}
	b=query(b,depth[b]-depth[a],12);
	//now the depth is the same...
	if(a==b)return a;
	for(ll x=12;x>=0;x--){
		if(depth[a]<(1<<x)){
			continue;
		}
		//1<<x should be relevant...
		c=query2(a,(1<<x),x);
		d=query2(b,(1<<x),x);
		if(c!=d){
			a=query(a,(1<<x),x);
			b=query(b,(1<<x),x);//make it count now
		}
	}
	ans=max(ans,max(val[a][0],val[b][0]));
	return parents[a][0];
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,q,a,b;
	long long sum=0;
	cin>>n>>m;
	for(int x=1;x<=n;x++){
		parent[x]=-1;
	}
	for(int x=0;x<m;x++){
		cin>>el[x].second.first>>el[x].second.second>>el[x].first;
	}
	sort(el,el+m);
	for(int x=0;x<m;x++){
		if(merge(el[x].second.first,el[x].second.second)){
			adjl[el[x].second.first].emplace_back(el[x].second.second,el[x].first);
			adjl[el[x].second.second].emplace_back(el[x].second.first,el[x].first);
			sum+=el[x].first;
		}
	}
	dfs(1,-1,0,0);
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b;
		ans=0;lca(a,b);
		cout<<sum-ans<<'\n';
	}
    return 0;
}