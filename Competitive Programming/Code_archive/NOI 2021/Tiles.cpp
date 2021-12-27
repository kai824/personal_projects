//thx for setting cancer segtree problem :)
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1000000007;
int n,q;
struct val{
	int k[8][8];
	int sz=1;
} qa;

string ss;
bool blk[30005][3];

vector<int> subs[8];
void sett(val &a,int it){
	bool b1=false,b2=false;
	if(blk[it][1]==0){
		if(blk[it][0]==0){
			b1=true;
		}
		if(blk[it][2]==0){
			b2=true;
		}
	}
	for(int i=7;i>=0;i--){
		for(int j=7;j>=0;j--){
			a.k[i][j]=1;
			if(b1){
				if((i&3)==3 && (j&3)==3)a.k[i][j]+=1;
			}
			if(b2){
				if((i&6)==6 && (j&6)==6)a.k[i][j]+=1;
			}
		}
	}
	a.sz=1;
}
int inc,cnt;
val merge(val a,val b,int end){
	val ans;
	ans.sz=a.sz+b.sz;
	for(int i=0;i<8;i++)for(int j=0;j<8;j++)ans.k[i][j]=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			for(int x=0;x<8;x++){//mask of which rows to use "linkway"
				if(a.sz==1 && (i&x)!=x)continue;
				if(b.sz==1 && (j&x)!=x)continue;
				
				cnt=0;
				for(int y=0;y<3;y++){
					if(x&(1<<y)){
						cnt++;
						if(blk[end][y] || blk[end+1][y])goto hell;
					}
				}
				if(a.sz==1)i-=x;
				if(b.sz==1)j-=x;
				inc=(a.k[i][7-x]*b.k[7-x][j] )%mod;
				if(a.sz==1)i+=x;
				if(b.sz==1)j+=x;
				
				ans.k[i][j]+=inc;
				ans.k[i][j]%=mod;
				
				hell:;
			}
		}
	}
	
	/*for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)cerr<<ans.k[i][j]<<' ';
			cerr<<'\n';
		}*/
	return ans;
}

struct node{
	int s,e,m;
	val v;
	node *l,*r;
	node(int ss,int ee){
		s=ss;e=ee;m=(s+e)/2;
		if(s==e){
			l=r=NULL;
			sett(v,s);
		}else{
			l=new node(s,m);
			r=new node(m+1,e);
			v=merge(l->v,r->v,m);
		}
		
		/*cerr<<s<<' '<<e<<' '<<v.sz<<'\n';
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++)cerr<<v.k[i][j]<<' ';
			cerr<<'\n';
		}
		cerr<<"\n\n";*/
	}
	void update(int p){
		if(s==e){
			sett(v,s);
			return;
		}
		if(p<=m)l->update(p);
		else r->update(p);
		v=merge(l->v,r->v,m);
	}
	void query(int a,int b){
		if(a<=s && e<=b){
			if(qa.k[0][0]==-1)qa=v;
			else qa=merge(qa,v,s-1);
			return;
		}
		if(a<=m)l->query(a,b);
		if(m<b)r->query(a,b);
	}
} *root;

int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>n>>q;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++)if((i&j)==j)subs[j].push_back(i);
	}
	for(int i=0;i<3;i++){
		cin>>ss;
		for(int j=0;j<n;j++){
			if(ss[j]=='.')blk[j][i]=0;
			else blk[j][i]=1;
		}
	}
	root=new node(0,n-1);
	
	int a,b;
	while(q--){
		cin>>a;
		if(a==1){
			cin>>a>>b;
			a--;b--;
			blk[b][a]^=1;
			root->update(b);
		}else{
			cin>>a>>b;
			a--;b--;
			qa.k[0][0]=-1;
			root->query(a,b);
			cout<<qa.k[7][7]<<'\n';
		}
	}
}
/*
*/
