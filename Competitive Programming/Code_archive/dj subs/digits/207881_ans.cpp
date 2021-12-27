// ans.cpp 24 May 17, 17:08:24 100 0.52 Judging completed in 27.539s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a,b;
    int tc;
    cin>>tc;
    for(int x=0;x<tc;x++){
        cin>>a>>b;
        cout<<((long long) floor((double)b * log10((double)a)))+1<<'\n';
    }
    return 0;
}