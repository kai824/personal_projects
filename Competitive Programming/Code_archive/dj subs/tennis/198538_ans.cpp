// ans.cpp 11 Mar 17, 22:40:54 100 0.24 Judging completed in 5.752s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return(a>b);
}
int main() {
    int n,a;
    map<int,int>itmap;
    vector<int> nums,nums2;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        nums.push_back(a);
        nums2.push_back(a);
    }
    sort(nums2.begin(),nums2.end(),cmp);
    nums2.erase(unique(nums2.begin(),nums2.end() ),nums2.end());
    for(int x=0;x<nums2.size();x++){
        itmap[nums2[x]]=x+1;
    }
    for(int x=0;x<n;x++){
        cout<<itmap[nums[x]];
        if(x+1<n)cout<<' ';
    }
    return 0;
}