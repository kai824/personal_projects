// ans.cpp 22 Feb 18, 09:47:42 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll n,ans=1,a,ans2=1;
    cin>>n;
    ll arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
        arr[x]++;
        ans2=__lcm(ans2,arr[x]);
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
    ans--;
    cout<<ans;
    if(ans!=ans2 && n<2000){
        if(ans<ans2)while(true){}
    }
    return 0;
}