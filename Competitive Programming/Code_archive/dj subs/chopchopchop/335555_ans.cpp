// ans.cpp 11 Mar 18, 14:31:44 81.82 0.11 Judging completed in 8.253s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long ps[1000005],ans=0,mini=INT_MAX;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k,maxi=0,maxit;
    cin>>n>>k;
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
    for(int x=1;x<maxit-(n-k);x++){
        mini=min((ps[x]-ps[x-1]),mini);
    }
    for(int x=maxit+1;x<=n;x++){
        mini=min(mini,ps[x]-ps[x-1]);
    }
    cout<<maxi-mini;
    return 0;
}