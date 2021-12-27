// ans.cpp 16 Oct 17, 22:55:13 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<ll,ll> a, pair<ll,ll> b){
    return(a.second<b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    typedef long long ll;
    ll n,a,b,aa,bb;
    cin>>n>>a>>b;
    pair<ll,ll> arr[n];
    for(ll x=0;x<n;x++){
        arr[x].first=x+1;
        cin>>aa>>bb;
        arr[x].second=abs(a-aa)+abs(b-bb);
    }
    stable_sort(arr,arr+n,cmp);
    for(ll x=0;x<n;x++){
        cout<<arr[x].first;
        if((x+1)<n)cout<<' ';
    }
    return 0;
}