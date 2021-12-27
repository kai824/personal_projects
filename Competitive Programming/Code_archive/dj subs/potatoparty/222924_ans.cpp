// ans.cpp 16 Oct 17, 22:31:46 100 0.22 Judging completed in 5.725s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b,s=1,e=1000000000;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a>>b;
        s=max(s,a);
        e=min(e,b);
    }
    cout<<max(0,e-s+1);
    return 0;
}