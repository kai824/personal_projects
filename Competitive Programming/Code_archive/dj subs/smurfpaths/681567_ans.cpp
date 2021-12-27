// ans.cpp 18 Jan 20, 15:48:34 0 0 Compilation failed on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL xx;
//xx is the threshold...

LL aa[600005],nex=1;
LL preorder[600005],subtree[600005];
vector<LL> adjl[600005];
pair<LL,LL> edges[600005];

void dfs(LL node,LL prev){
	preorder[node]=nex;nex++;
	for(LL x=0;x<adjl[node].size();x++){
		if(adjl[node][x]==prev)continue;
		dfs(adjl[node][x],node);
	}
	subtree[node]=nex-1;
}

struct node{
	node *l,*r;
	LL s,e,lazy=0;
	LL v;//stores the iterator(b4 preorder) of the max_element...
	LL val=0;//stores the actual value v refers to...
	LL v2=0;//stores number of elements that have sociability>=threshold...
	node(LL ss,LL ee){
		s=ss;e=ee;
		if(s==e){
			v=s;
			l=r=NULL;
			if(aa[preorder[s]]>=xx){
				v2=1;
				val=aa[preorder[s]]=LLONG_MIN;
			}else val=aa[preorder[s]];
		}else{
			l=new node(s,(s+e)/2);
			r=new node((s+e)/2+1,e);
			if(aa[preorder[l->v]]>aa[preorder[r->v]])v=l->v;
			else v=r->v;
			v2=l->v2+r->v2;
			val=max(l->val,r->val);
		}
	}
	
	void p_update(LL p){//remove the thing from the segment tree...
		if(s==e){
			aa[preorder[p]]=val=LLONG_MIN;
			v2=1;
			lazy=0;
			return;
		}
		if(p<=(s+e)/2){
			l->p_update(p);
		}else r->p_update(p);
		if(l->val > r->val)v=l->v;
		else v=r->v;
		v2=l->v2+r->v2;
		
		val=max(l->val,r->val);
		if(val!=LLONG_MIN)val+=lazy;
	}
	
	void update(LL ll,LL rr, LL c){//increment the range...
	    if(v2==e-s+1)continue;//all POP liao
		if(ll<=s && e<=rr){
			while(val+c>=xx ){
				//cout<<"p_updated "<<v<<'\n';
				p_update(v);
			}
			if(val==LLONG_MIN)return;
			lazy+=c;
			val+=c;
			return;
		}
		l->lazy+=lazy;r->lazy+=lazy;
		if(l->val!=LLONG_MIN)l->val+=lazy;
		if(r->val!=LLONG_MIN)r->val+=lazy;
		lazy=0;
		if(ll<=(s+e)/2){
			l->update(ll,rr,c);
		}
		if(rr>(s+e)/2){
			r->update(ll,rr,c);
		}
		
		if(l->val > r->val)v=l->v;
		else v=r->v;
		v2=l->v2+r->v2;
		
		val=max(l->val,r->val)+lazy;
		//cout<<s<<' '<<e<<' '<<v<<' '<<v2<<'\n';
	}
	LL query(LL ll,LL rr){
		if(ll<=s && e<=rr)return v2;
		LL ans=0;
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
	for(LL x=1;x<=n;x++){
		cin>>aa[x];//sociability...
	}
	for(LL x=1;x<n;x++){
		cin>>a>>b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
		edges[x]=make_pair(a,b);
	}
	dfs(1,-1);
	root=new node(1,nex);
	cin>>q;
	LL t,i=0;
	for(LL x=0;x<q;x++){
		cin>>t;
		if(t==1){
			cin>>a>>b;//update subtree of a, increase by b...
			root->update(preorder[a],subtree[a],b);
		}else{
			cin>>a;
			b=root->v2;
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