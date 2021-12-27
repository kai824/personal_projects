// ans.cpp 18 Jan 20, 15:08:20 13 1.24 Judging completed in 8.038s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL xx;
//xx is the threshold...

LL aa[500005],nex=1;
LL preorder[500005],subtree[500005];
vector<LL> adjl[500005];
pair<LL,LL> edges[500005];

void dfs(LL node,LL prev){
	preorder[node]=nex;nex++;
	for(int x=0;x<adjl[node].size();x++){
		if(adjl[node][x]==prev)continue;
		dfs(adjl[node][x],node);
	}
	subtree[node]=nex-1;
}

struct node{
	node *l,*r;
	LL s,e,lazy=0;
	LL v;//stores the iterator(b4 preorder) of the max_element...
	LL v2=0;//stores number of elements that have sociability>=threshold...
	node(int ss,int ee){
		s=ss;e=ee;
		if(s==e){
			v=s;
			l=r=NULL;
			if(aa[preorder[s]]>=xx){
				v2=1;
				aa[preorder[s]]=-1;
			}
		}else{
			l=new node(s,(s+e)/2);
			r=new node((s+e)/2+1,e);
			if(aa[preorder[l->v]]>aa[preorder[r->v]])v=l->v;
			else v=r->v;
			v2=l->v2+r->v2;
		}
	}
	
	void p_update(int p){//remove the thing from the segment tree...
		if(s==e){
			aa[preorder[v]]=LLONG_MIN;
			v2++;
			lazy=0;
			return;
		}
		if(p<=(s+e)/2){
			l->p_update(p);
		}else r->p_update(p);
		if(aa[preorder[l->v]]+l->lazy>aa[preorder[r->v]]+r->lazy)v=l->v;
		else v=r->v;
		v2=l->v2+r->v2;
	}
	
	void update(LL ll,LL rr, LL c){//increment the range...
		if(v2==(e-s+1))return;//all stuff in range POP liao, no point
		if(ll<=s && e<=rr){
			while(aa[preorder[v]]+c+lazy>=xx){
				//cout<<"p_updated "<<v<<'\n';
				p_update(v);
			}
			if(v==5){
				//cout<<"special "<<aa[preorder[v]]+c+lazy<<'\n';
			}
			lazy+=c;
			return;
		}
		l->lazy+=lazy;r->lazy+=lazy;
		lazy=0;
		if(ll<=(s+e)/2){
			l->update(ll,rr,c);
		}if(rr>(s+e)/2){
			r->update(ll,rr,c);
		}
		
		if(aa[preorder[l->v]]+l->lazy>aa[preorder[r->v]]+r->lazy)v=l->v;
		else v=r->v;
		v2=l->v2+r->v2;
		//cout<<s<<' '<<e<<' '<<v<<' '<<v2<<'\n';
	}
	int query(int ll,int rr){
		if(ll<=s && e<=rr)return v2;
		int ans=0;
		if(ll<=(s+e)/2){
			ans+=l->query(ll,rr);
		}
		if((s+e)/2<rr){
			ans+=r->query(ll,rr);
		}
		return ans;//+lazy;
	}
} *root;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	LL n,q,a,b,c;
	cin>>n>>xx;
	for(int x=1;x<=n;x++){
		cin>>aa[x];//sociability...
	}
	for(int x=1;x<n;x++){
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
		edges[x]=make_pair(a,b);
	}
	dfs(1,-1);
	root=new node(1,nex);
	cin>>q;
	LL t,i=0;
	for(int x=0;x<q;x++){
		cin>>t;
		if(t==1){
			cin>>a>>b;//update subtree of a, increase by b...
			root->update(preorder[a],subtree[a],b);
		}else{
			cin>>a;
			b=root->query(1,nex);
			c=root->query(preorder[a],subtree[a]);
			//cout<<"pre"<<a<<' '<<preorder[a]<<' '<<subtree[a]<<' '<<b<<' '<<c<<'\n';
			b-=c;
			//cout<<'g'<<t<<' '<<b*c<<'\n';
			cout<<b*c<<'\n';
		}
		//cout<<"ok\n";
	}
	return 0;
}