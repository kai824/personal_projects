// ans.cpp 24 Oct 17, 20:04:21 100 0 Judging completed in 5.158s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,ans=0;
    cin>>n>>k;
    k++;
    while(n>0){
        ans+=n%k;
        n/=k;
    }
    cout<<ans;
    return 0;
}