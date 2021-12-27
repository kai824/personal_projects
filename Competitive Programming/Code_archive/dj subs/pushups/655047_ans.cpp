// ans.cpp 18 Dec 19, 17:00:09 100 0.26 Judging completed in 4.163s on AWS Oregon.
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