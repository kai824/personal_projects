// ans.cpp 1 May 17, 20:29:08 0 0.14 Judging completed in 7.655s on AWS Ireland.
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
    if(b%2==0)cout<<"YES";
    else cout<<"NO";
    return 0;
}