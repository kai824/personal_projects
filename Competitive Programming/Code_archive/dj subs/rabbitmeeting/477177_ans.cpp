// ans.cpp 14 Jan 19, 11:06:32 35 0.58 Judging completed in 4.051s on AWS Oregon.
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
    n=v[r-1];//reuse as ans
    for(int x=0;x<v.size();x++){
        if(n-v[x]>=0)sum+=n-v[x];
        else sum+=v[x]-n;
    }
    cout<<n<<' '<<sum;
    return 0;
}