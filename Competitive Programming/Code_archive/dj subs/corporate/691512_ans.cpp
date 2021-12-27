// ans.cpp 1 Feb 20, 10:08:56 0 1.11 Judging completed in 6.056s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll,ll> arr[300005];

map<ll,ll>ss[300005],ss2[300005];

ll ps[300005];
ll parent[300005],siz[300005];
bool active[300005];

ll getr(ll x){
	if(parent[x]==-1)return x;
	return getr(parent[x]);
}

inline void merge(ll a,ll b){
	a=getr(a);
	b=getr(b);
	if(a==b)return;
	if(siz[a]<siz[b])swap(a,b);//make sure a has a larger subtree
	parent[b]=a;
	siz[a]+=siz[b];
	//do the set merging stuff...
	for(map<ll,ll>::iterator it=ss[b].begin();it!=ss[b].end();it++){
		if(ss[a].find(it->first)==ss[a].end()){
			ss[a][it->first]=it->second;
		}else ss[a][it->first]+=it->second;
	}
	ss[b].clear();
	
	for(map<ll,ll>::iterator it=ss2[b].begin();it!=ss2[b].end();it++){
		if(ss2[a].find(it->first)==ss2[a].end()){
			ss2[a][it->first]=it->second;
		}else ss2[a][it->first]+=it->second;
	}
	ss2[b].clear();
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,i,i2,i3,ans=0;
	cin>>n>>m;
	for(ll x=1;x<=n;x++){
		cin>>arr[x].first;
		arr[x].second=x;
		ps[x]=(ps[x-1]+arr[x].first)%m;
		
		parent[x]=-1;
		siz[x]=1;
		ss[x][ps[x]]=1;
		ss2[x][ps[x-1]]=1;//for sum of elements before...
	}
	sort(arr+1,arr+1+n);
	for(ll x=1;x<=n;x++){
		
		/*for(i=1;i<=5;i++){
			cout<<"\n\n";
			for(map<ll,ll>::iterator it=ss[i].begin();it!=ss[i].end();it++){
				cout<<it->first<<' '<<it->second<<'\n';
			}cout<<'\n';
		}*/
		
		i=i2=arr[x].second;
		active[i]=true;
		if(i+1<=n && active[i+1]){
			i2=getr(i+1);
			if(ss[i2].find(ps[i])!=ss[i2].end() ){
				ans+=ss[i2][ps[i]];
			}
			merge(i2,i);
		}
		i2=getr(i);
		if(i-1>=1 && active[i-1]){
			i3=getr(i-1);
			if(siz[i2]<siz[i3]){//iterate through the set at i2...
				for(map<ll,ll>::iterator it=ss[i2].begin();it!=ss[i2].end();it++){
					if(ss2[i3].find((it->first+m-arr[x].first)%m)!=ss2[i3].end()){
						ans+=it->second*ss2[i3][(it->first+m-arr[x].first)%m];
					}
				}
			}else{//iterate through set at i3...
				for(map<ll,ll>::iterator it=ss2[i3].begin();it!=ss2[i3].end();it++){
					if(ss[i2].find((it->first+arr[x].first)%m)!=ss[i2].end()){
						ans+=it->second*ss2[i3][(it->first+m-arr[x].first)%m];
					}
				}
			}
			merge(i2,i3);
		}
	}
	cout<<ans;
	return 0;
}