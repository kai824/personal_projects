// ans.cpp 20 Oct 17, 09:10:09 0 0.01 Judging completed in 5.403s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool A(ll a,ll b) {
	while(a>=b) a-=b;
	return !a;
}
bool cmp(ll a,ll b){
	return(a>b);
}
ll B(ll axe,ll why) {
	ll ans=LLONG_MIN;
	set<ll> v;
	//vector<ll> stuff;
	while(v.size()<why) {
		ll kay=rand()%why+1;
		if (A(axe,kay)&&A(why,kay)&&v.find(kay)==v.end())
		//stuff.push_back(kay);
		ans=max(ans,kay);
		v.insert(kay);
		//sort(stuff.begin(),stuff.end(),cmp);
	}
	return ans;
}
bool C(ll a) {
	bool ans = 1;
	for (ll x=2;x<a;x++){
		ans&=(B(x,a)==1);
		if(ans==0)break;
	}
	return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll tc,n,m;
	vector<ll>v;
	cin>>tc;
	while(tc--){
		v.clear();
		cin>>n>>m;
		for (ll x=2;x<=n;x++) {
			if (C(x))v.push_back(x);
			else break;
		}
		if (v.size()<m)printf("%lld\n",-1);
		else {
			sort(v.begin(),v.end(),cmp);
			printf("%lld\n",v[m-1]);
		}
	}
}