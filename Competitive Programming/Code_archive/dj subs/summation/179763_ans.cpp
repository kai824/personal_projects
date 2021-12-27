// ans.cpp 10 Jan 17, 21:18:45 100 0.04 Judging completed in 4.549s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,ans=0;
    cin>>a;
    for(int x=0;x<a;x++){
        cin>>b;
        ans+=abs(b);
    }
    cout<<ans;
    return 0;
}