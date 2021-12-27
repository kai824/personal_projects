// ans.cpp 11 Mar 18, 23:13:25 40 0 Judging completed in 4.726s on AWS Oregon.
#include <bits/stdc++.h>
#pragma Ospace
using namespace std;
int ar2[111115];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,k,nn;
    cin>>n;
    char arr[n];
    for(int x=0;x<n;x++){
        cin>>a;
        arr[x]=(char)(a%101);
        //ar2[x]=(a/101)+'0';
        ar2[x/9]=(ar2[x/9]*10)+(a/101);
    }
    for(int x=n;(true);x++){
        if(ar2[x/9]==0)break;
        ar2[x/9]*=10;
    }
    cin>>k;
    for(int x=0;x<n;x++){
        nn=ar2[x/9];
        for(int y=(x%9);y<8;y++){
            nn/=10;
        }
        nn%=10;
        a=101*(nn);
        a+=(int)(arr[x]);
        cout<<a+k<<'\n';
        //cout<<arr[x]<<' '<<(int)arr[x]<<' '<<ar2[x]<<'\n';
    }
    return 0;
}