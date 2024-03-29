// ans.cpp 18 Dec 19, 11:17:25 13.33 0.22 Judging completed in 4.255s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

int n,preorder[100005],a,b,parents[100005],nex=1;
bool visited[100005];

vector<int> adjlis[100005];
int subtree[100005];
int   depth[100005];
int parent[19][100005];

void build(int x,int d,int prev){//visits parents before children...
	depth[x]=d;
    visited[x]=true;
    preorder[x]=nex;nex++;
	for(int i=1;i<19;i++){
		if(parent[i-1][x]==-1)parent[i][x]=-1;
		else parent[i][x]=parent[i-1][parent[i-1][x]];
	}
    for(int i=0;i<adjlis[x].size();i++){
        if(visited[adjlis[x][i] ]==false){//not parents...
            //parents[adjlis[x][i] ]=x;
			parent[0][adjlis[x][i]]=x;
            build(adjlis[x][i],d+1,x);
        }
    }
    subtree[x]=nex-1;
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
		c=query(a,(1<<x),min(19,x+1));
		d=query(b,(1<<x),min(19,x+1));
		if(c!=d){
			a=c;
			b=d;
		}
	}
	return parents[a];
}

int ft[100050];
int ls(int x){
	return(x&(-x));
}
void update(int s,int e,int v){//rupq;
	for(;s<=100005;s+=ls(s)){
		ft[s]+=v;
	}
	e++;
	for(;e<=100005;e+=ls(e)){
		ft[e]-=v;
	}
}
int query(int p){
	int sum=0;
	for(;p;p-=ls(p)){
		sum+=ft[p];
	}
	return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,b,c,d;
    cin>>n>>m;
    for(int x=1;x<n;x++){
    	cin>>b>>c;
    	adjlis[b].push_back(c);
    	adjlis[c].push_back(b);
    }
    parents[1]=-1;
	parent[0][1]=-1;
    build(1,0,-1);
	init();
    for(int x=0;x<m;x++){
    	cin>>b>>c;
		d=lca(b,c);
		if(depth[b]==depth[d]){//delete everything from b, but keep the subtree...
			update(1,10000,1);
			d=query(c,depth[c]-depth[b]-1,19);//child of b that leads to c
			update(preorder[d],subtree[d],-1);
		}else{//depth[b]>depth[d] delete subtree of b...
			update(preorder[b],subtree[b],1);
		}
    	/*if(a=="p"){
    		cin>>b>>c;
    		update(preorder[b]+1,subtree[b],c);
    	}else{
    		cin>>b;
    		cout<<salaries[b]+query(preorder[b])<<'\n';
    	}*/
    }
	for(int x=1;x<=n;x++){
		/*for(int i=0;i<5;i++){
			cout<<parent[i][x]<<' ';
		}cout<<'\n';continue;*/
		if(query(preorder[x])>0){
			cout<<"0\n";
		}else cout<<"1\n";
	}
    return 0;
}