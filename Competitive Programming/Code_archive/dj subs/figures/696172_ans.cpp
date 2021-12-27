// ans.cpp 8 Feb 20, 11:11:57 10 0.01 Judging completed in 3.9s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,a,cur;
	vector<pair<int,int> > v;
	for(int x=0;x<=8000;x++){
		a=0;
		cur=1;
		for(int i=0;i<4;i++){
			a+=(1<<i)*((x/cur)%10);
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