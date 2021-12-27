// ans.cpp 14 Oct 17, 10:53:14 100 0.24 Judging completed in 4.353s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1000005],u,tc,n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    for(int x=1;x<=1000000;x++){
        u=x;
        while(u<=1000000){
            arr[u]+=x;
            u+=x;
        }
    }
    for(int x=2;x<=1000000;x++){
        arr[x]=max(arr[x],arr[x-1]);
    }
    cin>>tc;
    while(tc--){
        cin>>n;
        cout<<arr[n]<<'\n';
    }
    return 0;
}