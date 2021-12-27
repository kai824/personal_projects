// ans.cpp 21 Oct 17, 10:31:54 100 0 Judging completed in 3.728s on AWS Oregon.
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