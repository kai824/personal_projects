// ans.cpp 1 May 17, 20:30:24 100 0.13 Judging completed in 6.899s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,b=0;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        b^=a;
    }
    if(b%2==0)cout<<"Yes";
    else cout<<"No";
    return 0;
}