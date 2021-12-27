// ans.cpp 16 Dec 19, 17:19:18 9 0.14 Judging completed in 7.76s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
	pair<int,int> arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x].first>>arr[x].second;//fuse length, entertainment...
	}
	sort(arr,arr+n);
	long long cur_length=0,value=0,maxi=0;//fuse length, entertainment value...
	for(int x=0;x<n;x++){
		value-=(arr[x].first-cur_length)*x;
		cur_length=arr[x].first;
		value+=arr[x].second;
		maxi=max(maxi,value);
	}
	cout<<maxi;
    return 0;
}