// ans.cpp 16 Dec 19, 15:47:11 60 0.01 Judging completed in 4.228s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(pair<int,int> a,pair<int,int> b){
    return((a.first+(2*a.second))>(b.first+(2*b.second)));
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,m,speakers=0,last_covered=-1,maxi=-1;
    cin>>m>>n;
    pair<ll,ll> peeps[n];
    for(int x=0;x<n;x++){
        cin>>peeps[x].first>>peeps[x].second;
        peeps[x].first-=peeps[x].second;
    }
    sort(peeps,peeps+n,cmp);
    stable_sort(peeps,peeps+n);
    for(int x=0;x<n;x++){
        if(peeps[x].first>last_covered){
            if(maxi==-1 || maxi<peeps[x].first){
                cout<<-1;return 0;
            }
            last_covered=maxi;
            if(last_covered>=m)break;
            maxi=-1;
            speakers++;
        }
        maxi=max(maxi,peeps[x].first+peeps[x].second+peeps[x].second);
    }
    if(last_covered>=m){
        cout<<speakers;
        return 0;
    }
    if(maxi==-1){
        cout<<-1;return 0;
    }
    last_covered=maxi;
    maxi=-1;
    speakers++;
    if(last_covered>=m)cout<<speakers;
    else cout<<-1;
    return 0;
}