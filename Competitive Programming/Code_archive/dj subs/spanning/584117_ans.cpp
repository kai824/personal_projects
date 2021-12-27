// ans.cpp 7 Nov 19, 16:49:04 100 0.27 Judging completed in 4.255s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[1000005],it=1,n;
pair<int,int> arr2[1000005];
int taken[1000005],sum=0;

bool valid(int a){
	sum=0;
	for(int x=0;x<a;x++){
		if(taken[arr[x]]==0){
			sum++;
		}
		taken[arr[x]]++;
	}
	if(sum==it){
		for(int x=0;x<a;x++){taken[arr[x]]--;}
		return true;
	}
	for(int x=a;x<n;x++){
		if(taken[arr[x]]==0)sum++;
		taken[arr[x]]++;
		taken[arr[x-a]]--;
		if(taken[arr[x-a]]==0)sum--;
		if(sum==it){
			for(int y=x-a+1;y<=x;y++){
				taken[arr[y]]--;
			}
			return true;
		}
	}

	for(int x=n-a;x<n;x++){
		taken[arr[x]]--;
	}
	return false;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int lo,hi,mid;
    cin>>n;
    for(int x=0;x<n;x++){
		cin>>arr[x];
		arr2[x].first=arr[x];
		arr2[x].second=x;
	}
    sort(arr2,arr2+n);
	for(int x=0;x<n;x++){
		if(x!=0 && arr2[x].first!=arr2[x-1].first)it++;
		arr[arr2[x].second]=it;//reducing array, discretisation
	}
	lo=it;hi=n;
	while(lo<hi){
		mid=lo+((hi-lo)/2);
		if(valid(mid)){
			hi=mid;
		}else{
			lo=mid+1;
		}
	}
    cout<<lo;
    return 0;
}

/*
10
1 2 3 3 2 3 4 1 2 2
*/