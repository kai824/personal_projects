// ans.cpp 7 Mar 20, 12:57:36 0 0.07 Judging completed in 4.468s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    double n,k,a,ans=INT_MAX;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            ans=min(ans,a);
        }
    }
    cout<<ans;
    return 0;
}