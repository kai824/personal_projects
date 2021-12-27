// ans.cpp 22 Jan 17, 20:01:11 50 0.04 Judging completed in 8.19s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,inrange=1,ans=0;
    cin>>n;
    int a[n];
    for(int x=0;x<n;x++){
        cin>>a[x];
    }
    for(int x=1;x<n;x++){
        if(a[x]>a[x-1]){
            ans+=inrange;
            inrange++;
        }else{
            inrange=1;
        }
    }
    cout<<ans;
    return 0;
}