// ans.cpp 28 Dec 19, 15:44:21 10 0.1 Judging completed in 4.278s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long ans=0;
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
    for(int x=0;x<n;x++){
        ans*=10;ans+=b[x]-'0';
        ans%=(1000000007);
    }
    cout<<ans;
    return 0;
}