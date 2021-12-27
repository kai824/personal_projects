// ans.cpp 7 Nov 16, 16:13:11 0 0 Compilation failed on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int> a, pair<string, int> b){
    return (a.first>b.first);
}
int main() {
    int a,b;
    vector<pair<int,int> > d;
    cin>>a;
    for(int c=0;c<a;c=c+1){
        cin>>b;
        d[c].first=b;
        d[c].second=c+1;
    }
    sort(d.begin(),d.end(),cmp);
    cout<<d[0].second<<" "<<d[1].second;
    return 0;
}