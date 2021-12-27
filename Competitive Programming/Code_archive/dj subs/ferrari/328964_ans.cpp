// ans.cpp 22 Feb 18, 09:34:44 23 0.02 Judging completed in 7.308s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(ll a,ll b){
    return(a*(b/__gcd(a,b)));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,ans=1,a;
    cin>>n;
    while(n--){
        cin>>a;a++;
        ans=lcm(a,ans);
        ans%=(1000000007);
    }
    cout<<ans-1;
    return 0;
}