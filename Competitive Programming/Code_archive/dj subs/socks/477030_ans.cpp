// ans.cpp 13 Jan 19, 17:42:26 0 0 Judging completed in 4.34s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,k,ans=1,a;
    bool possible=false;
    cin>>n>>k;
    for(int x=0;x<n;x++){
        cin>>a;
        if(a>=k)possible=true;
        ans+=min(a,k-1);
    }
    if(possible==false)cout<<-1;
    else cout<<ans;
    return 0;
}