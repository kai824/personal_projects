// ans.cpp 13 Jan 19, 16:32:05 0 0 Judging completed in 3.297s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string a;
    long long cur=0,ans=0;
    for(int x=0;x<a.length();x++){
        if(a[x]=='u'){
            cur=0;
            continue;
        }
        cur++;
        ans+=cur;
    }
    cout<<ans;
    return 0;
}