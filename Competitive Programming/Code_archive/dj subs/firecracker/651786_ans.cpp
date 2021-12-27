// ans.cpp 16 Dec 19, 17:39:37 100 0.2 Judging completed in 6.844s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,cnt=0;
	cin>>n;
	pair<long long,long long> arr[n];
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int x=0;x<n;x++){
		cin>>arr[x].first>>arr[x].second;//fuse length, entertainment...
	}
	sort(arr,arr+n);
	long long cur_length=0,value=0,maxi=0;//fuse length, entertainment value...
	for(int x=0;x<n;x++){
		cur_length=arr[x].first;
		value+=arr[x].second+arr[x].first;
		pq.push(arr[x].second+arr[x].first);
		cnt++;
		while(!pq.empty() && pq.top()<cur_length){
			cnt--;
			value-=pq.top();
			pq.pop();
		}
		maxi=max(maxi,value-cur_length*cnt);
		//cout<<arr[x].first<<' '<<arr[x].second<<'\n';
	}
	cout<<maxi;
    return 0;
}