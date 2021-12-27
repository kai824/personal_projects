// ans.cpp 1 Jan 18, 16:44:49 100 0.11 Judging completed in 4.348s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,parent[18][50005],a,b,dist[50005],depth[50005];
bool visited[50005];

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
	for(ll i=1;i<18;i++){
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
	b=query(b,depth[b]-depth[a],17);
	//now the depth is the same...
	if(a==b)return a;
	for(ll x=17;x>=0;x--){
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
    return (dist[a]-dist[c])+(dist[b]-dist[c]);
}



int par[150],ran[150];
int get_root(int x){
	if(par[x]==-1) return x;
	else par[x]=get_root(par[x]);
	return par[x];
}
bool checkifconnected(int a,int b){
    return(get_root(a)==get_root(b));
}
void merge(int A,int B){
	if(checkifconnected(A,B))return;
	if(ran[A]<ran[B])par[get_root(A)]=get_root(B);
	else if(ran[B]<ran[A])par[get_root(B)]=get_root(A);
	else {
		par[get_root(A)]=get_root(B);
		ran[get_root(B)]+=1;
	}
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    int a,b,c,q;
    int aa[5];
    for(int x=1;x<n;x++){
    	cin>>a>>b>>c;
    	adjlis[a].push_back(make_pair(b,c));
    	adjlis[b].push_back(make_pair(a,c));
    }
    parent[0][0]=-1;
    build(0,0,0);
    init();
    
    cin>>q;
    vector<int>v;
    vector<pair<int,pair<int,int> > > edge_list;
    for(int x=0;x<q;x++){
    	v.clear();
    	edge_list.clear();
    	for(int i=0;i<5;i++){cin>>aa[i];v.push_back(aa[i]);}
    	for(int i=0;i<4;i++){
    		for(int i2=i+1;i2<5;i2++){
    			v.push_back(lca(aa[i],aa[i2]));
    			for(int y=0;y<v.size()-1;y++){
    				if(v[y]==v.back()){
    					v.pop_back();
    					break;
    				}
    			}
    		}
    	}
    	
    	for(int y=0;y<v.size();y++){
    		for(int z=y+1;z<v.size();z++){
    			edge_list.push_back(make_pair(finddist(v[y],v[z]),make_pair(y,z)));
    		}
    	}
    	sort(edge_list.begin(),edge_list.end());
    	int ans=0;bool broke;
    	memset(par,-1,sizeof(par));
    	memset(ran,0,sizeof(ran));
    	for(int y=0;y<edge_list.size();y++){
    		if(checkifconnected(edge_list[y].second.first,edge_list[y].second.second))continue;
    		merge(edge_list[y].second.first,edge_list[y].second.second);
    		ans+=edge_list[y].first;
    		broke=false;
    		for(int z=1;z<v.size();z++){
    			if(checkifconnected(0,z)==false){
    				broke=true;
    				break;
    			}
    		}
    		if(broke==false){
    			//all are connected...
    			break;
    		}
    	}
    	cout<<ans<<'\n';
    	
    }
    return 0;
}