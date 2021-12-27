// ans.cpp 6 Jan 18, 22:16:53 0 0 Judging completed in 2.829s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	ll tc, n, m,maxn=-1,maxm=-1;
	vector<ll>s;
	cin>>tc;
	cout<<tc<<' ';
	while(tc--){
		cin>>n>>m;
		maxn=max(maxn,n);
		maxm=max(maxm,m);
	}
	cout<<maxn<<' '<<maxm;
}