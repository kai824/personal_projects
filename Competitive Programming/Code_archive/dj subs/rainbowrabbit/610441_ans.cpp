// ans.cpp 19 Nov 19, 07:59:02 100 0.13 Judging completed in 4.206s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int c,mini;
    long long ans=0;
    cin>>c;
    int arr[c];
    for(int x=0;x<c;x++){
        cin>>arr[x];
    }
    sort(arr,arr+c);
    mini=arr[0];
    for(int x=0;x<c;x++){
        ans+=mini;
        if(arr[x]>mini)ans++;
    }
    cout<<ans;
    return 0;
}