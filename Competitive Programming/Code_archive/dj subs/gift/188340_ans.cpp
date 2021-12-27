// ans.cpp 5 Feb 17, 21:19:54 100 0 Judging completed in 4.89s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,ans=0;
    cin>>n>>k;
    int a[n];
    cin>>a[0];
    for(int x=1;x<n;x++){
        cin>>a[x];
        if(a[x-1]-a[x]>=k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}