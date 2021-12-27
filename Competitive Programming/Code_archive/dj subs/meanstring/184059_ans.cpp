// ans.cpp 22 Jan 17, 19:14:52 100 0 Judging completed in 6.992s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b=0;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        b+=a;
    }
    cout<<b/n;
    return 0;
}