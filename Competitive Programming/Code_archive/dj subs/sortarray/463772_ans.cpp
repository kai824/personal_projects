// ans.cpp 25 Dec 18, 17:38:10 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,ans=1;
    ll increasing;
    cin>>n;
    if(n<3){
        cout<<1;return 0;
    }
    ll arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    if(arr[0]<arr[1])increasing=1;
    else if(arr[0]>arr[1]) increasing=0;
    else increasing=2;
    for(int x=2;x<n;x++){
        if(increasing==1){
            if(arr[x-1]>arr[x]){
                increasing=2;//broke sequence
                ans++;
                x++;
            }
        }else if(increasing==0){
            if(arr[x-1]<arr[x]){
                increasing=2;
                ans++;
                x++;
            }
        }else{
            if(arr[x-1]==arr[x])increasing=2;
            if(arr[x-1]<arr[x])increasing=1;
            else increasing=0;
        }
    }
    cout<<ans;
    if(ans>)
    return 0;
}