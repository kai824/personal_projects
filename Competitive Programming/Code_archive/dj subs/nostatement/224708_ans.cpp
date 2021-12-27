// ans.cpp 20 Oct 17, 09:14:50 4 1 Judging completed in 6.436s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#define LONGLONGMAX 1LL
#define LONGLONGMIN 0LL
typedef long long ll;
bool A(ll numberone,ll numbertwo) {
	while(numberone-numbertwo>=LONGLONGMIN) 
	for(ll numberthree=numbertwo;numberthree--;--numberone);
	return !numberone;
}
ll B(ll axe,ll why) {
	set<ll> s;
	vector<ll> v;
	while(s.size()<why) {
		ll kay=rand()%why+LONGLONGMAX;
		if (A(axe,kay)&&A(why,kay)&&s.find(kay)==s.end())
		v.push_back(kay);
		s.insert(kay);
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	return v[LONGLONGMIN];
}
bool C(ll seewhatsee) {
	bool seamonster = LONGLONGMAX;
	for (ll seamonst3r=LONGLONGMAX<<LONGLONGMAX;seamonst3r<seewhatsee;++seamonst3r)
	seamonster&=(B(seamonst3r,seewhatsee)==LONGLONGMAX);
	return seamonster;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll tc, n, m;
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		vector<ll> s;
		for (ll v=LONGLONGMAX<<LONGLONGMAX;v<=n;++v) {
			if (C(v))s.push_back(v);
		}
		sort(s.begin(),s.end());
		reverse(s.begin(),s.end());
		if (s.size()<m)printf("%lld\n",LONGLONGMIN-LONGLONGMAX);
		else {
			for (ll v=LONGLONGMAX;v<m;++v)
			s.erase(s.begin());
			printf("%lld\n",*s.begin());
		}
		s.clear();
	}
}