// ans.cpp 2 Apr 17, 16:26:13 100 0.03 Judging completed in 5.709s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int xs[n],ys[n];
    for(int x=0;x<n;x++){
        cin>>xs[x]>>ys[x];
    }
    sort(xs,xs+n);
    sort(ys,ys+n);
    cout<<xs[n/2]<<' '<<ys[n/2];
    return 0;
}