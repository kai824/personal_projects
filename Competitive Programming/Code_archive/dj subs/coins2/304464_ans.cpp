// ans.cpp 24 Dec 17, 19:52:15 20 2.01 Judging completed in 6.734s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
unsigned char arr[30000003];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    cin>>n>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        arr[a]^=1;
        arr[b+1]^=1;
    }
    for(int x=0,current=0;x<n;++x){
        current^=arr[x];
        cout<<current;
    }
    return 0;
}