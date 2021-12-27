// ans.cpp 9 Apr 17, 21:39:23 0 1 Judging completed in 6.376s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s;
    cin>>n>>s;
    int nums[n];
    for(int x=0;x<n;x++){
        cin>>nums[x];
    }
    int pt1=0,pt2=0,ans=0;//from pt1 to pt2...
    long long current=nums[0];
    while(pt2<=n && pt1<=n){
        if(current<=s){
            ans+=pt2-pt1+1;
            pt2++;
            current+=nums[pt2];
        }else{
            current-=nums[pt1];
            pt1++;
        }
    }
    cout<<ans;
    return 0;
}