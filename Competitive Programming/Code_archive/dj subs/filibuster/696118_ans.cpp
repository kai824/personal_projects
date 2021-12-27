// ans.cpp 8 Feb 20, 10:48:41 0 4.03 Judging completed in 9.874s on AWS Oregon.
#include"bits/stdc++.h"
using namespace std;

/*#pragma GCC optimization("O3")
#pragma GCC optimization("avx2")
#pragma GCC optimization("unroll-loops")*/
string s,t;int a,b;
pair<string,int> arr[300005];
bool cmp(pair<string,int>a,pair<string,int>b){
	if(a.first==b.first){
		return a.second>b.second;
	}
	return a.first<b.first;
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin>>s;//full string...
	int n,q,p;
	cin>>n;
	for(int x=1;x<=n;x++){
		cin>>p>>t;//copy speaker p, add t to the end...
		arr[x].first=arr[p].first;
		arr[x].first+=t;
		arr[x].second=x;
	}
	sort(arr+1,arr+n+1,cmp);
	cin>>q;
	for(int x=0;x<q;x++){
		cin>>a>>b;
		a--;
		t=s.substr(a,b-a);
		if(arr[1].first>t){
			cout<<"-1\n";
			return 0;
		}
		cout<<arr[upper_bound(arr+1,arr+n+1,make_pair(t,INT_MAX))-1-arr].second<<'\n';
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