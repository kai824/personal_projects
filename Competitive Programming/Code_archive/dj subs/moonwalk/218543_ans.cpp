// ans.cpp 10 Aug 17, 18:33:02 85 1.33 Judging completed in 5.951s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return(a>b);
}
int main() {
    int n,m,c,p,q,r;
    cin>>n>>m>>c;
    int arr[c];
    for(int x=0;x<c;x++){
        cin>>p>>q>>r;
        arr[x]=(q-p)-r;
    }
    sort(arr,arr+c,cmp);
    for(int x=0;x<m;x++){
        if(arr[x]<0)break;
        n-=arr[x];
    }
    cout<<n;
    return 0;
}