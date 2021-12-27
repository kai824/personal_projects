// ans.cpp 5 Feb 17, 21:16:18 20 0 Judging completed in 4.74s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,ans=0;
    cin>>n>>k;
    int a[n];
    cin>>a[0];
    for(int x=1;x<n;x++){
        cin>>a[x];
        if(a[x]-a[x-1]>=k){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}