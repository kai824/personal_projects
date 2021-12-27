// ans.cpp 14 Jan 19, 11:03:02 0 0.59 Judging completed in 8.761s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long r,n,sum=0;
    vector<long long> v;
    cin>>r>>n;
    for(int x=0;x<r;x++){
        cin>>n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    n=v[r];//reuse as ans
    for(int x=0;x<v.size();x++){
        sum+=abs(v[r]-v[x]);
    }
    cout<<sum;
    return 0;
}