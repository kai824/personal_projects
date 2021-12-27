// ans.cpp 11 Dec 16, 19:58:53 0 0.23 Judging completed in 7.055s on AWS Ireland.
#include<bits/stdc++.h>
using namespace std;
int ft[50005],n,ans;
string a;
vector<string> nums,nums2;
vector<int> m_nums;
map<string,int>itmap;
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
bool cmp(string a,string b){
    return(a<b);
}
int main(){
	ans=0;
	cin>>n;
	for(int y=0;y<n;y++){
		cin>>a;
		nums.push_back(a);
		nums2.push_back(a);
	}
	sort(nums2.begin(),nums2.end(),cmp);
	nums2.erase(unique(nums2.begin(),nums2.end() ),nums2.end());
	for(int y=0;y<nums2.size();y++){
		itmap[nums2[y]]=y+1;
	}
	for(int y=0;y<nums.size();y++){
		m_nums.push_back(itmap[nums[y]]);
	}
	for(int y=0;y<n;y++){
		update(m_nums[y],1);
		ans+=query(n)-query(m_nums[y]);
	}
	cout<<ans<<endl;
}