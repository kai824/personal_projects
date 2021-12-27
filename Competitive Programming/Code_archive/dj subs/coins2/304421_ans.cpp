// ans.cpp 24 Dec 17, 19:03:53 0 1.64 Judging completed in 24.303s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
unsigned char arr[30000003],current;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,a,b;
    cin>>n>>q;
    for(int x=0;x<q;x++){
        cin>>a>>b;
        arr[a]++;
        arr[b+1]++;
        arr[a]^=1;
        arr[b+1]^=1;
    }
    for(int x=0;x<n;x++){
        current^=arr[x];
        cout<<(current);
    }
    return 0;
}