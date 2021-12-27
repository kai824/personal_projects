// ans.cpp 6 Dec 18, 07:32:37 100 0 Judging completed in 3.678s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,mini=INT_MAX,a,sum=0;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        sum+=a;
        if((a%10)!=0)mini=min(mini,a);
    }
    if((sum%10)==0){
        if(mini==INT_MAX)cout<<0;
        else cout<<sum-mini;
    }else{
        cout<<sum;
    }
    return 0;
}