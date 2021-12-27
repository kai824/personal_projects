// ans.cpp 22 Dec 19, 14:48:44 24 2.01 Judging completed in 7.754s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
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
	
	/*void update(int p,int new_val,int s,int e){
	    if(p==s && p==e){
	        v=new_val;
	        return;
	    }
	    if(p<=(s+e)/2){
	        //update the left...
	        if(l==NULL)l=new node(s,(s+e)/2);
	        l->update(p,new_val,s,(s+e)/2);
	        if(r==NULL){
	            v=process(l->v,DEFAULT_VALUE);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }else{
	        //update the right...
	        if(r==NULL)r=new node(((s+e)/2) + 1,e);
	        r->update(p,new_val,((s+e)/2) + 1,e);
	        if(l==NULL){
	            v=process(DEFAULT_VALUE,r->v);
	        }else{
	            v=process(l->v,r->v);
	        }
	    }
	}*/
	
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

int dfs(int node,int prev){
	vis[node]=true;
	arr2[node]=prev;
	int cnt=1,a,cur=0,it=-1;
	for(int x=0;x<adjl[node].size();x++){
		if(vis[adjl[node][x].first]==false){
			a=dfs(adjl[node][x].first,adjl[node][x].second);
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
	v=process(v,root->query(preorder[a]+1,preorder[b],1,nex-1));
	if(v.size()==0)return -10;
	else return v.back();
	//update(preorder[a]+1,1);update(preorder[b]+1,-1);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,a,b,c,p=1;
	cin>>n>>k>>q;
	for(int x=1;x<n;x++){
		cin>>a>>b>>c;
		adjl[a].emplace_back(b,c);
		adjl[b].emplace_back(a,c);
	}
	dfs(0,INT_MAX);
	dfs2(0,1,0);//node, distance, parent...
	for(int x=0;x<n;x++){
		arr[preorder[x]]=arr2[x];
	}
	root=new node();
	root->build(1,nex-1);
	for(int x=0;x<q;x++){
		cin>>a>>b;
		a+=p;b+=p;
		a%=n;b%=n;
		if(a<0)a+=n;
		if(b<0)b+=n;
		if(a==b)p=-1;
		else p=qry(a,b);
		cout<<p<<'\n';
	}
	return 0;
}