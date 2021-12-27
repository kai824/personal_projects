// ans.cpp 8 Nov 16, 18:25:32 100 0.33 Judging completed in 5.386s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<uint64_t, uint64_t> a, pair<uint64_t,uint64_t> b){
    return (a.first>b.first);
}
int main() {
    uint64_t a,b;
    vector<pair<uint64_t,uint64_t> > d;
    cin>>a;
    pair<uint64_t,uint64_t> e;
    for(int c=0;c<a;c=c+1){
        cin>>b;
        e.first=b;
        e.second=c+1;
        d.push_back(e);
    }
    sort(d.begin(),d.end(),cmp);
    if(d[1].second>d[0].second)cout<<d[0].second<<" "<<d[1].second;
    else cout<<d[1].second<<" "<<d[0].second;
    return 0;
}