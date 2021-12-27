// ans.cpp 17 Jan 18, 08:26:21 0 3.02 Judging completed in 9.618s on AWS Oregon.
#include <iostream>
#include <bitset>
using namespace std;
bitset<30000005>bs;
int readint(){
   int cc = getc(stdin);
   for (;cc < '0' || cc > '9';)  cc = getc(stdin);
   int ret = 0;
   for (;cc >= '0' && cc <= '9';)
   {
      ret = ret * 10 + cc - '0';
      cc = getc(stdin);
   }
  return ret;
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