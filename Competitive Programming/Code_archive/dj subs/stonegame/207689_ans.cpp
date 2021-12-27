// ans.cpp 19 May 17, 22:00:35 50 0 Judging completed in 9.567s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n;
    cin>>n;
    ll a[n+5];
    a[0]=-1;
    for(ll x=1;x<=n;x++){
        for(ll y=1;(true);y++){
            if(y*3>=x){
                a[x]=x;
                break;
            }
            if(y*2<a[x-y]){
                a[x]=y;
                break;
            }
        }
    }
    cout<<a[n];
    return 0;
}