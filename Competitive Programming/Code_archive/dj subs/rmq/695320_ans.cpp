// ans.cpp 6 Feb 20, 22:17:38 0 0.12 Judging completed in 5.398s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")

pair<int,int> range[100000];
int arr[100000];//the minimum possible at each part...
int ans[100000];

struct node{//lazy propagation...
	int v=INT_MIN,s,e;
	node *l,*r;
	node(int ss,int ee){
		s=ss;e=ee;
		if(s==e)l=r=NULL;
		else{
			l=new node(ss,(ss+ee)/2);
			r=new node((ss+ee)/2+1,ee);
		}
	}
	void update(int a,int b,int c){//the min from a to b is c...
		if(a<=s && e<=b){
			v=max(v,c);
			return;
		}
		if(a<=(s+e)/2){
			l->update(a,b,c);
		}
		if((s+e)/2<b){
			r->update(a,b,c);
		}
	}
	void get_arr(int cur_max){
		if(s==e){
			arr[s]=max(cur_max,v);
		}else{
			l->get_arr(max(cur_max,v));
			r->get_arr(max(cur_max,v));
		}
	}
} *root;

struct node2{//normal segtree, max query...
	int v,s,e;//v is the iterator to the min element in array[s]
	node2 *l,*r;
	void check(){
		if(arr[l->v]>=arr[r->v])v=l->v;
		else v=r->v;
	}
	node2(int ss,int ee){
		s=ss;e=ee;
		if(s==e){
			v=s;
			l=r=NULL;
		}else{
			l=new node2(ss,(ss+ee)/2);
			r=new node2((ss+ee)/2+1,ee);
			check();
		}
	}
	void update(int p){
		if(s==e){
			return;
		}
		if(p<=(s+e)/2)l->update(p);
		else r->update(p);
		check();
	}
	int query(int a,int b){
		if(a<=s && e<=b){
			return v;
		}
		int ans=-1,tmp;
		if(a<=(s+e)/2){
			ans=l->query(a,b);
		}
		if((s+e)/2<b){
			tmp=r->query(a,b);
			if(ans==-1)ans=tmp;
			else if(arr[ans]<arr[tmp])ans=tmp;
		}
		return ans;
	}
}*root2;

int n,q,tmp,a,b,c;

void oops(){
	for(int i=0;i<n;i++){
		cout<<"-1";
		if(i+1<n)cout<<' ';
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	vector<int> unassigned;
	vector<pair<int,int> >v2;
	cin>>n>>q;//0-indexed...
	for(int x=0;x<n;x++){
		range[x].first=INT_MIN;
		range[x].second=INT_MAX;
		ans[x]=-1;
	}
	root=new node(0,n-1);
	for(int x=0;x<q;x++){
		cin>>a>>b>>c;//min from a to b is c...
		range[c].first=max(range[c].first,a);
		range[c].second=min(range[c].second,b);
		root->update(a,b,c);
	}
	root->get_arr(0);

	root2=new node2(0,n-1);
	for(int x=n-1;x>=0;x--){//do the stuff for x
		if(range[x].first>range[x].second){
			oops();
			return 0;
		}
		if(range[x].first==INT_MIN && range[x].second==INT_MAX){
			unassigned.push_back(x);
			continue;
		}
		tmp=root2->query(max(range[x].first,0),min(range[x].second,n-1));
		while(arr[tmp]>x){
			if(unassigned.size()==0){
				oops();
				return 0;
			}
			arr[tmp]=-1;//give it a value...
			ans[tmp]=unassigned.back();
			unassigned.pop_back();
			root2->update(tmp);
			tmp=root2->query(max(range[x].first,0),min(range[x].second,n-1));
		}
		if(arr[tmp]==-1){//greater than x means yao qiu tai gao || -1 means all taken liao...
			oops();return 0;
		}
		ans[tmp]=x;
		arr[tmp]=-1;
		root2->update(tmp);
	}
	for(int x=0;x<n;x++){
		if(ans[x]==-1){
			v2.emplace_back(arr[x],x);//the minimum it needs, and it...
		}
	}
	sort(v2.begin(),v2.end());
	sort(unassigned.begin(),unassigned.end());
	if(v2.size()!=unassigned.size()){
	    oops();
	    return 0;
	}
	for(int x=0;x<v2.size();x++){
		if(unassigned[x]<v2[x].first){//too small...
			oops();
			return 0;
		}
		ans[v2[x].second]=unassigned[x];
	}
	for(int x=0;x<n;x++){
		cout<<ans[x];
		if(x+1<n)cout<<' ';
		else cout<<'\n';
	}
	return 0;
}

/*
5 3
0 2 1
1 3 0
1 4 0
*/