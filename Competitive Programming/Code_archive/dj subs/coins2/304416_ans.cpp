// ans.cpp 24 Dec 17, 19:01:08 20 2.01 Judging completed in 8.988s on AWS Oregon.
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
        arr[a]%=2;
        arr[b+1]%=2;
    }
    for(int x=0;x<n;x++){
        current+=arr[x];
        cout<<(current%2);
    }
    return 0;
}