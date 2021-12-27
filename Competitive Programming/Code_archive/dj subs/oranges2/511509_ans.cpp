// ans.cpp 31 Mar 19, 21:26:12 100 0.51 Judging completed in 5.4s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
//lca
typedef long long ll;
ll n,parent[19][100005],depth[100005];
long long val[19][100005],ans=0;
bool visited[100005];

vector<pair<ll,long long> > adjlis[100005];

inline void build(ll x,long long distance,ll d){//visits parents before children...
    visited[x]=true;
    depth[x]=d;
    for(ll i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i].first ]==false){//not parents...
            parent[0][adjlis[x][i].first]=x;
			val[0][adjlis[x][i].first]=adjlis[x][i].second;
            build(adjlis[x][i].first,adjlis[x][i].second,d+1);
        }
    }
}

inline void init(){
	for(ll i=1;i<19;i++){
		for(ll j=0;j<n;j++){
			if(parent[i-1][j]==-1){
				parent[i][j]=-1;
				continue;
			}
			parent[i][j]=parent[i-1][parent[i-1][j]];
			val[i][j]=max(val[i-1][j],val[i-1][parent[i-1][j]]);
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
	ans=max(ans,val[next_bit][x]);
	return query(parent[next_bit][x],k-(1<<next_bit),next_bit-1);
}
ll query2(ll x,ll k,ll next_bit){//not counted
	if(x==-1)return -1;
	if(k==0)return x;
	if(k<(1<<next_bit)){//next_bit too huge...
		return query2(x,k,next_bit-1);
	}
	//k>=1<<nextbit, so parent[x][next_bit] is relevant...
	return query2(parent[next_bit][x],k-(1<<next_bit),next_bit-1);
}

inline ll lca(ll a,ll b){
	ll c,d;
	//Ensure that b is deeper down the graph...
	if(depth[a]>depth[b]){//not what you want...
		swap(a,b);
	}
	b=query(b,depth[b]-depth[a],18);
	//now the depth is the same...
	if(a==b)return a;
	for(ll x=18;x>=0;x--){
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
	ans=max(ans,max(val[0][a],val[0][b]));
	return parent[0][a];
}

//ufds
int mp[100005],r[100005];
int get_root(int x){
	if(mp[x]==x) return x;
	else mp[x]=get_root(mp[x]);
	return mp[x];
}
void combine(int x,int y){
	if(r[x]<r[y])mp[get_root(x)]=get_root(y);
	else if(r[y]<r[x])mp[get_root(y)]=get_root(x);
	else {
		mp[get_root(x)]=get_root(y);
		r[get_root(y)]+=1;
	}
}
bool check(int x,int y){
	return get_root(x)==get_root(y);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long e,q,a,b,c;
    cin>>n>>e>>q;
    pair<long long,pair<int,int> >  el[e];
	for(int x=0;x<n;x++){
		mp[x]=x;
	}
    for(int x=0;x<e;x++){
        cin>>a>>b>>c;
        el[x]=make_pair(c,make_pair(a,b));
    }
    sort(el,el+e);
    for(int x=0;x<e;x++){
		if(check(el[x].second.first,el[x].second.second)==false){
			combine(el[x].second.first,el[x].second.second);
			adjlis[el[x].second.first].push_back(make_pair(el[x].second.second,el[x].first));
			adjlis[el[x].second.second].push_back(make_pair(el[x].second.first,el[x].first));
		}
	}
	parent[0][0]=-1;
	val[0][0]=0;
	build(0,0,0);
	init();
	for(int x=0;x<q;x++){
		cin>>a>>b;
		ans=0;
		lca(a,b);
		cout<<ans<<'\n';
	}
    return 0;
}