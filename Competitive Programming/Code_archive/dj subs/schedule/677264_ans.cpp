// ans.cpp 11 Jan 20, 17:19:15 100 0.5 Judging completed in 5.001s on AWS Oregon.
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll n;
pair<pair<ll,ll>,ll> m[1000005];

vector<pair<ll,ll> > v;//index, reward



bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b){
    return(a.first.second<b.first.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll it;
    cin>>n;
    for(ll x=0;x<n;x++){
        cin>>m[x].first.first>>m[x].first.second>>m[x].second;
    }sort(m,m+n,cmp);
    //v.emplace_back(0,0);
	v.push_back(make_pair(0,0));
    for(ll x=0;x<n;x++){
        it=upper_bound(v.begin(),v.end(),make_pair(m[x].first.first,-1ll))-v.begin();
				it--;
				if(it<0)continue;
        if(v[it].second+m[x].second>v.back().second){
            if(v.back().first<m[x].first.second)
            //v.emplace_back(m[x].first.second,v[it].second+m[x].second);
						v.push_back(make_pair(m[x].first.second,v[it].second+m[x].second));
            else
            v.back().second=v[it].second+m[x].second;
        }
    }
    cout<<v.back().second;
    return 0;
}