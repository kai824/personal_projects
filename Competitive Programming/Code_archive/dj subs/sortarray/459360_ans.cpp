// ans.cpp 21 Dec 18, 07:34:28 0 0.02 Judging completed in 2.142s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=1;
    short int increasing;
    cin>>n;
    if(n<3){
        cout<<1;return 0;
    }
    int arr[n];
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
                ans+=1;
            }
        }else if(increasing==0){
            if(arr[x-1]<arr[x]){
                increasing=2;
                ans+=1;
            }
        }else{
            if(arr[x-1]==arr[x])increasing=2;
            if(arr[x-1]<arr[x])increasing=1;
            else increasing=0;
        }
    }
    cout<<ans;
    return 0;
}