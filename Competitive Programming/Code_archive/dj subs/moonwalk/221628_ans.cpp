// ans.cpp 7 Oct 17, 15:48:17 100 0.28 Judging completed in 5.954s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,c,p,q,r;
    cin>>n>>m>>c;
    int arr[c];
    for(int x=0;x<c;x++){
        cin>>p>>q>>r;
        arr[x]=(q-p)-r;
    }
    sort(arr,arr+c,cmp);
    for(int x=0;x<min(c,m);x++){
        if(arr[x]<=0)break;
        n-=arr[x];
    }
    cout<<n;
    return 0;
}