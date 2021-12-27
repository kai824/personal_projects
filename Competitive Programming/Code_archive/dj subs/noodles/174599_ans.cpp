// ans.cpp 24 Dec 16, 22:41:20 100 0.08 Judging completed in 4.506s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
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