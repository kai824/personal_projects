// ans.cpp 28 Dec 19, 17:59:46 6 1.46 Judging completed in 7.23s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

//static int SQ=708;
#define SQ 320

int arr[500005];

bool masked[SQ];//lazy update
unordered_map<int,int> mps[SQ];//sqrt decomp

struct node{
	int v=0;//cnt
	int s,e;
	bool masked=0;
	node *l,*r;
	node(int ss,int ee,int t){
		s=ss;e=ee;
		if(ss==ee){
			if(arr[ss]==t)v=1;
			else v=0;
		}else{
			l=new node(s,(s+e)/2,t);
			r=new node((s+e)/2 +1,e,t);
			v=l->v+r->v;
		}
	}
	void update(int b,int c,int x){
		if(b<=s && e<=c){
			v=(e-s)+1;
			v*=x;
			masked=true;
			return;
		}
		if(masked){
			if(v==0){
				l->v=0;r->v=0;
			}else{
				l->v=(s+e)/2-s+1;
				r->v=e-(s+e)/2;
			}
			l->masked=r->masked=true;
			masked=false;
		}
		if(b<=(s+e)/2){
			l->update(b,c,x);
		}
		if(c>(s+e)/2){
			r->update(b,c,x);
		}
		v=l->v+r->v;
	}
	int query(int a,int b){
		if(v==0)return -2;
		if(masked || s==e){
			return s;//the iterator...
		}
		if(a<=(s+e)/2){
			if(l->v>0)return l->query(a,b);
		}
		return r->query(a,b);
	}

} *st[9];

void main2(int n){
	int q,a,b,c,d;
	for(int x=1;x<=8;x++){
		st[x]=new node(0,n-1,x);
	}
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b>>c>>d;
		b--;c--;
		if(a==2){//update...
			for(int x=1;x<=8;x++){
				if(d==x)st[x]->update(b,c,1);
				else st[x]->update(b,c,0);
			}
		}else{
			cout<<st[d]->query(b,c)+1<<'\n';
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	if(n>5000){
		main2(n);
		return 0;
	}
	int q,a,b,c,d,ans;
	for(int x=n-1;x>=0;x--){
		mps[x/SQ][arr[x]]=x;
	}
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b>>c>>d;
		b--;c--;
		if(a==1){//query...
			ans=INT_MAX;
			for(int i=b;i<=c;i++){
				if(i%SQ == 0 && i+SQ-1<=c){//at the start of a bucket...
					if(mps[i/SQ].find(d)!=mps[i/SQ].end()){
						ans=mps[i/SQ][d];
						break;
					}
					i+=SQ-1;//let the for loop do the extra one...
					continue;
				}
				if(arr[i]==d){
					ans=i;break;
				}
			}
			if(ans==INT_MAX)cout<<"-1\n";
			else cout<<ans+1<<'\n';
		}else{
			for(int i=b;i<=c;i++){
				if(i%SQ == 0 && i+SQ-1<=c){
					masked[i/SQ]=true;
					mps[i/SQ].clear();
					mps[i/SQ][d]=i-(i%SQ);
					continue;
				}
				if(masked[i/SQ]==true){
					for(int j=SQ*(i/SQ);j<SQ*(1+i/SQ);j++){
						arr[j]=mps[i/SQ].begin()->first;
					}
					masked[i/SQ]=false;
				}
				arr[i]=d;
			}
			if(b%SQ == 0 && b+SQ-1<=c){//starts at start of bucket...
			}else{
				mps[b/SQ].clear();
				for(int j=SQ*(1+b/SQ)-1;j>=SQ*(b/SQ);j--){
					mps[b/SQ][arr[j]]=j;
				}
			}
			if(masked[c/SQ]==false){
				mps[c/SQ].clear();
				for(int j=SQ*(1+c/SQ)-1;j>=SQ*(c/SQ);j--){
					if(arr[j]==0)continue;//cost shouldn't be 0
					mps[c/SQ][arr[j]]=j;
				}
			}
		}
	}
	return 0;
}
/*
5
1 1
1 2
1 3
2 4
2 5
*/