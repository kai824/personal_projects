// ans.cpp 19 Nov 19, 09:59:13 22 0.18 Judging completed in 5.367s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int> > adjl[100005];
ll n,q;
ll d[100005],aa[100005];
ll pa[100005],parent[20][100005],dist[100005],depth[100005];
bool visited[100005];

void build(ll x,ll distance,ll dd){//distance is sum of node weights to current node...
    visited[x]=true;
    dist[x]=distance;
    depth[x]=dd;
    for(ll i=0;i<adjl[x].size();i++){
        if(visited[adjl[x][i].first ]==false){//not parents...
            parent[0][adjl[x][i].first]=x;
            build(adjl[x][i].first,distance+d[adjl[x][i].first],dd+1);
        }
    }
}

void init(ll node){
	for(ll i=1;i<20;i++){
		for(ll j=1;j<=n;j++){
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
	ll c,dd;
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
		dd=query(b,(1<<x),min((long long)19,x+1));
		if(c!=dd){
			a=c;
			b=dd;
		}
	}
	return parent[0][a];
}

inline ll get_dist(ll a,ll b){
    int node=lca(a,b);
    return dist[a]+dist[b]-(dist[node]*2)+d[node];
}

int dia[100005][2];//store 2 ends of diameter...

ll get_root(ll x){
    if(pa[x]==-1)return x;
    pa[x]=get_root(pa[x]);
    return pa[x];
}

void merge(int a, int b){
    a=get_root(a);b=get_root(b);
    if(a==b)return;
    pa[a]=b;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>q;
    ll a,b,bb,l,lo,hi,mid,limit,ans=0;
    pair<int,pair<int,int> > el[n-1];
    for(int x=1;x<n;x++){
        cin>>a>>b>>l;
        el[x-1]=make_pair(l,make_pair(a,b));
        adjl[a].push_back(make_pair(b,l));
        adjl[b].push_back(make_pair(a,l));
    }
    b=0;
    for(int x=0;x<n;x++){
        cin>>d[x+1];
        b=max(b,d[x+1]);
        pa[x+1]=-1;
        dia[x+1][0]=dia[x+1][1]=x+1;
    }
    ans=bb=b;
    sort(el,el+n-1);
    parent[1][0]=-1;
    build(1,d[1],0);
    init(1);//root tree at node 1...
    bool n1,n2;
    for(int x=0;x<n-1;x++){
        limit=el[x].first;
        a=get_root(el[x].second.first);
        b=get_root(el[x].second.second);
        
        if(get_dist(dia[a][0],el[x].second.first)>get_dist(dia[a][1],el[x].second.first))n1=0;
        else n1=1;
        if(get_dist(dia[b][0],el[x].second.second)>get_dist(dia[b][1],el[x].second.second))n2=0;
        else n2=1;
        l=get_dist(dia[a][n1],el[x].second.first) + get_dist(dia[b][n2],el[x].second.second);
        merge(a,b);
		if(n2==0)swap(dia[b][0],dia[b][1]);
        dia[b][0]=dia[a][n1];
		//{dia[a][n1],dia[b][n2]}
        
        ans=max(ans,l);
        aa[x]=ans;
		//cout<<aa[x]<<' '<<l<<'\n';
    }
    for(int x=0;x<q;x++){
        cin>>a;
        if(a<el[0].first){
            cout<<bb<<"\n";
            continue;
        }
        lo=0;
        hi=n-2;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(el[mid].first>a)hi=mid-1;
            else lo=mid;
        }
        cout<<aa[lo]<<'\n';
    }
    return 0;
}

/*
5 4
1 2 4
2 3 2
3 4 3
4 5 6
1 3 3 1 5
*/