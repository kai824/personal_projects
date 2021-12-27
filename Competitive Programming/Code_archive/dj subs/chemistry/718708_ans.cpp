// ans.cpp 1 Apr 20, 12:49:45 0 0 Judging completed in 3.324s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int maxi=0,n,a;
    cin>>n;
    while(n--){
        cin>>a;
        maxi=max(maxi,abs(a));
    }
    assert(maxi<=4);
    return 0;
}