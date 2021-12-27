// ans.cpp 3 Dec 19, 10:52:58 100 0 Judging completed in 3.796s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,ans=0;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        ans+=a-1;
    }
    cout<<ans;
    return 0;
}