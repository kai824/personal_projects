// ans.cpp 20 Oct 17, 09:59:56 0 1 Judging completed in 7.38s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(ll a,ll b){
    return(a>b);
}
bool A(ll a1,ll a2) {
	return (a1==a2);
}
ll B(ll axe,ll why) {
    ll ans=LLONG_MIN;
	set<ll> s;
	while(s.size()<why) {
		ll kay=rand()%why+1;
		if (axe==kay&&why==kay&&s.find(kay)==s.end())
		ans=max(ans,kay);
		s.insert(kay);
	}
	return ans;
}
bool C(ll sws) {
	bool sm = 1;
	for (ll sm3=2;sm3<sws;++sm3){
	    sm&=B(sm3,sws);
	    if(sm==false)break;
	}
	return sm;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll tc, n, m,prev;
	vector<ll> s;
	cin>>tc;
	while (tc--) {
	    s.clear();
		cin>>n>>m;
		for (ll v=2;v<=n;++v) {
			if (C(v))s.push_back(v);
		}
		if (s.size()<m)printf("%lld\n",-1);
		else {
			sort(s.begin(),s.end(),cmp);
			swap(s[0],s[m-1]);
			printf("%lld\n",*s.begin());
		}
	}
}