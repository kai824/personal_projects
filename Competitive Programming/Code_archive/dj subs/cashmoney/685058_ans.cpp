// ans.cpp 24 Jan 20, 17:17:40 0 1.46 Judging completed in 6.686s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=1e9+12;
ll h,d,p,a;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        h+=a*a;h+=2*a*p;
        h%=mod;
        
        p+=a;
        p%=mod;
        
        d+=a*a;
        d%=mod;
    }
    d=d*d;d%=mod;
    h-=d;
    while(h<0){h+=mod;}
    cout<<h;
    return 0;
}