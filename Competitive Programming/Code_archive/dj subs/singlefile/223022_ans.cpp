// ans.cpp 17 Oct 17, 13:11:02 100 0.68 Judging completed in 4.144s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ft[1000005],n;
ll ft2[1000005];
ll ls(ll x){
	return(x & (-x));
}
ll query(ll p) {
	ll sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
ll query2(ll p){
    ll sum=0;
    for(;p;p-=ls(p))sum+=ft2[p];
    return sum;
}
void update(ll p, ll v) {
	for(;p<=(n+3);p+=ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
void update2(ll p,ll v){
    for(;p<=(n+3);p+=ls(p)){
        ft2[p]+=v;
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    ll arr[n],ans=0,a,a1=0,a2=0;
    vector<pair<ll,ll> > arr2;
    map<ll,ll>itmap;
    for(ll x=0;x<n;x++){
        cin>>arr[x];
        arr2.push_back(make_pair(arr[x],x));
    }
    sort(arr2.begin(),arr2.end());
    a=0;
    for(ll x=0;x<n;x++){
    	if(x==0||arr2[x].first!=arr2[x-1].first){
    		a++;
    	}
    	arr[arr2[x].second]=a;
    }
    for(ll x=0;x<n;x++){
        ans+=a2-query2(arr[x]);
        a=a1-query(arr[x]);
        update2(arr[x],a);
        a2+=a;
        update(arr[x],1);
        a1+=1;
    }
    cout<<ans;
    return 0;
}