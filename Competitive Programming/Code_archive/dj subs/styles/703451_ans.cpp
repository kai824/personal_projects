// ans.cpp 22 Feb 20, 11:19:06 0 0.03 Judging completed in 3.138s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,l,r,lo,hi,mid;
    cin>>t;
    while(t--){
        cin>>l>>r;
        if(l>r)swap(l,r);
        lo=0;hi=r;
        while(lo<hi){
            mid=hi-(hi-lo)/2;
            if(mid*(mid+1)/2>r){
                hi=mid-1;
            }else lo=mid;
        }
        cout<<lo+1<<'\n';
    }
    return 0;
}