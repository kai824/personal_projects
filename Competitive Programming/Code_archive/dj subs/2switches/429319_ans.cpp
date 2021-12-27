// ans.cpp 2 Dec 18, 09:39:22 100 0 Judging completed in 6.805s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max(min(b,d)-max(a,c),0);
    return 0;
}