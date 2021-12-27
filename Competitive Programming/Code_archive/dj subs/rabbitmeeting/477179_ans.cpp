// ans.cpp 14 Jan 19, 11:07:27 100 1.15 Judging completed in 5.1s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long r,n,a,b,sum=0;
    vector<int> v;
    cin>>r>>n;
    for(long long x=0;x<r;x++){
        cin>>a>>b;
        v.push_back(a);
        v.push_back(b);
    }
    sort(v.begin(),v.end());
    n=v[r-1];//reuse as ans
    for(long long x=0;x<v.size();x++){
        if(n-v[x]>=0)sum+=n-v[x];
        else sum+=v[x]-n;
    }
    cout<<n<<' '<<sum;
    return 0;
}