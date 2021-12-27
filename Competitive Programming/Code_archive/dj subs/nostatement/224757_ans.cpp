// ans.cpp 20 Oct 17, 10:51:03 50 1.03 Judging completed in 5.616s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	ll tc, n, m,u;
	vector<ll>s;
	cin>>tc;
	while (tc--) {
	    s.clear();
		cin>>n>>m;
		char sieve[n+1];
		for (ll v=0;v<=n;++v) {
			sieve[v]='x';
		}
		for(ll x=2;x<=n;x++){
		    if(sieve[x]=='x'){
		        s.push_back(x);
		        u=x*2;
		        while(u<=n){
		            sieve[u]='n';
		            u+=x;
		        }
		    }
		}
		if (s.size()<m)printf("-1\n");
		else {
			reverse(s.begin(),s.end());
			swap(s[0],s[m-1]);
			printf("%lld\n",*s.begin());
		}
	}
}