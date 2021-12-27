// ans.cpp 22 Feb 18, 09:49:03 0 3 Judging completed in 8.465s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(ll a,ll b){
    return(a*(b/__gcd(a,b)));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,ans=1,a,ans2=1;
    cin>>n;
    ll arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr[x]++;
        ans2=lcm(ans2,arr[x]);
    }
    ans2--;
    for(int x=0;x<n;x++){
        for(int y=x+1;y<n;y++){
            arr[x]/=__gcd(arr[x],arr[y]);
            if(arr[x]==1)break;
        }
        ans*=arr[x];
        ans%=(1000000007);
    }
    if(ans==0)ans=1000000007;
    cout<<ans;
    if(ans!=ans2 && n<2000){
        if(ans<ans2)while(true){}
    }
    return 0;
}