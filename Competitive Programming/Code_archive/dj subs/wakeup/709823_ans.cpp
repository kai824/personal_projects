// ans.cpp 7 Mar 20, 12:54:12 0 0.05 Judging completed in 3.922s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,a,ans=INT_MAX;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            ans=min(ans,a);
        }
    }
    cout<<ans<<".00\n";
    return 0;
}