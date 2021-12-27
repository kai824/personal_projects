// ans.cpp 8 Feb 20, 13:20:14 0 0.54 Judging completed in 4.334s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/
vector<pair<int,int> > v;

void gen(int n, int k, int b) {
  if (n == -1) v.emplace_back(k,b);
  for (int i=0;i<=9;i++)
  gen(n - 1, k + (1<<n)*i, b * 10 + i);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,a,cur;
	gen(7,0,0);
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