// ans.cpp 16 Dec 19, 15:14:14 100 0.02 Judging completed in 4.02s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m,mini=INT_MAX,last_speaker=INT_MIN,speakers=0;
    cin>>n>>m;
    pair<ll,ll> peeps[n];
    for(int x=0;x<n;x++){
        cin>>peeps[x].first>>peeps[x].second;
        peeps[x].first+=peeps[x].second;
    }
    sort(peeps,peeps+n);
    for(int x=0;x<n;x++){
        if(mini<peeps[x].first-peeps[x].second-peeps[x].second){
            last_speaker=mini;
            mini=INT_MAX;
            speakers++;
        }
        if(peeps[x].first-last_speaker>2*peeps[x].second)mini=min(mini,peeps[x].first);
    }
    if(mini<INT_MAX)speakers++;
    cout<<speakers;
    return 0;
}