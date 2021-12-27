// ans.cpp 7 Mar 20, 12:59:39 6 0.07 Judging completed in 4.158s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    double n,k,a,ans=0;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>a;
            ans+=1/a;
        }
    }
    cout<<1/ans;
    return 0;
}