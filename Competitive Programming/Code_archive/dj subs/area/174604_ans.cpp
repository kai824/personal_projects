// ans.cpp 24 Dec 16, 22:52:45 100 0.24 Judging completed in 4.455s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n,h=0,w=0,ans;
    cin>>n;
    ans=0;
    for(long long int x=0;x<n;x++){
        cin>>h>>w;
        ans+=(h*w);
    }
    cout<<ans;
    return 0;
}