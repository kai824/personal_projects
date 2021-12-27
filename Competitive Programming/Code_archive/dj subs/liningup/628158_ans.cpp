// ans.cpp 4 Dec 19, 14:02:51 100 0.04 Judging completed in 6.381s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    long long ans=1;
    cin>>n;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    sort(arr,arr+n);
    for(int x=0;x<n;x++){
        if((n%2)==1){
            if(x>0 && arr[x]!=((x+1)/2)*2){
                cout<<0;return 0;
            }else if(x==0 && arr[x]!=0){
                cout<<0;return 0;
            }
        }else{
            if(arr[x]!=(x/2)*2+1){
                cout<<0;return 0;
            }
        }
    }
    for(int x=0;x<n/2;x++){
        ans*=2;
        ans%=(1000000007);
    }
    cout<<ans;
    return 0;
}