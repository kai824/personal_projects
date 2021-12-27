// ans.cpp 4 Nov 17, 16:29:51 100 0.98 Judging completed in 8.133s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string n;
    int m,tc,nex,current;
    bool broke;
    cin>>n>>tc;
    while(tc--){
        nex=0;//iterator of the next digit to intake(within n)
        current=0;//the stuff we are currently processing...
        cin>>m;
        broke=false;
        while(true){
            while(current<m){
                if(nex>=n.length()){
                    broke=true;
                    break;
                }
                current*=10;
                current+=n[nex]-'0';
                nex++;
            }
            if(broke){
                cout<<current<<'\n';
                break;
            }
            current%=m;
        }
    }
    return 0;
}