// ans.cpp 16 Oct 17, 17:10:36 80 1 Judging completed in 4.21s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(float a,float b){
    return(a>b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s,ans=0;
    cin>>n>>s;
    if(s>n)while(true){}
    float nums[n];
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