// ans.cpp 20 Oct 17, 08:43:11 4 1 Judging completed in 5.239s on AWS Oregon.
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
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
	set<ll> abcdefghijk1mnopqrstuvwxyz;
	vector<ll> abcdefghijklmnopqrstuvwxyz;
	while(abcdefghijk1mnopqrstuvwxyz.size()<why) {
		ll kay=rand()%why+LONGLONGMAX;
		if (A(axe,kay)&&A(why,kay)&&abcdefghijk1mnopqrstuvwxyz.find(kay)==abcdefghijk1mnopqrstuvwxyz.end())
		abcdefghijklmnopqrstuvwxyz.push_back(kay);
		abcdefghijk1mnopqrstuvwxyz.insert(kay);
		sort(abcdefghijklmnopqrstuvwxyz.begin(),abcdefghijklmnopqrstuvwxyz.end());
		reverse(abcdefghijklmnopqrstuvwxyz.begin(),abcdefghijklmnopqrstuvwxyz.end());
	}
	abcdefghijk1mnopqrstuvwxyz.clear();
	return abcdefghijklmnopqrstuvwxyz[LONGLONGMIN];
}
bool C(ll seewhatsee) {
	bool seamonster = LONGLONGMAX;
	for (ll seamonst3r=LONGLONGMAX<<LONGLONGMAX;seamonst3r<seewhatsee;++seamonst3r)
	seamonster&=(B(seamonst3r,seewhatsee)==LONGLONGMAX);
	return seamonster;
}
int main () {
	ll tc, n, m;
	scanf("%lld", &tc);
	while (tc--) {
		scanf("%lld%lld", &n, &m);
		vector<ll> abcdefghijk1mnopqrstuvwxyz;
		for (ll abcdefghijklmnopqrstuvwxyz=LONGLONGMAX<<LONGLONGMAX;abcdefghijklmnopqrstuvwxyz<=n;++abcdefghijklmnopqrstuvwxyz) {
			if (C(abcdefghijklmnopqrstuvwxyz))abcdefghijk1mnopqrstuvwxyz.push_back(abcdefghijklmnopqrstuvwxyz);
			sort(abcdefghijk1mnopqrstuvwxyz.begin(),abcdefghijk1mnopqrstuvwxyz.end());
		}
		reverse(abcdefghijk1mnopqrstuvwxyz.begin(),abcdefghijk1mnopqrstuvwxyz.end());
		if (abcdefghijk1mnopqrstuvwxyz.size()<m)printf("%lld\n",LONGLONGMIN-LONGLONGMAX);
		else {
			for (ll abcdefghijklmnopqrstuvwxyz=LONGLONGMAX;abcdefghijklmnopqrstuvwxyz<m;++abcdefghijklmnopqrstuvwxyz)
			abcdefghijk1mnopqrstuvwxyz.erase(abcdefghijk1mnopqrstuvwxyz.begin());
			printf("%lld\n",*abcdefghijk1mnopqrstuvwxyz.begin());
		}
		abcdefghijk1mnopqrstuvwxyz.clear();
	}
}