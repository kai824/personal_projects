// ans.cpp 8 Feb 20, 13:21:32 30 0.19 Judging completed in 3.738s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	typedef long long ll;
	ll n,a,cur;
	vector<pair<ll,ll> > v;
	for(int x=0;x<=1e6;x++){
		a=0;
		cur=1;
		for(int i=0;i<7;i++){
			a+=(1ll<<i)*((x/cur)%10);
			cur*=10;
		}
		v.emplace_back(a,x);
	}
	sort(v.begin(),v.end());
	cin>>n;
	for(int x=0;x<n;x++){
		cin>>a;
		cout<<v[a-1].second<<'\n';
	}
	return 0;
}

/*
weneedtopassanewhealthcarebill
5
0 russian
0 as
2 set
0 blue
4 donkey
4
10 12
27 30
1 30
24 26
*/