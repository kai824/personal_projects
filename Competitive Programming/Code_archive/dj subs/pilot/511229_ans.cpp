// ans.cpp 30 Mar 19, 22:16:40 89 1.06 Judging completed in 5.095s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*int ft[1000005];
inline int ls(int x){
	return x & (-x);
}
inline int query(int p){
	int sum=0;
	for(;p;p-=ls(p))sum+=ft[p];
	return sum;
}
*/
ll dp[1000005];//dp i stores answer if it can contain all the stuff from the back to the ith height
bool cmp(pair<int,int> a,pair<int,int> b){
	return (a.first>b.first);
}
int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,q,lo,hi,mid,ans,s,e,l,a;
	cin>>n>>q;
	pair<int,int> arr[n];//height, iterator
	for(int x=0;x<n;x++){
		cin>>arr[x].first;arr[x].second=x;
	}
	sort(arr,arr+n,cmp);//descending order
	ans=(n*(n-1))/2 + n;
	set<int> ss;//stores iterators
	for(int x=0;x<n;x++){
		dp[x]=ans;
		ss.insert(arr[x].second);
		set<int>::iterator it=ss.find(arr[x].second),it2=it;
		if(it==ss.begin())s=-1;
		else{
			it2--;
			s=*it2;
		}
		it2=it;
		it2++;
		if(it2==ss.end())e=n;
		else{
			it2=it;
			it2++;
			e=*it2;
		}
		l=(e-s-1);
		ans-=(l*(l-1))/2 + l;
		l=arr[x].second-s-1;
		ans+=(l*(l-1))/2 + l;
		l=e-arr[x].second-1;
		ans+=(l*(l-1))/2 + l;
		//cout<<arr[x].first<<'\t'<<arr[x].second<<'\t'<<dp[x]<<'\t'<<s<<'\t'<<e<<'\n';
	}
	dp[n]=ans;//should be 0 already...
	//cout<<dp[n]<<'\n';
	for(int x=0;x<q;x++){
		cin>>a;
		//binary search the answer in dp array
		lo=0;hi=n;
		while(lo<hi){
			mid=(lo+hi)/2;//rounds down, impt since arr[n] doesn't exist
			if(arr[mid].first>a)lo=mid+1;
			else hi=mid;
		}
		cout<<dp[lo]<<'\n';
	}
	return 0;
}
