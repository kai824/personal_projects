// ans.cpp 11 Jan 17, 16:12:24 100 0 Judging completed in 4.889s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,ans=0,b;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        ans+=b;
    }
    cout<<ans;
    return 0;
}