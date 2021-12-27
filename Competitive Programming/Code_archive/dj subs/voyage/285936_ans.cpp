// ans.cpp 9 Dec 17, 22:14:09 100 0.21 Judging completed in 4.722s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,parent[20][200005],a,b,parents[200005],dist[200005],depth[200005];
bool visited[200005];

vector<ll> adjlis[200005];

void build(ll x,ll distance,ll d){//visits parents before children...
    visited[x]=true;
    dist[x]=distance;
    depth[x]=d;
    for(ll i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            parents[adjlis[x][i] ]=x;
            parent[0][adjlis[x][i]]=x;
            build(adjlis[x][i],distance+1,d+1);
        }
    }
}

void init(){
	for(ll i=1;i<20;i++){
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
	b=query(b,depth[b]-depth[a],19);
	//now the depth is the same...
	if(a==b)return a;
	for(ll x=19;x>=0;x--){
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
	return parents[a];
}
int finddist(int a,int b){
    int c=lca(a,b);
    return (dist[a]-dist[c])+(dist[b]-dist[c]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int w,s=0,e=0;
    parents[0]=-1;
    parent[0][0]=-1;
    build(0,0,0);
    init();
    for(int x=1;x<n;x++){
        cin>>w;w--;
        parent[0][x]=w;
        parents[x]=w;
        depth[x]=depth[w]+1;
        dist[x]=dist[w]+1;
        for(int y=1;y<20;y++){
            if((1<<y)>dist[x]){
                parent[y][x]=-1;
                continue;
            }
            parent[y][x]=query(parent[y-1][x],(1<<(y-1) ) ,19);
        }
        if(finddist(s,x)>finddist(s,e)){
            e=x;
        }else if(finddist(x,e)>finddist(s,e)){
            s=x;
        }
        cout<<finddist(s,e)<<'\n';
    }
    return 0;
}