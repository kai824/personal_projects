// ans.cpp 24 Dec 17, 20:07:28 20 2.04 Judging completed in 7.381s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
unsigned char arr[30000005];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N,Q;cin>>N>>Q;
    while(Q--){
        int a,b;cin>>a>>b;
        arr[a]^=1;
        arr[b+1]^=1;
    }
    for(int i=0,curr=0;i<N;++i){
        curr^=arr[i];
        cout<<curr;
    }
}