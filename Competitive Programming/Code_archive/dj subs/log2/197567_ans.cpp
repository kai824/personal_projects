// ans.cpp 9 Mar 17, 10:31:42 100 0 Judging completed in 6.746s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,ans=0;
    cin>>a;
    while(a>=2){
        a/=2;
        ans++;
    }
    cout<<ans;
    return 0;
}