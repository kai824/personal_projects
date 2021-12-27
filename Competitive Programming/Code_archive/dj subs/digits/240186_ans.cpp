// ans.cpp 4 Nov 17, 10:20:23 100 0.6 Judging completed in 6.405s on AWS Oregon.
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