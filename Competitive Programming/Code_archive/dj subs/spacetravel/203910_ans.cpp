// ans.cpp 9 Apr 17, 21:55:10 100 0 Judging completed in 5.817s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s,ans=0;
    cin>>n>>s;
    int nums[n];
    for(int x=0;x<n;x++){
        cin>>nums[x];
        ans+=nums[x];
    }
    sort(nums,nums+n,cmp);
    for(int x=s;x<n;x++){
        ans+=nums[x];
    }
    cout<<ans;
    return 0;
}