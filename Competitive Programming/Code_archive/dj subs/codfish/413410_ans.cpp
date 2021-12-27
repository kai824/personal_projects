// ans.cpp 14 Nov 18, 14:30:24 100 0.44 Judging completed in 3.033s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> ft;
ll maxi;
ll ls(ll x){
	return x&(-x);
}
void update(ll x){
	if(x<=0)cout<<x;
	//x+=200000ll*2147483648ll;
	for(;x<=maxi;x+=ls(x)){
		if(ft.find(x)==ft.end()){//does not exist yet
			ft[x]=1;
		}else{
			ft[x]++;
		}
	}
}
ll query(ll x){
	if(x<=0)cout<<x;
	//x+=200000ll*2147483648ll;
	ll ans=0;
	for(;x;x-=ls(x)){
		ans+=ft[x];
	}
	return ans;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,k,a,ans=0,cur_it=2;
    cin>>n>>k;
    pair<ll,ll> ps[n+1];
	vector<pair<ll,ll> > values;
	unordered_map<ll,ll> actual;//maps the actual values to reduced values
    ps[0].first=0;
	values.push_back(make_pair(0,0));
    for(ll x=1;x<=n;x++){
        cin>>a;
        ps[x].first=ps[x-1].first+a;
		//cout<<ps[x]<<' ';
		values.push_back(make_pair(ps[x].first,x));
		values.push_back(make_pair(ps[x].first-k,-1));
    }
	sort(values.begin(),values.end());
	actual[values[0].first]=1;
	for(int x=1;x<values.size();x++){
		if(values[x].first==values[x-1].first){
			continue;
		}
		actual[values[x].first]=cur_it;
		cur_it++;
	}
	maxi=cur_it+10;
	update(actual[0]);
    for(ll x=1;x<=n;x++){
		//cout<<"luol\n";
		ans+=query(actual[ps[x].first-k]);
		update(actual[ps[x].first]);
		//cout<<ans<<' ';
    }
    cout<<ans;
    return 0;
}