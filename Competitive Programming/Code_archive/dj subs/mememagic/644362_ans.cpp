// ans.cpp 12 Dec 19, 17:37:52 0 0.11 Judging completed in 4.258s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline double divide(ll a,ll b){
	ll aa=a,bb=b;
	return aa/bb;
}

//convex hull...
vector<pair<ll,pair<ll,ll> > >lines;
inline void add_line(ll m, ll c){//gradient, y-intercept, assumes increasing gradient
	while(lines.size()>=2){
		//intersect(new, third last)
		if(divide(c-lines[lines.size()-2].second.second,lines[lines.size()-2].second.first-m)<lines.back().first){
			lines.pop_back();//will be irrelevant
		}else break;
	}
	if(lines.size()==0)lines.push_back(make_pair(LLONG_MIN,make_pair(m,c)));
	else lines.push_back(make_pair(divide(c-lines.back().second.second, lines.back().second.first-m),make_pair(m,c)));
}
inline ll query(ll x){//x-coordinate, uses max_point
	ll mid,lo=0,hi=lines.size()-1;
	while(lo<hi){//find highest number less than x...
		mid=hi-(hi-lo)/2;
		if(lines[mid].first<=x)lo=mid;
		else hi=mid-1;
	}
	return lines[lo].second.first*x+lines[lo].second.second;
}
int main() {
    ll n,origin=0,ans=0;
    cin>>n;
    ll arr[n+1],ps[n+1];
    arr[0]=0;ps[0]=0;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
        origin+=arr[x]*x;
        ps[x]=ps[x-1]+arr[x];
    }
    for(int x=1;x<=n;x++){//start pos
        add_line(x,-ps[x-1]);
		ans=max(ans,query(arr[x])+ps[x-1]-(arr[x]*x));
    }
	lines.clear();
	for(int x=n;x>0;x--){//start pos
        add_line(-x,-ps[x-1]);
		//negate gradient and 'x' tgt, so gradient still increasing...
		ans=max(ans,query(-arr[x])+ps[x-1]-(arr[x]*x));
    }
    cout<<origin+ans;
    return 0;
}