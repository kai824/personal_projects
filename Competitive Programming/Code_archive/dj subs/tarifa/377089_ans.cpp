// ans.cpp 12 Jul 18, 10:42:02 100 0 Judging completed in 4.061s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int x,n,a;
    cin>>x>>n;
    x*=(n+1);
    for(int i=0;i<n;i++){
        cin>>a;
        x-=a;
    }
    cout<<x;
    return 0;
}