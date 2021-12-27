// ans.cpp 12 Dec 17, 16:36:19 0 0.22 Judging completed in 3.579s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,parent[20][300005],a,b,depth[300005],value[300005],node[300005];//node points stack i to the correct node of the card...
bool visited[300005];

vector<ll> adjlis[300005];

void build(ll x,ll d){//visits parents before children...
    visited[x]=true;
    depth[x]=d;
    for(ll i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            parent[0][adjlis[x][i]]=x;
            build(adjlis[x][i],d+1);
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
	return parent[0][a];
}
int finddist(int a,int b){
    int c=lca(a,b);
    return (depth[a]-depth[c])+(depth[b]-depth[c]);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll b,c;string a;
    cin>>n;
    parent[0][0]=-1;
    build(0,0);
    init();
    node[0]=0;
    value[0]=-1;
    depth[0]=0;
    for(int x=1;x<=n;x++){
        cin>>a;
        if(a=="a"){
        	cin>>b;
        	b=node[b];//get the right node first...
        	parent[0][x]=b;
        	node[x]=x;
        	value[x]=x;
        	for(int y=1;y<20;y++){
	            if((1<<y)>depth[x]){
	                parent[y][x]=-1;
	                continue;
	            }
	            parent[y][x]=query(parent[y-1][x],(1<<(y-1) ) ,19);
	        }
	        depth[x]=depth[b]+1;
        }else if(a=="b"){
        	cin>>b;b=node[b];
        	cout<<value[node[b]]<<'\n';
        	node[x]=parent[0][node[b]];//parent of the node representation of stack b...
        	for(int y=0;y<20;y++){
        		parent[y][x]=parent[y][parent[0][node[b]]];
        	}
        }else if(a=="c"){
        	cin>>b>>c;
        	b=node[b];c=node[c];
        	cout<<depth[lca(b,c)]<<'\n';
        	node[x]=b;
        }
    }
    return 0;
}