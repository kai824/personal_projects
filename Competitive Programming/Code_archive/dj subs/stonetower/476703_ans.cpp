// ans.cpp 12 Jan 19, 17:24:13 100 0 Judging completed in 2.878s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,b,c;
    cin>>a>>b;
    c=(b-a)*(b-a+1)/2;
    cout<<c-b;
    return 0;
}