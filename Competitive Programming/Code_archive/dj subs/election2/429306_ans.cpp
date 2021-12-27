// ans.cpp 2 Dec 18, 09:16:00 100 0 Judging completed in 3.719s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll lcm(ll a,ll b){
    return(b/__gcd(a,b)*a);
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,t,a,tn,an,factor;
    cin>>n;
    cin>>t>>a;
    for(int x=1;x<n;x++){
        cin>>tn>>an;
        //find smallest multiple of tn >=t
        if((t%tn)==0)factor=t/tn;
        else factor=(t+tn-(t%tn))/tn;
        if((a%an)==0)factor=max(factor,a/an);
        else factor=max((a+an-(a%an))/an,factor);
        t=factor*tn;
        a=factor*an;
    }
    cout<<t+a;
    return 0;
}