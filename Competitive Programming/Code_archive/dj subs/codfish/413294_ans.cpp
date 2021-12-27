// ans.cpp 14 Nov 18, 14:03:00 30 0.89 Judging completed in 3.769s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> ft;
ll ls(ll x){
	return x&(-x);
}
void update(ll x){
	x+=200000ll*2147483648ll;
	for(;x<=420000ll*2147483648ll;x+=ls(x)){
		if(ft.find(x)==ft.end()){//does not exist yet
			ft[x]=1;
		}else{
			ft[x]++;
		}
	}
}
ll query(ll x){
	x+=200000ll*2147483648ll;;
	ll ans=0;
	for(;x;x-=ls(x)){
		ans+=ft[x];
	}
	return ans;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,k,a,ans=0;
    cin>>n>>k;
    ll ps[n+1];
    ps[0]=0;
    for(ll x=1;x<=n;x++){
        cin>>a;
        ps[x]=ps[x-1]+a;
		//cout<<ps[x]<<' ';
    }//cout<<'\n';
	update(0);
    for(ll x=1;x<=n;x++){
		//cout<<"luol\n";
		ans+=query(ps[x]-k);
		update(ps[x]);
		//cout<<ans<<' ';
    }
    cout<<ans;
    return 0;
}