// ans.cpp 21 Dec 18, 07:30:40 0 0 Compilation failed on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,ans=1;
    short int increasing;
    cin>>n;
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
                increasing=0;//broke sequence
                ans+=1;
            }
        }else if(increasing==0{
            if(arr[x-1]<arr[x]){
                increasing=1;
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