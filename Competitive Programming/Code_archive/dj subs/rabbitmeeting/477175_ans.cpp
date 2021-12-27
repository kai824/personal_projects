// ans.cpp 14 Jan 19, 11:04:25 0 0.58 Judging completed in 5.247s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long r,n,a,b,sum=0;
    vector<long long> v;
    cin>>r>>n;
    for(int x=0;x<r;x++){
        cin>>a>>b;
        v.push_back(a);
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    n=v[r];//reuse as ans
    for(int x=0;x<v.size();x++){
        sum+=abs(n-v[x]);
    }
    cout<<sum;
    return 0;
}