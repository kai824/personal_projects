// ans.cpp 28 May 17, 19:41:12 100 0 Judging completed in 9.501s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n,c;
    cin>>n>>c;
    cout<<n/(c+1)<<' '<<n-(c*(n/(c+1)))<<'\n';
    return 0;
}