// ans.cpp 12 Nov 18, 14:45:26 100 0.31 Judging completed in 2.932s on AWS Oregon.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,ans=0,removed;
    cin>>n;
    ll h[n];
    vector<pair<ll,ll> > v;//height, stuff removed
    for(int x=0;x<n;x++){
        cin>>h[x];
    }
    v.push_back(make_pair(h[0],0));
    for(int x=1;x<n;x++){
        ans+=v.size();
		removed=0;
        while(v.size()>0 && v.back().first<h[x]){
			removed++;
			removed+=v.back().second;
			ans+=v.back().second;
            v.pop_back();
        }
        v.push_back(make_pair(h[x],removed));
    }
    cout<<ans;
    return 0;
}