// ans.cpp 17 Oct 17, 22:26:33 80 1 Judging completed in 5.432s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ft[200005],a,c;
vector<ll> arr[200005];
ll ls(ll x){
	return(x & (-x));
}
ll query(ll p) {
	ll sum = 0;
	for(; p; p -= ls(p))sum+=ft[p];
	return sum;
}
void update(ll p, ll v) {
	for(; p <= n; p += ls(p)){
		ft[p] += v;//n is the number of elements
	}
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return(a.second<b.second);
}
int main(){
    cin>>n;
    pair<ll,ll> data[n],compress[n];
    for(ll x=0;x<n;x++){
        cin>>data[x].first;
        compress[x].first=data[x].first;
        compress[x].second=x;
    }
    
    sort(compress,compress+n);//compressing values
    for(ll x=0;x<n;x++){
        if(x==0||compress[x].first!=compress[x-1].first)a++;
        data[compress[x].second].first=a;
    }
    
    for(ll x=0;x<n;x++){
        cin>>data[x].second;
        compress[x].first=data[x].second;
        compress[x].second=x;
    }
    sort(compress,compress+n);
    a=0;
    for(ll x=0;x<n;x++){
    	if(x==0||compress[x].first!=compress[x-1].first)a++;
        data[compress[x].second].second=a;
    }
    a=0;//now used as ans...
    sort(data,data+n,cmp);
    for(ll x=0;x<n;x++){
        update(data[x].first,1);
        a+=query(data[x].first-1);
        //a-=arr[data[x].second];
        for(ll y=0;y<arr[data[x].second].size();y++){
        	if(arr[data[x].second][y]<data[x].first)a--;
        }
        
        arr[data[x].second].push_back(data[x].first);
        
        //cout<<data[x].first<<' '<<data[x].second<<'\n';
    }
    cout<<a;
    return 0;
}