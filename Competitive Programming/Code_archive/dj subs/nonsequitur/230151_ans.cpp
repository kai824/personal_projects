// ans.cpp 24 Oct 17, 20:03:33 100 0 Judging completed in 5.042s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s,e;
    cin>>n>>s>>e;
    for(int x=s;x<=e;x++){
        if(x%n==0)cout<<x<<'\n';
    }
    return 0;
}