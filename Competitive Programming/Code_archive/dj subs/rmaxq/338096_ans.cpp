// ans.cpp 14 Mar 18, 22:25:11 57 0.29 Judging completed in 5.41s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
#define ONE INT_MIN

struct node{
	int v=0,lazy=0;
	node *l=NULL,*r=NULL;
	node(){}
	int query(int s,int e,int a,int b){
		if(a<=s && e<=b)return v;
		int lv=ONE,rv=ONE;
		if(a<=((s+e)/2)){//left child involved
			if(l==NULL){
				lv=lazy;
			}else{
				lv=l->query(s,(s+e)/2,a,b)+lazy;
			}
		}
		if((s+e)/2<b){
			if(r==NULL){
				rv=lazy;
			}else{
				rv=r->query((s+e)/2 + 1,e,a,b)+lazy;
			}
		}
		return max(lv,rv);
	}
	void update(int s,int e,int a,int b,int add){
		if(a<=s && e<=b){
			lazy+=add;
			v+=add;
			return;
		}
		if(a<=((s+e)/2)){//left child involved
			if(l==NULL){
				l=new node();
			}
			l->update(s,(s+e)/2,a,b,add);
		}
		if((s+e)/2<b){
			if(r==NULL){
				r=new node();
			}
			r->update((s+e)/2 + 1,e,a,b,add);
		}
		v=ONE;
		if(l!=NULL)v=max(v,l->v);
		if(r!=NULL)v=max(v,r->v);
	}
} *root;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	root=new node();
	int n,a,b,c,q;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>a;
		root->update(0,n,x,x,a);
	}
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a;
		if(a==0){
			cin>>b>>c;
			cout<<root->query(0,n,b,c)<<'\n';
		}else{
			cin>>a>>b>>c;
			root->update(0,n,a,b,c);
		}
	}
	return 0;
}