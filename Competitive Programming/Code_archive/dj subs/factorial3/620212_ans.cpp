// ans.cpp 2 Dec 19, 10:50:51 0 0 Judging completed in 3.6s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    long long n,cur=1,nex=0,ans=0;
    cin>>n;
    while(cur<n){
        nex++;
        cur*=nex;
    }
    while(true){
        if(cur<=n){
            n-=cur;
            ans++;
            if(n==0)break;
        }
        cur/=nex;nex--;
    }
    cout<<ans;
    return 0;
}