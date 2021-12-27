// ans.cpp 17 Feb 18, 11:16:07 100 0.12 Judging completed in 4.176s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int r[1000005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=1,b;
    cin>>n;
    r[0]=1;
    for(int x=1;x<n;x++){
        cin>>b;
        r[x]=r[b]+1;
        ans=max(ans,r[x]);
    }
    cout<<ans;
    return 0;
}