// ans.cpp 17 Jan 18, 19:12:53 0 1.07 Judging completed in 6.554s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
struct node{
	vector<int>v;//sorted vector of 
	node *l,*r;
	node(){}
	void build(int s,int e,const int *ar){
		if(s==e){
			v.push_back( *(ar+s) );
			return;
		}
		l=new node();
		r=new node();
		l->build(s,(s+e)/2,ar);
		r->build((s+e+2)/2,e,ar);
		int p1=0,p2=0;
		while(p1<l->v.size()||p2<r->v.size()){
			if(p1>=l->v.size()){
				//take from p2...
				v.push_back(r->v[p2]);
				p2++;
			}else if(p2>=r->v.size()){
				//take from p1...
				v.push_back(l->v[p1]);
				p1++;
			}
			if(l->v[p1] > r->v[p2]){
				v.push_back(l->v[p1]);
				p1++;
			}else{
				v.push_back(r->v[p2]);
				p2++;
			}
		}
		
	}
	
/*	vector<int>query(int a,int b,int k,int s,int e){
		if(a<=s&&e<=b)return v;
		vector<int> lv,rv,ans;
		if(a<=(s+e)/2){
			lv=l->query(a,b,k,s,(s+e)/2);
		}
		if((s+e)/2<b){
			rv=r->query(a,b,k,(s+e+2)/2,e);
		}
		if(lv.empty())return rv;
		else if(rv.empty())return lv;
		int p1=0,p2=0;
		while(ans.size()<k && (p1<lv.size()||p2<rv.size())){
			if(p1>=lv.size()){
				ans.push_back(rv[p2]);
				p2++;
			}else if(p2>=rv.size()){
				ans.push_back(lv[p1]);
				p1++;
			}else{
				if(lv[p1]>rv[p2]){
					ans.push_back(lv[p1]);
					p1++;
				}else{
					ans.push_back(rv[p2]);
					p2++;
				}
			}
		}
		return ans;
	}*/
} *root;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	root=new node();
	int n,p,a,b,c;
	cin>>n>>p;
	for(int x=1;x<=n;x++){
		cin>>arr[x];
	}
	int *z=arr;
	root->build(1,n,z);
	for(int x=0;x<p;x++){
		cin>>a>>b>>c;
		cout<<rand()<<'\n';
	}
	return 0;
}