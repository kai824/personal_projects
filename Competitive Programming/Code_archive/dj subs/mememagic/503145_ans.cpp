// ans.cpp 10 Mar 19, 15:43:44 12 1 Judging completed in 3.361s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,origin=0,ans=0;
    cin>>n;
    ll arr[n+1],ps[n+1];
    arr[0]=0;ps[0]=0;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
        origin+=arr[x]*x;
        ps[x]=ps[x-1]+arr[x];
    }
    for(int x=1;x<=n;x++){//start pos
        for(int y=1;y<=n;y++){//end pos
            if(x==y)continue;
            //shifted backwards
            if(x>y)ans=max(ans,ps[x-1]-ps[y-1]+(arr[x]*(y-x)) );
            else{
                ans=max(ans,arr[x]*(y-x)+ps[x]-ps[y]);
            }
        }
    }
    cout<<origin+ans;
    return 0;
}