// ans.cpp 12 Nov 18, 15:46:02 100 0.2 Judging completed in 2.561s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,ans=INT_MAX;
	cin>>n>>k;
	k=n-k;//number of stuff that can be taken...
	deque<pair<int,int> >dq;//difference, iterator of larger number...
	int arr[n];
	for(int x=0;x<n;x++){
		cin>>arr[x];
	}
	sort(arr,arr+n);
	for(int x=1;x<k-1;x++){
		while(!dq.empty() && dq.back().first>arr[x]-arr[x-1]){
			dq.pop_back();
		}
		dq.push_back(make_pair(arr[x]-arr[x-1],x));
	}
	for(int x=0;x+k<=n;x++){//start at x, end at x+k
		//update range
		while(!dq.empty() && dq.back().first>arr[x+k-1]-arr[x+k-2]){
			dq.pop_back();
		}
		dq.push_back(make_pair(arr[x+k-1]-arr[x+k-2],x+k-1));

		while(dq.size()>0 && dq[0].second<x){
			dq.pop_front();
		}
		ans=min(ans,dq[0].first+arr[x+k-1]-arr[x]);//smallest diff + largest diff
	}
	cout<<ans;
    return 0;
}