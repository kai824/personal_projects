// ans.cpp 7 Mar 20, 12:39:55 7 0.69 Judging completed in 4.284s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;

#define mp make_pair
typedef pair<int,int> pii;
#define int long long

int n,k,a,ans;
vector<int> h;

struct node{//range min, returns the iterator
	int s,e,v;
	node *l,*r;
	node(int ss,int ee){
		s=ss;e=ee;
		if(s==e){
			l=r=NULL;
			if((s!=0 && h[s]<h[s-1]) && (s!=n-1 && h[s]<h[s+1]))v=s;//valley...
			else v=n;
		}else{
			l=new node(s,(s+e)/2);
			r=new node((s+e)/2+1,e);
			refresh();
		}
	}
	void refresh(){
		if(h[l->v]<h[r->v])v=l->v;
		else v=r->v;
	}
	/*void update(int p,int nv){
		if(s==e){
			v=nv;
		}
		if(p<=(s+e)/2)l->update(p,nv);
		else r->update(p,nv);
		refresh();
	}*/
	int query(int ll,int rr){
		if(ll<=s && e<=rr)return v;
		int ans=INT_MAX;
		if(ll<=(s+e)/2){
			ans=min(ans,l->query(ll,rr));
		}
		if((s+e)/2<rr){
			ans=min(ans,r->query(ll,rr));
		}
		return ans;
	}
} *root;

int recurse(int l,int r,int cur_height=0){//from left to right, inclusive...
	//returns the min cost...
	int mid=root->query(l,r),a1,a2;
	if(mid==n){//just upslope, then downslope...
		a=0;
		for(int x=l;x<=r;x++){
			a=max(h[x],a);
		}
		return a-cur_height;
	}
	a1=recurse(l,mid-1,h[mid]);a2=recurse(mid+1,r,h[mid]);
	return h[mid]-cur_height+a1+a2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
		cin>>n>>k;
		for(int x=0;x<n;x++){
			cin>>a;
			if(h.size()==0 || h.back()!=a){
				h.push_back(a);
			}
		}
		n=h.size();
		h.push_back(INT_MAX);
		root=new node(0,n-1);
		ans=recurse(0,n-1);

		for(int x=0;x<n;x++){
			if(h[x]>0)h[x]=k-h[x];
		}
		root=new node(0,n-1);
		ans=min(ans,recurse(0,n-1) );

		cout<<ans<<'\n';
    return 0;
}