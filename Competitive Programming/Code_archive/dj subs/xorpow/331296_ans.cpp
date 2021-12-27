// ans.cpp 27 Feb 18, 22:02:23 100 0 Judging completed in 4.621s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
long long cnts[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,k,a,current=0,ans=0,u;
    cin>>n>>k;
    cnts[current]++;
    for(int x=0;x<n;x++){
        cin>>a;
        current^=a;
        cnts[current]++;
        u=k;
        while(u<256){
        	ans+=cnts[(current^u)];
        	u*=k;
        }
    }
    cout<<ans;
    return 0;
}