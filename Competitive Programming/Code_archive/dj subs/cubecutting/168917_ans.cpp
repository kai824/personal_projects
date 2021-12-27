// ans.cpp 10 Dec 16, 15:47:50 100 0 Judging completed in 5.715s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    uint64_t ans=0,a[3],b=1;
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a + 3);
    for(int d=0;d<3;d=d+1){
        ans=ans+((a[d]-1)*b);
        b=a[d]*b;
    }
    cout<<ans;
    return 0;
}