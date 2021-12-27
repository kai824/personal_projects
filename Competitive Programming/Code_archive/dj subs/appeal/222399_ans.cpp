// ans.cpp 14 Oct 17, 12:30:06 100 0.17 Judging completed in 6.464s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
int ft[100005],n,ans;
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
	return(a>b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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