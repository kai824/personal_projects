// ans.cpp 25 Dec 17, 14:08:48 60 0.44 Judging completed in 4.618s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin>>t;
    unsigned long long n;
    while(t--){
        cin>>n;
        unsigned long long ans=0;
        for(int x=1;x*x<=n;x++){
            if((n%x)!=0)continue;
            ans+=x;
            if(x*x==n)continue;
            ans+=(n/x);
        }
        cout<<ans<<'\n';
    }
    return 0;
}