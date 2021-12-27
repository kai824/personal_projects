// ans.cpp 7 Nov 19, 16:19:53 0 0.16 Judging completed in 3.608s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=1;
    cin>>n;
    long long arr[n];
    for(int x=0;x<n;x++){cin>>arr[x];}
    sort(arr,arr+n);
    for(int x=1;x<n;x++){
        if(arr[x]!=arr[x-1])ans++;
    }
    cout<<ans;
    return 0;
}