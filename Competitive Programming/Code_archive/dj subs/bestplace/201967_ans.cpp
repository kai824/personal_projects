// ans.cpp 22 Mar 17, 20:09:52 3 1 Judging completed in 6.971s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int xs[n],ys[n];
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>xs[x]>>ys[x];
    }
    sort(xs,xs+n);
    sort(ys,ys+n);
    cout<<xs[n/2]<<' '<<ys[n/2];
    return 0;
}