// ans.cpp 16 Oct 17, 12:26:54 0 0 Judging completed in 3.686s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll n,k,arr[100010]={4294967295},a,sum;
    cin>>n>>k;
    for(int x=1;x<=n;x++){
        cin>>a;
        if(x<=k)arr[x]=a;
        else{
            sum=0;
            arr[x]=4294967295;
            for(int y=x-k;y<x;x++){
                arr[x]=min(max(a,arr[y]),arr[x]);
            }
        }
    }
    a=4294967295;//now used as "ans"
    for(int x=n+1-k;x<=n;x++){
        arr[n+1]=min(arr[x],arr[n+1]);
    }
    if(k>n)cout<<0;
    else cout<<arr[n+1];
    return 0;
}