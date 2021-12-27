// ans.cpp 4 Dec 19, 10:15:24 100 0.05 Judging completed in 4.063s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=0;
    cin>>n;
    int a;
    for(int x=0;x<n;x++){
        cin>>a;
        if(mp.find(a)==mp.end())mp[a]=1;
        else mp[a]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second>=it->first)ans+=it->second-it->first;
        else ans+=it->second;
    }
    cout<<ans;
    return 0;
}