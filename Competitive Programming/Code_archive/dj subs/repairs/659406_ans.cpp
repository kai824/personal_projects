// ans.cpp 21 Dec 19, 23:13:02 38 0.28 Judging completed in 5.355s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adjl[100005];
bool vis[100005];
int dist[100005],preorder[100005],rt[100005],parent[100005],subtree[100005];
int nex=1;

int dfs(int node){
	vis[node]=true;
	int cnt=1,a,cur=0,it=-1;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]==false){
			a=dfs(adjl[node][x]);
			cnt+=a;
			if(a>cur){
				cur=a;
				it=x;
			}
		}
	}
	if(it>0){
		swap(adjl[node][it],adjl[node][0]);
	}
	return cnt;
}
void dfs2(int node,int dd,int prev,int heavy_root=-1){
	if(heavy_root==-1)heavy_root=node;
	rt[node]=heavy_root;
	vis[node]=false;
	dist[node]=dd;parent[node]=prev;
	preorder[node]=nex;nex++;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x]]==true){
			if(x==0)dfs2(adjl[node][x],dd+1,node,heavy_root=heavy_root);//heavy edge...
			else dfs2(adjl[node][x],dd+1,node);//light edge...
		}
	}
	subtree[node]=nex-1;
}

//segtree
struct node{
	ll lazy=0,l_set=-1;
	node *l=NULL,*r=NULL;
	node(){}
	void sett(int s,int e,int a,int b,ll v){
		//cout<<'s'<<s<<' '<<e<<' '<<a<<' '<<b<<' '<<v<<'\n';
		if(a<=s && e<=b){
			lazy=0;l_set=v;
			return;
		}
		if(l==NULL)l=new node();
		if(r==NULL)r=new node();
		if(l_set==-1){
			l->lazy+=lazy;
			r->lazy+=lazy;
			lazy=0;
		}else{
			l->l_set=r->l_set=l_set;
			l_set=-1;
		}
		if(a<=(s+e)/2){
			l->sett(s,(s+e)/2,a,b,v);
		}
		if(b>(s+e)/2){
			r->sett((s+e)/2+1,e,a,b,v);
		}
	}
	void update(int s,int e,int a,int b,ll c){
		//cout<<'u'<<a<<' '<<b<<' '<<c<<'\n';
		if(a<=s && e<=b){
			lazy+=c;
			return;
		}
		if(l==NULL)l=new node();
		if(r==NULL)r=new node();
		if(l_set==-1){
		}else{
			l->l_set=r->l_set=l_set;
			l_set=-1;
			l->lazy=r->lazy=0;
		}
		if(a<=(s+e)/2){
			l->update(s,(s+e)/2,a,b,c);
		}
		if(b>(s+e)/2){
			r->update((s+e)/2+1,e,a,b,c);
		}
	}
	ll query(int s,int e,int p){
		if((s==p && p==e) || l_set!=-1){
			if(l_set==-1)return lazy;
			return l_set+lazy;
		}
		if(p<=(s+e)/2){
			if(l==NULL){
				if(l_set==-1)return lazy;
				return lazy+l_set;
			}
			return l->query(s,(s+e)/2,p)+lazy;
		}
		if(p>(s+e)/2){
			if(r==NULL){
				if(l_set==-1)return lazy;
				return lazy+l_set;
			}
			return r->query((s+e)/2 + 1,e,p)+lazy;
		}
		return 0;
	}
} *root;

void plant(int a,int b,int c){
    if(dist[a]>dist[b])swap(a,b);
	while(rt[a]!=rt[b]){
		if(dist[rt[a]]>dist[rt[b]])swap(a,b);
		root->update(0,100005,preorder[rt[b]],preorder[b],c);
		//cout<<'u'<<preorder[rt[b]]<<' '<<preorder[b]<<' '<<c<<'\n';
		b=parent[rt[b]];
	}
	if(dist[a]>dist[b])swap(a,b);
	root->update(0,100005,preorder[a],preorder[b],c);
	//cout<<'u'<<preorder[a]<<' '<<preorder[b]<<' '<<c<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,t,a,b,c;
	root=new node();
	cin>>n>>q;
	for(int x=1;x<n;x++){
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}
	dfs(0);//choose which child is heavy...
	dfs2(0,1,0);
	for(int x=0;x<q;x++){
		cin>>t;
		if(t==1){
			cin>>a>>b>>c;//update along a path
			plant(a,b,c);
		}else if(t==2){
			cin>>a>>b;//repair whole subtree of a and set value to b...
			root->sett(0,100005,preorder[a],subtree[a],b);
		}else if(t==3){
			cin>>a;//point query on node a...
			cout<<root->query(0,100005,preorder[a])<<'\n';
		}
	}
	return 0;
}