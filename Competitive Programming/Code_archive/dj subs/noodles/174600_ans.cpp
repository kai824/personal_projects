// ans.cpp 24 Dec 16, 22:43:01 100 0.03 Judging completed in 5.543s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,ans,y=1;
    cin>>n;
    int ex[n];
    for(int x=0;x<n;x++){
        cin>>ex[x];
    }
    sort(ex,ex+n);
    ans=0;//a is now used as the answer
    for(int x=1;x<=n;x++){//x is i (day i)
        if(y<=ex[x-1]){
            ans++;
            y++;
        }
    }
    cout<<ans;
    return 0;
}