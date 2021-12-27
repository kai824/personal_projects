// ans.cpp 14 Aug 19, 21:24:52 10 0.74 Judging completed in 5.713s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ft[1000005],m=1e9+7;
//ll ans[1000005];
inline ll ls(int x){
    return x & (-x);
}
inline void update(ll p,ll v){
    for(;p<1000002;p+=ls(p)){
        ft[p]+=v;
        ft[p]%=m;
    }
}
inline ll query(ll p){
    ll ans=0;
    for(;p;p-=ls(p)){
        ans+=ft[p];
        ans%=m;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,cur_it=1,increment;
    cin>>n;
    ll arr[n],total;
    pair<int,int> arr2[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr2[x]=make_pair(arr[x],x);
    }
    sort(arr2,arr2+n);
    arr[arr2[0].second]=1;
    for(int x=1;x<n;x++){
        if(arr2[x].first!=arr2[x-1].first)cur_it++;
        arr[arr2[x].second]=cur_it;
    }
    total=0;
    for(int x=0;x<n;x++){
        increment=query(arr[x])+1LL;//1 since can dao everything
        total+=increment;
        total%=m;
        update(arr[x],increment);
    }
    cout<<total;
    return 0;
}