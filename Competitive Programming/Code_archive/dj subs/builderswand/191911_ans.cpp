// ans.cpp 15 Feb 17, 20:54:27 3 0 Judging completed in 5.69s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,ans=-5;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        ans=max(ans,b);
    }cout<<ans;
    return 0;
}