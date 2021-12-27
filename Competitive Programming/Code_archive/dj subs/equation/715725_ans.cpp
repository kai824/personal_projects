// ans.cpp 21 Mar 20, 22:39:02 100 0.56 Judging completed in 4.973s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,a,mini,maxi,sum=0;

vector<int> v;

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>k;
    for(int x=0;x<n;x++){
        mini=INT_MAX;
        maxi=INT_MIN;
        for(int y=0;y<k;y++){
            cin>>a;
            mini=min(mini,a);
            maxi=max(maxi,a);
        }
        sum+=mini;
        v.push_back(mini+maxi);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int x=0;x<n/2;x++){
        sum-=v[x];
    }
    cout<<sum<<'\n';
}