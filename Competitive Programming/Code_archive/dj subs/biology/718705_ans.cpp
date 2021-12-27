// ans.cpp 1 Apr 20, 12:47:25 3 0.09 Judging completed in 3.751s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;

bitset<1000005> bits,bits2;

int main() {
    ios_base::sync_with_stdio(false);
    int n,e,a;
    cin>>n>>e;
    for(int x=1;x<=n;x++)bits[x]=bits2[x]=0;
    for(int x=0;x<n;x++){
        cin>>a;
        bits2[a]=1;
        cin>>a;
        bits2[a]=1;
        bits[a]=1;//not a producer...
    }
    for(int x=1;x<=n;x++){
        if(bits[x]==0){
            cout<<x<<" 0\n";
            return 0;
        }
        if(bits2[x]==0){//the node not in any edges...
            cout<<x<<" 0\n";
            return 0;
        }
    }
    return 0;
}