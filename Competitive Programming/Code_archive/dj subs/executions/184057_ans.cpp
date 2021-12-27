// ans.cpp 22 Jan 17, 19:07:27 100 0.02 Judging completed in 4.711s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b=0;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        b+=a;
    }
    cout<<b;
    return 0;
}