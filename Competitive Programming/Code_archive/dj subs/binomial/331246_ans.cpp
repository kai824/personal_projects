// ans.cpp 27 Feb 18, 21:26:21 100 0 Judging completed in 4.907s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long top[105],bottom[105];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,k,a,ans=1;
    cin>>n>>k;
    for(int x=0;x<k;x++){
        bottom[x]=x+1;
        top[x]=n-x;
    }
    for(int x=0;x<k;x++){
        for(int y=0;y<k;y++){
            a=__gcd(top[x],bottom[y]);
            top[x]/=a;
            bottom[y]/=a;
        }
    }
    for(int x=0;x<k;x++){
    	ans*=top[x];
    	ans%=1000000007;
    }
    cout<<ans;
    return 0;
}