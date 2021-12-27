// ans.cpp 25 Dec 19, 18:25:19 0 3.07 Judging completed in 9.141s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int arr[200005];//maps the P number to the node number
int depth[200005];
int parent[200005][20];
vector<int> children[200005];
void dfs(int node,int dep){
	depth[node]=dep;
	for(int x=1;x<20;x++){
		if(parent[node][x-1]==-1)parent[node][x]=-1;
		else parent[node][x]=parent[parent[node][x-1]][x-1];
	}
	for(int x=0;x<children[node].size();x++){
		dfs(children[node][x],dep+1);
	}
}

int lca(int a,int b){
	if(depth[a]<depth[b])swap(a,b);
	//make sure a is deeper
	for(int x=19;x>=0;x--){
		if(depth[a]-depth[b]>=(1<<x)){
			a=parent[a][x];
		}
	}
	if(a==b)return a;
	for(int x=19;x>=0;x--){
		if(parent[a][x]!=parent[b][x]){
			a=parent[a][x];
			b=parent[b][x];
		}
	}
	return parent[a][0];
}

inline int dist(int a,int b){
	return depth[a]+depth[b]-(2*depth[lca(a,b)]);
}

inline pii process(pii a,pii b){//2 lines...
	if(a.first==-1 || b.first==-1){
		return make_pair(-1,-1);
	}
	int d1=dist(a.first,a.second);
	int d2=dist(a.first,b.first),d3=dist(a.second,b.first);
	if(d1+d2==d3){//put b.first on the line
		a.first=b.first;
	}else if(d1+d3==d2){
		a.second=b.first;
	}else if(d2+d3==d1){
		;//b.first is along the line of a...
	}else{
		return make_pair(-1,-1);
	}
	d1=dist(a.first,a.second);
	d2=dist(a.first,b.second);d3=dist(a.second,b.second);
	if(d1+d2==d3){//put b.second on the line...
		a.first=b.second;
	}else if(d1+d3==d2){
		a.second=b.second;
	}else if(d2+d3==d1){
		;//b.first is along the line of a...
	}else{
		return make_pair(-1,-1);
	}
	return a;
}

struct node{
	pii v=make_pair(-1,-1);
	node *l=NULL,*r=NULL;
	int s,e;
	node(int ss,int ee){
		s=ss;e=ee;
		if(s<e){
			l=new node(s,(s+e)/2);
			r=new node((s+e)/2+1,e);
		}
	}
	void update(int p,int vv){
		if(s==e){
			v=make_pair(vv,vv);
			return;
		}
		if(p<=(s+e)/2){
			l->update(p,vv);
		}else{
			r->update(p,vv);
		}
		v=process(l->v,r->v);
		//cout<<s<<' '<<e<<' '<<v.first<<' '<<v.second<<'\n';
	}
	pii query(int ll,int rr){//the simple path from l to r
		if(ll<=s && e<=rr)return v;
		pii a=make_pair(-2,-2);
		if(ll<=(s+e)/2){
			a=l->query(ll,rr);
		}
		if((s+e)/2<rr){
			if(a==make_pair(-2,-2))return r->query(ll,rr);
			a=process(a,r->query(ll,rr));
		}
		return a;
	}
} *root;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,p,q,a,b,c,d;
	int lo,hi,mid;
	cin>>n;
	int ori[n+5];//maps node number to permutation number
	root=new node(0,n);
	for(int x=1;x<=n;x++){
		cin>>p;
		arr[p]=x;//maps perm number to node number
		ori[x]=p;
	}
	parent[1][0]=-1;
	for(int x=2;x<=n;x++){//parents...
		cin>>parent[x][0];
		children[parent[x][0]].push_back(x);
	}
	dfs(1,0);
	for(int x=0;x<n;x++){
		root->update(x,arr[x]);//x refers to the node...
	}
	
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a;
		if(a==2){
			lo=1;hi=n;
			while(lo<hi){
				mid=hi-(hi-lo)/2;
				if(root->query(0,mid).first==-1){
					hi=mid-1;
				}else lo=mid;
			}
			cout<<lo+1<<'\n';
		}else{
			cin>>b>>c;
			arr[ori[b]]=c;
			arr[ori[c]]=b;
			swap(ori[b],ori[c]);
			b=ori[b];c=ori[c];//find the nodes they refer to
			root->update(b,arr[b]);
			root->update(c,arr[c]);
		}
	}
	return 0;
}