// ans.cpp 5 Aug 19, 21:55:51 100 1 Judging completed in 5.225s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q,b,c1,c2;
ll full;
unsigned long long cnt=0;
bool used[25]={false};

vector<ll> invalid[25];

inline void output(ll a){
	ll p=(1LL<<40);
	while(p){
		cout<<((p&a)!=0);
		p>>=1;
	}cout<<'\n';
}

void backtrack(int depth,ll rw, ll ld, ll rd){//depth, row, diagonals
	if(depth>n){
	    //if(rw!=full)return;
		cnt++;
		return;
	}
	if(used[depth]){
		backtrack(depth+1,rw,ld<<1,rd>>1);
		return;
	}
	ll pos = full & (~(rw|ld|rd));
	for(int it=0;it<invalid[depth].size();it++){
		pos&=(~(invalid[depth][it]));//make sure they're not explored
	}
	ll p;
	while(pos){
		p = pos & -pos;//least significant bit
		pos-=p;
		backtrack(depth+1,rw|p,(ld|p)<<1,(rd|p)>>1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll precomp[25]={0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184,14772512,95815104,666090624,4968057848,39029188884,314666222712};
	cin>>n>>q;
	full=( (1LL<<(n+20) ) -1 ) - ((1LL<<20)-1);//leave 20 blanks...
	ll s_ld=0,s_rd=0,s_rw=0;//starting stuff
	for(int x=0;x<q;x++){
		cin>>c1>>c2;c2--;
		if(used[c1] || max(s_rw&(1LL<<(20+c2)),max(s_ld&(1LL<<(20+c2-(c1-1))),s_rd&(1LL<<(20+c2+(c1-1)))))!=0){
			cout<<0;return 0;
		}
		s_rw|=(1LL<<(20+c2));
		s_ld|=(1LL<<(20+c2-(c1-1)));
		s_rd|=(1LL<<(20+c2+(c1-1)));
		used[c1]=true;
	}cin>>b;
	for(int x=0;x<b;x++){
		cin>>c1>>c2;
		invalid[c1].push_back((1LL<<(20+c2-1)));
	}
	if(q==0 && b==0){
		cout<<precomp[n]<<'\n';
		return 0;
	}
	//clock_t begin=clock();
	backtrack(1,s_rw,s_ld,s_rd);
	cout<<cnt;//<<(char)32<<(double)(clock()-begin)/CLOCKS_PER_SEC;
	cout<<'\n';
	return 0;
}