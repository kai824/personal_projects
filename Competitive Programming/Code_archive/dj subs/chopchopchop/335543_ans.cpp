// ans.cpp 11 Mar 18, 14:28:41 81.82 0.09 Judging completed in 6.85s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long ps[1000005],ans=0;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,maxi=0,maxit;
    cin>>n>>k;
    if(k==0)while(true){}
    for(int x=1;x<=n;x++){
        cin>>ps[x];
        ps[x]+=ps[x-1];
    }
    for(int x=n-k;x<=n;x++){
        if(ps[x]-ps[x-(n-k)]>maxi){
            maxit=x;
            maxi=ps[x]-ps[x-(n-k)];
        }
    }
    vector<long long> v;
    for(int x=1;x<maxit-(n-k);x++){
        v.push_back(ps[x]-ps[x-1]);
    }
    for(int x=maxit+1;x<=n;x++){
        v.push_back(ps[x]-ps[x-1]);
    }
    v.push_back(maxi);
    sort(v.begin(),v.end());
    for(int x=1;x<v.size();x++){
        ans+=v[x]-v[x-1];
    }
    cout<<ans;
    return 0;
}