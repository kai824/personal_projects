// ans.cpp 22 Nov 20, 23:28:14 0 0.03 Judging completed in 3.86s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
//#define int long long

int arr[100005],par[100005];
int getr(int k){
    if(par[k]==-1)return k;
    par[k]=getr(par[k]);
    return par[k];
}
void merge(int a,int b){
    par[b]=a;
    arr[a]=arr[b]=max(arr[a],arr[b]);
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
        par[x]=-1;
    }
    while(m--){
        cin>>a>>b;
        a=getr(a);
        b=getr(b);
        if(a==b){
            cout<<"-1\n";
        }else{
            merge(a,b);
            cout<<arr[a]<<'\n';
        }
    }
    return 0;
}