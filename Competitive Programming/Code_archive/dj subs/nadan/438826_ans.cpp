// ans.cpp 6 Dec 18, 07:29:19 100 0 Judging completed in 6.617s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int x=1;x<k;x++){
        cout<<x<<'\n';
        n-=x;
    }
    cout<<n;//since always possible
    return 0;
}