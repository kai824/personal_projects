#include<bits/stdc++.h>
using namespace std;

#define lnt long long
const lnt inf=1e17;
typedef pair<lnt,lnt> pii;
#define f first
#define s second
#define mp make_pair
#define eb emplace_back

int par[205];//ST1...
int sz[205];

int getr(int x){
	if(par[x]==-1)return x;
	return par[x]=getr(par[x]);
}

void merge(int a,int b){
	a=getr(a);b=getr(b);
	if(a==b)return;
	par[a]=b;
	sz[b]+=sz[a];
}

vector<int> find_reachable(vector<int> r, vector<int> u, vector<int> v, vector<int> c) {
	int n=r.size();
	int m=u.size();
	for(int i=0;i<n;i++)par[i]=-1,sz[i]=1;
	for(int i=0;i<m;i++){
		merge(u[i],v[i]);
	}

	vector<int> ans;
	ans.resize(n);

	int mn=n;

	for(int i=0;i<n;i++){
		if(r[i]==0){
			ans[i]=sz[getr(i)];
		}else ans[i]=1;
		mn=min(mn,ans[i]);
	}
	for(int i=0;i<n;i++){
		ans[i]=(mn==ans[i]);
	}
	return ans;
}
