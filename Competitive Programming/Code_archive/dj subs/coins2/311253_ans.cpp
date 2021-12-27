// ans.cpp 30 Dec 17, 16:13:36 100 1.87 Judging completed in 10.792s on AWS Oregon.
#include <iostream>
#include <bitset>
using namespace std;
bitset<30000005>bs;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int x=0;x<q;x++){
        int a,b;
        cin>>a>>b;
        bs[a]=!bs[a];
        bs[b+1]=!bs[b+1];
    }
    bool current=0;
    for(int x=0;x<n;x++){
        current^=bs[x];
        cout<<current;
    }
    return 0;
}