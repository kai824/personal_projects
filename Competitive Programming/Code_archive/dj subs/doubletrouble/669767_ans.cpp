// ans.cpp 31 Dec 19, 18:07:54 100 0.25 Judging completed in 4.292s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,k,a,b;
    cin>>n>>k;
    multiset<ll> ss;
    for(int x=0;x<n;x++){
        cin>>a;
        ss.insert(a);
    }
    while(k>0 && *ss.begin()*2<*ss.rbegin()){
        a=*ss.begin();
        ss.erase(ss.begin());
        ss.insert(a*2);
        k--;
    }
    b=k%n;
    if(b==0)b=n;
    k-=b;
    for(int x=1;x<b;x++){
        ss.erase(ss.begin());
    }
    a=*ss.begin();
    for(int x=0;x<=k/n;x++){
        a*=2;
        a%=1000000007;
    }
    cout<<a;
    return 0;
}