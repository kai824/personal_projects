// ans.cpp 22 Jan 17, 20:02:29 100 0.03 Judging completed in 5.506s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n,inrange=1,ans=0;
    cin>>n;
    long long int a[n];
    for(long long int x=0;x<n;x++){
        cin>>a[x];
    }
    for(long long int x=1;x<n;x++){
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