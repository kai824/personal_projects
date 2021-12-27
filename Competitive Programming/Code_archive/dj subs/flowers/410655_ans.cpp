// ans.cpp 12 Nov 18, 13:52:41 17 0.06 Judging completed in 2.653s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int ps[1000005];
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int k,d,a,b;
    cin>>k>>d;
    arr[0]=0;
    for(int x=1;x<=1000000;x++){
        if(x<k){
            arr[x]=1;
            continue;
        }else if(x==k){
            arr[x]=2;
            continue;
        }
        arr[x]=arr[x-1];
        if(x>=k)arr[x]+=arr[x-k];
    }
    for(int x=1;x<=1000000;x++){
        ps[x]=ps[x-1]+arr[x];
    }
    for(int x=0;x<d;x++){
        cin>>a>>b;
        cout<<ps[b]-ps[a-1]<<'\n';
    }
    return 0;
}