// ans.cpp 13 Jan 19, 22:10:46 100 0 Judging completed in 6.191s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,k,ans=0LL,a;
    bool possible=false;
    cin>>n>>k;
    if(k==0){
        cout<<0;
        return 0;
    }
    for(int x=0;x<n;x++){
        cin>>a;
        if(a>=k)possible=true;
        ans+=min(a,k-1);
    }
    if(possible==false)cout<<-1;
    else cout<<ans+1;
    return 0;
}