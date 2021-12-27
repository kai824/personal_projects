// ans.cpp 15 Apr 17, 21:27:41 27 0.59 Judging completed in 6.354s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,p,p1=0,p2=0,current,ans=0,curnums=1;
    cin>>n>>p;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    current=arr[0];
    while(p1<n && p2<n){
        if(current<p){
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