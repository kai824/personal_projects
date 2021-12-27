// ans.cpp 31 May 17, 18:59:07 50 1 Judging completed in 10.755s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,ans=1;
    cin>>n;
    for(int x=1;x<=n;x++){//if 2^x>n, answer is x
        //at any point, ans should be 2^x
        ans*=2;
        if(ans>n){
            ans=x;
            break;
        }
    }
    cout<<ans;
    return 0;
}