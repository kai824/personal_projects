// ans.cpp 1 Apr 20, 12:48:15 100 0.17 Judging completed in 3.893s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

bitset<1000005> bits;

int main() {
    ios_base::sync_with_stdio(false);
    int n,e,a;
    cin>>n>>e;
    for(int x=0;x<e;x++){
        cin>>a>>a;
        bits[a]=1;//not a producer...
    }
    for(int x=1;x<=n;x++){
        if(bits[x]==0){
            cout<<x<<" 0\n";
            return 0;
        }
    }
    return 0;
}