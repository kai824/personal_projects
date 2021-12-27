// ans.cpp 22 Dec 19, 15:15:12 0 5.01 Judging completed in 10.989s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimization("O3")
#pragma GCC optimization("axv2")
#pragma GCC optimization("unroll-loops")

typedef vector<int> vi;

vector<pair<int,int> > adjl[100005];
bool vis[100005];
int dist[100005],preorder[100005],rt[100005],parent[100005];
int arr[100005],arr2[100005];
int nex=1,k;

vi process(vi a,vi b){
	vi c;int it1,it2;it1=it2=0;
	while((it1<a.size() || it2<b.size()) && c.size()<k){
		if(a.size()==it1){
			c.push_back(b[it2]);it2++;
		}else if(b.size()==it2){
			c.push_back(a[it1]);it1++;
		}else if(a[it1]<=b[it2]){
			c.push_back(a[it1]);it1++;
		}else{
			c.push_back(b[it2]);it2++;
		}
	}
	return c;
}

struct node{
	vi v;
	node *l=NULL,*r=NULL;
	node(){}

	void build(int s,int e){
		v.clear();
		if(s==e){
			v.push_back(arr[s]);
			return;
		}
		l=new node();r=new node();
		l->build(s,(s+e)/2);
		r->build((s+e)/2+1,e);
		v=process(l->v,r->v);
	}

	void update(int b,int s,int e){
		v.clear();
		if(s==e){
			v.push_back(arr[s]);
			return;
		}
		if(b<=(s+e)/2)l->update(b,s,(s+e)/2);
		else r->update(b,(s+e)/2+1,e);
		v=process(l->v,r->v);
	}
	
	vector<int> query(int a,int b,int s,int e){
	    if(a<=s&&e<=b)return v;
		vi bb,cc;
		if(a>b)return bb;
	    if( ( (s+e)/2 )<a ){//left child not relevant
	    }else{//left child relevant;
	        bb=l->query(a,b,s,(s+e)/2);
	    }
	    if(b<=( (s+e)/2 ) ){//right child irrelvant
	    }else{
	        cc=r->query(a,b,((s+e)/2) + 1,e);
	    }
	    return process(bb,cc);
	}
} *root;

int dfs(int node){
	vis[node]=true;
	int cnt=1,a,cur=0,it=-1;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x].first]==false){
			a=dfs(adjl[node][x].first);
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
		if(vis[adjl[node][x].first]==true){
			if(x==0)dfs2(adjl[node][x].first,dd+1,node,heavy_root=heavy_root);//heavy edge...
			else dfs2(adjl[node][x].first,dd+1,node);//light edge...
		}
	}
}

int qry(int a,int b){
	vi v;
    if(dist[a]>dist[b])swap(a,b);
	while(rt[a]!=rt[b]){
		if(dist[rt[a]]>dist[rt[b]])swap(a,b);
		v=process(v,root->query(preorder[rt[b]],preorder[b],1,nex-1) );
		/*update(preorder[rt[b]],1);
		update(preorder[b]+1,-1);*/
		b=parent[rt[b]];
	}
	if(dist[a]>dist[b])swap(a,b);
	v=process(v,root->query(preorder[a],preorder[b],1,nex-1));
	if(v.size()<k)return -1;
	else return v[k-1];
	//update(preorder[a],1);update(preorder[b]+1,-1);
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,a,b,c,p=1;
	cin>>n>>q;k=INT_MAX;
	for(int x=1;x<=n;x++){
		cin>>arr2[x];
	}
	for(int x=1;x<n;x++){
		cin>>a>>b;
		adjl[a].emplace_back(b,1);
		adjl[b].emplace_back(a,1);
	}
	dfs(1);
	dfs2(1,1,1);//node, distance, parent...
	for(int x=1;x<=n;x++){//nodes numbered 1 to n
		arr[preorder[x]]=arr2[x];
	}
	root=new node();
	root->build(1,nex-1);
	for(int x=0;x<q;x++){
		cin>>k>>a>>b;
		if(k==0){
			arr[preorder[a]]=b;
			k=INT_MAX;
			root->update(preorder[a],1,nex-1);
			continue;
		}
		p=qry(a,b);
		if(p==-1)cout<<"invalid request!\n";
		else cout<<p<<'\n';
	}
	return 0;
}