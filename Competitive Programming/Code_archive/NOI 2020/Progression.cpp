#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define mp make_pair

struct grp{
	pair<int,int> left,right;
	int ans,ss;
	
	void output(){
		cerr<<"Currently at "<<ss<<' '<<ans<<'\t'<<left.first<<' '<<left.second<<'\t'<<right.first<<' '<<right.second<<'\n';
	}
};

int diff[300005];

grp cur,l2;
void gett(grp r){//combine r into l to get the right, left, ans...
	if(cur.ans==-1){
		cur=r;return;
	}
	l2=cur;
	cur.ans=max(cur.ans,r.ans);
	if(l2.right.first==r.left.first){
		cur.ans=max(l2.right.second+r.left.second,cur.ans);
	}
	
	if(l2.left.second==l2.ss && l2.left.first==r.left.first){
		l2.left.second+=r.left.second;//whoa
	}
	if(r.right.second==r.ss && r.right.first==l2.right.first){
		r.right.second+=l2.right.second;//whoa
	}
	cur.left=l2.left;cur.right=r.right;
	cur.ss=l2.ss+r.ss;
}

struct node{//ST[i]=diff[i]=A[i]-A[i-1], where i is 1-indexed and A[0]=0;
	int s,e;
	node *l,*r;
	
	//lazy stuff...
	int lazy=0,lset=1e9;//lazy is for "add"
	//legit values, which should include lazy updates alr...
	int sum=0,ans=1;//where maxi is the longest answer inside
	pii left,right;//number, cnt
	void merge(){//update my own values based on children
		//set=1e9;lazy=0;
		sum=l->sum+r->sum;
		ans=max(l->ans,r->ans);
		if(l->right.first==r->left.first){
			ans=max(l->right.second+r->left.second,ans);//"combining"
		}
		left=l->left;
		right=r->right;
		if(l->left.second==l->e - l->s +1 && l->left.first==r->left.first){
			left.second+=r->left.second;//whoa
		}
		if(r->right.second==r->e - r->s +1 && r->right.first==l->right.first){
			right.second+=l->right.second;//whoa
		}
	}
	
	node(int ss,int ee){
		s=ss;e=ee;
		if(s==e){
			l=r=NULL;
			ans=1;sum=diff[s];
			left=mp(diff[s],1);
			right=mp(diff[s],1);
		}else{
			l=new node(s,(s+e)/2);
			r=new node((s+e)/2+1,e);
			merge();
		}
	}
	void propagate(){//pass down lazy stuff
		if(lset!=1e9){//happens before lazy updates...
			l->sett(l->s,l->e,lset);
			r->sett(r->s,r->e,lset);
			lset=1e9;
		}
		//lazy...
		l->update(l->s,l->e,lazy);
		r->update(r->s,r->e,lazy);
		lazy=0;
	}
	void update(int a,int b,int c){//+c
		if(a<=s && e<=b){//sum, ans, left, right, lazy, lset
			sum+=c*(e-s+1);//LOL...
			left.first+=c;right.first+=c;
			lazy+=c;
			return;
		}
		propagate();
		if(a<=(s+e)/2){
			l->update(a,b,c);
		}
		if((s+e)/2<b){
			r->update(a,b,c);
		}
		merge();
	}
	void sett(int a,int b,int c){
		if(a<=s && e<=b){
			ans=e-s+1;
			sum=c*(e-s+1);
			lset=c;
			left=right=mp(c,e-s+1);
			lazy=0;
			return;
		}
		propagate();
		if(a<=(s+e)/2){
			l->sett(a,b,c);
		}
		if((s+e)/2<b){
			r->sett(a,b,c);
		}
		merge();
	}
	
	
	void query(int a,int b){
		if(a<=s && e<=b){
			//cerr<<s<<' '<<e<<' '<<ans<<'\t'<<left.first<<' '<<left.second<<'\t'<<right.first<<' '<<right.second<<'\n';
			grp tmp;
			tmp.left=left;tmp.right=right;
			tmp.ss=(e-s+1);tmp.ans=ans;
			gett(tmp);
			//cur.output();
			return;
		}
		propagate();
		if(a<=(s+e)/2){
			l->query(a,b);
		}
		if((s+e)/2<b){
			r->query(a,b);
		}
	}
	int get_sum(int x){//sum up to ST[x]
		if(x==e){
			return sum;
		}
		propagate();
		if(x<=(s+e)/2){
			return l->get_sum(x);
		}
		return l->sum + r->get_sum(x);
	}
} *root;

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,q,d,prev=0,a,b;
	cin>>n>>q;
	for(int x=1;x<=n;x++){
		cin>>d;//use this to find difference...
		diff[x]=d-prev;
		prev=d;
	}
	root=new node(0,n);
	int t,l,r,s,c;
	while(q--){
		cin>>t;
		if(t==1){//patch, basically add stuff to [l,r]
			cin>>l>>r>>s>>c;
			root->update(l,l,s);//diff[l]+=s...
			if(l<r)root->update(l+1,r,c);//add stuff
			if(r<n)root->update(r+1,r+1,-((r-l)*c +s) );//diff[r]-=s+(r-l)*c
		}else if(t==2){//rewrite, setting [l,r] to S+(i-L)*c, so diff[l+r...r]==c. etc...
			cin>>l>>r>>s>>c;
			a=root->get_sum(l);//get A[l]
			b=root->get_sum(r);//get A[r]
			//cerr<<a<<' '<<b<<'\n';
			root->update(l,l,s-a);//A[l]=s, so A[l]+=s-A[l]
			if(l<r)root->sett(l+1,r,c);
			if(r<n)root->update(r+1,r+1,-(s+(r-l)*c - b) );//A[r]=s+(r-l)*c, so A[r]+=s+(r-l)*c - b
		}else{//query
			cin>>l>>r;
			if(l==r){
				cout<<"1\n";continue;
			}
			cur.ans=-1;
			root->query(l+1,r);
			cout<<cur.ans+1<<'\n';
		}
		/*for(int x=0;x<=n;x++){
			cout<<root->get_sum(x)<<' ';
		}cout<<'\n';*/
	}
	return 0;
}

/*
10 6
1 2 3 4 1 2 3 4 5 5
3 1 10
1 1 4 -1 -1
3 1 10
3 9 10
2 5 10 -2 -2
3 1 10

`
*/
