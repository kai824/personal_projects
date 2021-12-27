// ans.cpp 13 Jan 19, 17:49:34 0 0 Judging completed in 3.435s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,k,ans=0LL,a;
    bool possible=false;
    cin>>n>>k;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a>=k)possible=true;
        ans+=min(a,k-1);
    }
    if(possible==false)cout<<ans+1;
    else cout<<ans+1;
    return 0;
}