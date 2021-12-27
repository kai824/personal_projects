// ans.cpp 20 Oct 17, 09:17:53 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool A(ll a1,ll a2) {
	while(a1-a2>=0) 
	for(ll a3=a2;a3--;--a1);
	return !a1;
}
ll B(ll axe,ll why) {
	set<ll> s;
	vector<ll> v;
	while(s.size()<why) {
		ll kay=rand()%why+1;
		if (A(axe,kay)&&A(why,kay)&&s.find(kay)==s.end())
		v.push_back(kay);
		s.insert(kay);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	return v[0];
}
bool C(ll sws) {
	bool sm = 1;
	for (ll sm3=1<<1;sm3<sws;++sm3)sm&=(B(sm3,sws)==1);
	return sm;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll tc, n, m;
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		vector<ll> s;
		for (ll v=1<<1;v<=n;++v) {
			if (C(v))s.push_back(v);
		}
		if (s.size()<m)printf("%lld\n",0-1);
		else {
			sort(s.begin(),s.end());
			reverse(s.begin(),s.end());
			printf("%lld\n",*s[m-1]);
		}
		s.clear();
	}
}