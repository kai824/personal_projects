// ans.cpp 18 Dec 19, 11:40:03 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,preorder[200005],a,b,parents[200005],nex=1;
bool visited[200005];

vector<ll> adjlis[200005];
ll subtree[200005];
ll   depth[200005];
ll parent[20][200005];

void build(ll x,ll d,ll prev){//visits parents before children...
	depth[x]=d;
    visited[x]=true;
    preorder[x]=nex;nex++;
	for(ll i=1;i<20;i++){
		if(parent[i-1][x]==-1)parent[i][x]=-1;
		else parent[i][x]=parent[i-1][parent[i-1][x]];
	}
    for(ll i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            //parents[adjlis[x][i] ]=x;
			parent[0][adjlis[x][i]]=x;
			parents[adjlis[x][i]]=x;
            build(adjlis[x][i],d+1,x);
        }
    }
    subtree[x]=nex-1;
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
		c=query(a,(1<<x),min((long long)19,x+1));
		d=query(b,(1<<x),min((long long)19,x+1));
		if(c!=d){
			a=c;
			b=d;
		}
	}
	return parent[0][a];
}

ll ft[200050];
ll ls(ll x){
	return(x&(-x));
}
void update(ll s,ll e,ll v){//rupq;
	for(;s<=200005;s+=ls(s)){
		ft[s]+=v;
	}
	e++;
	for(;e<=200005;e+=ls(e)){
		ft[e]-=v;
	}
}
ll query(ll p){
	ll sum=0;
	for(;p;p-=ls(p)){
		sum+=ft[p];
	}
	return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll m,bb,cc,dd,total=0;
    cin>>n>>m;
    for(ll x=1;x<n;x++){
    	cin>>bb>>cc;
    	adjlis[bb].push_back(c);
    	adjlis[cc].push_back(bb);
    }
    parents[1]=-1;
	parent[0][1]=-1;
    build(1,0,-1);
    for(ll x=0;x<m;x++){
    	cin>>bb>>c;
		dd=lca(bb,cc);
		if(bb==dd){//delete everything from b, but keep the subtree...
			dd=query(cc,depth[cc]-depth[bb]-1,19);//child of b that leads to c
			total++;
			update(preorder[dd]+1,subtree[dd],-1);
		}else{//depth[b]>depth[d] delete subtree of b...
			update(preorder[bb],subtree[bb],1);
		}
    }
	for(ll x=1;x<=n;x++){
		if(total+query(preorder[x])>0){
			cout<<"0\n";
		}else cout<<"1\n";
	}
    return 0;
}