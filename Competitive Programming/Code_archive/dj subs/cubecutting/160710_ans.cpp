// ans.cpp 9 Nov 16, 18:12:57 73 0 Judging completed in 6.952s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[3],b=1,ans=0;
    cin>>a[0]>>a[1]>>a[2];
    sort(a, a + 3);
    for(int d=0;d<3;d=d+1){
        ans=ans+((a[d]-1)*b);
        b=a[d]*b;
    }
    cout<<ans;
    return 0;
}