// ans.cpp 21 Oct 17, 13:13:47 100 0.24 Judging completed in 7.124s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,a1=1,a2=1;
    bool a11=true;
    cin>>n>>k;
    a2+=k;
    int ans[n+1];
    for(int x=1;x<=k+1;x++){
        if(a11){
            ans[x]=a1;
            a1++;
        }else{
            ans[x]=a2;
            a2--;
        }
        a11=!a11;
    }
    for(int x=k+2;x<=n;x++){
        ans[x]=x;
    }
    for(int x=1;x<k;x++){
        cout<<x<<' ';
    }
    cout<<k<<'\n';
    for(int x=1;x<n;x++){
        cout<<ans[x]<<' ';
    }
    cout<<ans[n];
    return 0;
}