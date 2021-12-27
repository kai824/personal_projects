// ans.cpp 8 Feb 20, 10:57:15 9 4.03 Judging completed in 10.512s on AWS Oregon.
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
	assert(n>0);
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
		if(n==0){
		    cout<<"-1\n";
		    continue;
		}
		a--;
		t=s.substr(a,b-a);
		p=upper_bound(arr+1,arr+n+1,make_pair(t,INT_MAX))-1-arr;
		if(arr[1].first>t || p<1){
			cout<<"-1\n";
			continue;
		}
		cout<<arr[p].second<<'\n';
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