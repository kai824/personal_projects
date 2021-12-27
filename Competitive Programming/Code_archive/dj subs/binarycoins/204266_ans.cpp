// ans.cpp 16 Apr 17, 14:23:20 100 0 Judging completed in 6.166s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    ull a,b,ans=0;
    cin>>a;
    b=LLONG_MAX+1;
    for(ull x=0;x<64;x++){
        if(b>a){
        	b/=2;
        	continue;
        }
        ans++;
        a-=b;
        b/=2;
    }
    cout<<ans;
    return 0;
}