// ans.cpp 3 Dec 19, 10:51:41 0 0 Judging completed in 3.705s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,ans=0;
    for(int x=0;x<n;x++){
        cin>>a;
        ans+=a-1;
    }
    cout<<ans;
    return 0;
}