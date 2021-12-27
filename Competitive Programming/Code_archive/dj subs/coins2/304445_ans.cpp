// ans.cpp 24 Dec 17, 19:38:30 20 2.01 Judging completed in 7.492s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
unsigned char arr[30000003];
int n,q,a,b,current;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    while(q--){
        cin>>a>>b;
        arr[a]^=1;
        arr[b+1]^=1;
    }
    for(int x=0;x<n;x++){
        current^=arr[x];
        cout<<current;
    }
    return 0;
}