// ans.cpp 4 Nov 17, 10:19:52 100 0 Judging completed in 3.263s on AWS Oregon.
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