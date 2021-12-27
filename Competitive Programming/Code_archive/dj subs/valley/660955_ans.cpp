// ans.cpp 23 Dec 19, 12:41:05 59 0.22 Judging completed in 3.95s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> pii;

vector<pii> adjl[100005];
pii edges[100005];
bool shop[100005];
ll parent[100005][20],dist[100005],depth[100005];
ll dis[2000];

void dfs(ll x,ll p,ll dst,ll dep){
    dist[x]=dst;depth[x]=dep;
    parent[x][0]=p;
    for(ll i=1;i<20;i++){
        if(parent[x][i-1]==-1)parent[x][i]=-1;
        else parent[x][i]=parent[parent[x][i-1]][i-1];
    }//2k decomp
    for(ll i=0;i<adjl[x].size();i++){
        if(adjl[x][i].first==p)continue;
        dfs(adjl[x][i].first,x,dst+adjl[x][i].second,dep+1);
    }
}

ll query(ll x,ll k,ll next_bit){
	if(x==-1)return -1;
	if(k==0)return x;
	if(k<(1<<next_bit)){//next_bit too huge...
		return query(x,k,next_bit-1);
	}
	//k>=1<<nextbit, so parent[x][next_bit] is relevant...
	return query(parent[x][next_bit],k-(1<<next_bit),next_bit-1);
}

ll lca(ll a,ll b){
	ll c,d;
	//Ensure that b is deeper down the graph...
	if(depth[a]>depth[b]){//not what you want...
		swap(a,b);
	}
	b=query(b,depth[b]-depth[a],19ll);
	//now the depth is the same...
	if(a==b)return a;
	for(ll x=19;x>=0;x--){
		if(depth[a]<(1<<x)){
			continue;
		}
		//1<<x should be relevant...
		c=query(a,(1<<x),19ll);
		d=query(b,(1<<x),19ll);
		if(c!=d){
			a=c;
			b=d;
		}
	}
	return parent[a][0];
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,s,q,e,a,b,b2,b3,c,d,node;
    cin>>n>>s>>q>>e;
    for(ll x=1;x<n;x++){
        cin>>a>>b>>c;
        edges[x]=make_pair(a,b);
        adjl[a].push_back(make_pair(b,c));
        adjl[b].push_back(make_pair(a,c));
    }
    dfs(e,-1,0,1);
    for(ll x=0;x<s;x++){
        cin>>a;shop[a]=true;
    }
    priority_queue<pii,vector<pii>,greater<pii> > dijk;
    for(ll x=0;x<q;x++){
        cin>>a>>b;
        b2=b3=b;
        c=edges[a].first;d=edges[a].second;
        if(c>d)swap(c,d);
        if(lca(c,b2)==c && lca(d,b3)==d){
            //edge is along the line...
            if(n>1000){
                cout<<"0\n";
            }else{
                while(!dijk.empty()){
                    dijk.pop();
                }
                for(ll x=1;x<=n;x++){
                    dis[x]=LLONG_MAX;
                }dis[b]=0;
                dijk.push(make_pair(0,b));//dist, node
                while(!dijk.empty()){
                    node=dijk.top().second;
                    if(shop[node]){
                        break;
                    }
                    dijk.pop();
                    for(ll x=0;x<adjl[node].size();x++){
                        if(c==min(node,adjl[node][x].first) && d==max(node,adjl[node][x].first))continue;
                        if(dis[node]+adjl[node][x].second<dis[adjl[node][x].first]){
                            dis[adjl[node][x].first]=dis[node]+adjl[node][x].second;
                            dijk.push(make_pair(dis[node]+adjl[node][x].second,adjl[node][x].first));
                        }
                    }
                }
                if(dijk.empty())cout<<"oo\n";
                else cout<<dijk.top().first<<'\n';
            }
        }else{
            cout<<"escaped\n";
        }
    }
    return 0;
}
/*
5 2 3 1
1 2 3
1 3 2
3 4 1
3 5 2
2 4

2 2
2 5
4 5
*/