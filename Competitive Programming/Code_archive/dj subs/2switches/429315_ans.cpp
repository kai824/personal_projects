// ans.cpp 2 Dec 18, 09:38:29 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>a>>b>>c>>d;
    cout<<min(b,d)-max(a,c);
    return 0;
}