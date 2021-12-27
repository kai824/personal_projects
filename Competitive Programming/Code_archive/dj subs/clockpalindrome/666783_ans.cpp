// ans.cpp 28 Dec 19, 15:42:19 0 0.09 Judging completed in 4.214s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    bool carry=true;
    for(int x=n-1;x>=0;x--){
        if(carry){
            if(b[x]=='9'){
                b[x]='0';
                continue;
            }
            b[x]++;
            carry=false;
            break;
        }
    }
    cout<<b;
    return 0;
}