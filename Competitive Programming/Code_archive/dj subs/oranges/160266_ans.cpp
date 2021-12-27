// ans.cpp 7 Nov 16, 16:31:58 0 0.33 Judging completed in 5.51s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long int, long long int> a, pair<long long int, long long int> b){
    return (a.first>b.first);
}
int main() {
    long long int a,b;
    vector<pair<long long int,long long int> > d;
    cin>>a;
    pair<int,int> e;
    for(int c=0;c<a;c=c+1){
        cin>>b;
        e.first=b;
        e.second=c+1;
        d.push_back(e);
    }
    sort(d.begin(),d.end(),cmp);
    cout<<d[0].second<<" "<<d[1].second;
    return 0;
}