// ans.cpp 15 Apr 17, 21:28:44 27 0.15 Judging completed in 5.261s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,p,p1=0,p2=0,current,ans=0,curnums=1;
    cin>>n>>p;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    current=arr[0];
    while(p1<n && p2<n){
        if(current<=p){
            ans=max(ans,curnums);
            p2++;
            curnums++;
            current+=arr[p2];
        }else{
            current-=arr[p1];
            curnums--;
            p1++;
        }
    }
    cout<<ans;
    return 0;
}