// ans.cpp 8 Feb 17, 09:04:50 100 0.21 Judging completed in 2.537s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int ft[50005],n,t,a,ans;
vector<int> nums,nums2;
map<int,int>itmap;
int ls(int x){
	return(x & (-x));
}
int query(int p) {
	int sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(int p, int v) {
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
int main(){
	cin>>t;
	for(int x=0;x<t;x++){
		ans=0;
		cin>>n;
		for(int y=0;y<n;y++){
			cin>>a;
			nums.push_back(a);
			nums2.push_back(a);
		}
		sort(nums2.begin(),nums2.end());
		nums2.erase(unique(nums2.begin(),nums2.end() ),nums2.end());
		for(int y=0;y<nums2.size();y++){
			itmap[nums2[y]]=y+1;
		}
		for(int y=0;y<nums.size();y++){
			nums[y]=itmap[nums[y]];
		}
		for(int y=0;y<n;y++){
			update(nums[y],1);
			ans+=query(n)-query(nums[y]);
		}
		cout<<ans<<endl;
		fill_n(ft,n+3,0);
		itmap.clear();
		nums.clear();
		nums2.clear();
	}
}