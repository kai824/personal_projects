// ans.cpp 22 Feb 20, 11:21:22 4 0.03 Judging completed in 3.194s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long t,l,r,lo,hi,mid;
    cin>>t;
    while(t--){
        cin>>l>>r;
        if(l>r)swap(l,r);
        lo=0ll;hi=r;
        while(lo<hi){
            mid=hi-(hi-lo)/2ll;
            if(mid*(mid+1ll)/2ll>r){
                hi=mid-1ll;
            }else lo=mid;
        }
        cout<<lo+1<<'\n';
    }
    return 0;
}