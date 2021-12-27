// ans.cpp 13 Feb 17, 07:39:39 0 0 Judging completed in 7.066s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,ans=0;
    cin>>a>>b;
    if(a>b)swap(a,b);
    ans+=b/2;
    b=b%2;
    if(a<ans){
        ans=a;
        cout<<ans;
        return 0;
    }
    a-=ans;
    if(a>=2 && b==1){
        ans++;
        cout<<ans;
        return 0;
    }
    return 0;
}