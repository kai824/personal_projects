// ans.cpp 5 Jan 19, 22:46:10 100 0.02 Judging completed in 2.812s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin>>n;
    ll a[n],b[n],total=0;//no. of button presses
    for(int x=0;x<n;x++){
        cin>>a[x]>>b[x];
    }
    for(int x=n-1;x>=0;x--){
        if(((a[x]+total)%b[x])==0)continue;//avoid adding b[x]
        total+=b[x]-((a[x]+total)%b[x]);
    }
    cout<<total;
    return 0;
}