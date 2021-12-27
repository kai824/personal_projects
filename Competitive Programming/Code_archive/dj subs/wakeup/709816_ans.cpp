// ans.cpp 7 Mar 20, 12:52:51 0 0.05 Judging completed in 3.775s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,a,ans=INT_MAX;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a;
            ans=min(ans,a);
        }
    }
    printf("%.2f",&ans);
    return 0;
}