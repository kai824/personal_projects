// ans.cpp 11 Feb 20, 19:20:06 100 0.33 Judging completed in 5.369s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;


typedef long long ll;

pair<ll,ll> arr[300005],seg[300005];
char c;

vector<ll>vv[1000005];

ll ps[300005];
ll parent[300005],siz[300005];
bool active[300005];

inline ll getr(ll x){
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
	seg[a].first=min(seg[a].first,seg[b].first);
	seg[a].second=max(seg[a].second,seg[b].second);
}

inline ll read(){
    ll ans=0;
    while(c=getchar_unlocked()){
        if(c>='0' && c<='9'){
            ans=c-'0';
            break;
        }
    }
    while(c=getchar_unlocked()){
        if(c<'0' || c>'9')break;
        ans*=10;
        ans+=c-'0';
    }
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,m,i,i2,i3,tmp,ans=0;
	n=read();m=read();
	vv[0].push_back(0);
	for(ll x=1;x<=n;x++){
		arr[x].first=read();
		arr[x].second=x;
		ps[x]=(ps[x-1]+(arr[x].first%m))%m;

		parent[x]=-1;
		siz[x]=1;
		vv[ps[x]].push_back(x);
		seg[x].first=seg[x].second=x;
		//ss[x][ps[x]]=1;
		//ss2[x][ps[x-1]]=1;//for sum of elements before...
	}
	sort(arr+1,arr+1+n);
	for(ll x=1;x<=n;x++){
		arr[x].first%=m;
		i=i2=arr[x].second;
		active[i]=true;
		if(i+1<=n && active[i+1]){
			i2=getr(i+1);
			if(true){
				ans+=int(upper_bound(vv[ps[i]].begin(),vv[ps[i]].end(),seg[i2].second)-lower_bound(vv[ps[i]].begin(),vv[ps[i]].end(),seg[i2].first));
			}
			merge(i2,i);
		}
		i2=getr(i);
		if(i-1>=1 && active[i-1]){
			i3=getr(i-1);
			if(siz[i2]<siz[i3]){//iterate through the set at i2...
				for(int it=seg[i2].first;it<=seg[i2].second;it++){
				    tmp=((ps[it]+m-arr[x].first)%m);
					ans+=int(upper_bound(vv[tmp].begin(),vv[tmp].end(),seg[i3].second-1)-lower_bound(vv[tmp].begin(),vv[tmp].end(),seg[i3].first-1));
					//find in ss2
				}
			}else{//iterate through set at i3...
				for(int it=seg[i3].first-1;it<seg[i3].second;it++){
				    tmp=((ps[it]+arr[x].first)%m);
					ans+=int(upper_bound(vv[tmp].begin(),vv[tmp].end(),seg[i2].second)-lower_bound(vv[tmp].begin(),vv[tmp].end(),seg[i2].first));
				}
			}
			merge(i2,i3);
		}
	}
	cout<<ans;
	return 0;
}