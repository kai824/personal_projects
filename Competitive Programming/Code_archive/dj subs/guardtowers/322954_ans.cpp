// ans.cpp 7 Feb 18, 20:05:01 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int arr[2000001],b[2000001];
bool cmp(int a, int c){
    return(b[a]>b[c]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    set<ll>ss;
    ll n,ans=0;
    cin>>n;
    for(ll x=0;x<n;x++){
        cin>>b[x].first;
        arr[x].second=x;
    }
    sort(arr,arr+n,cmp);
    ss.insert(-1);ss.insert(n);
    for(ll x=0;x<n;x++){
        auto upper=ss.lower_bound(arr[x]);
        auto lower=upper;
        lower--;
        ans+=(arr[x]-1- *lower)+(*upper-1-arr[x]);
        //cout<<*ss.lower_bound(arr[x].second)<<'\n';
        ss.insert(arr[x]);
    }
    cout<<ans;
    return 0;
}
//4 1 3 2 0