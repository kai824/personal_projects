// ans.cpp 11 Jan 20, 16:46:12 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int dp[1000005],n;
pair<pair<int,int>,int> m[1000005];

vector<pair<int,int> > v;//index, reward



bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    return(a.first.second<b.first.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int it;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>m[x].first.first>>m[x].first.second>>m[x].second;
    }sort(m,m+n,cmp);
    v.emplace_back(0,0);
    for(int x=0;x<n;x++){
        it=lower_bound(v.begin(),v.end(),m[x].first.first)-v.begin();
        if(v[it].second+m[x].second>v.back().second){
            if(v.back().first<m[x].first.second)
            v.emplace_back(m[x].first.second,v[it].second+m[x].second);
            else
            v.back().second=v[it].second+m[x].second;
        }
    }
    cout<<v.back().second;
    return 0;
}