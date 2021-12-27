// ans.cpp 17 Jan 18, 08:29:30 0 3.02 Judging completed in 7.733s on AWS Oregon.
#include <iostream>
#include <bitset>
using namespace std;
bitset<30000005>bs;
inline int readint(){
    int n=0;
    int ch=getchar_unlocked();
    while( ch <48 )ch=getchar_unlocked();
    while(ch>47)
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,a,b;
    cin>>n>>q;
    for(int x=0;x<q;x++){
        a=readint();b=readint();
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