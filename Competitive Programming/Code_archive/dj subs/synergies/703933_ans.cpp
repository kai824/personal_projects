// ans.cpp 22 Feb 20, 13:37:16 0 0 Judging completed in 3.337s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin>>n;
    for(int x=0;x<n/2;x++){
        cout<<"A";
    }
    for(int x=n/2;x<n;x++){
        cout<<"B";
    }
    return 0;
}