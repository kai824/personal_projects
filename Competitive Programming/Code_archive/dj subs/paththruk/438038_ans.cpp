// ans.cpp 5 Dec 18, 17:00:05 46.43 0.15 Judging completed in 2.438s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,parent[19][100005],dist[100005],depth[100005];
bool visited[100005];

vector<pair<ll,ll> > adjlis[50005];

void build(ll x,ll distance,ll d){//visits parents before children...
    visited[x]=true;
    dist[x]=distance;
    depth[x]=d;
    for(ll i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i].first ]==false){//not parents...
            parent[0][adjlis[x][i].first]=x;
            build(adjlis[x][i].first,distance+adjlis[x][i].second,d+1);
        }
    }
}

void init(){
	for(ll i=1;i<19;i++){
		for(ll j=0;j<n;j++){
			if(parent[i-1][j]==-1){
				parent[i][j]=-1;
				continue;
			}
			parent[i][j]=parent[i-1][parent[i-1][j]];
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
	return query(parent[next_bit][x],k-(1<<next_bit),next_bit-1);
}

ll lca(ll a,ll b){
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
		c=query(a,(1<<x),x);
		d=query(b,(1<<x),x);
		if(c!=d){
			a=c;
			b=d;
		}
	}
	return parent[0][a];
}
ll finddist(ll a,ll b){
    ll c=lca(a,b);
    return (dist[a]-dist[c])+(dist[b]-dist[c]);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    ll a,b,c,q,k;
    for(int x=1;x<n;x++){
        cin>>a>>b>>c;
        a--;b--;//since copied from 0-indexed roadsideadverts code
        adjlis[a].push_back(make_pair(b,c));
        adjlis[b].push_back(make_pair(a,c));
    }
    parent[0][0]=-1;
    build(0,0,0);
    init();
    cin>>q>>k;
	k--;
    for(int x=0;x<q;x++){
        cin>>a>>b;
		a--;b--;
        cout<<finddist(a,k)+finddist(b,k)<<'\n';
    }
    return 0;
}