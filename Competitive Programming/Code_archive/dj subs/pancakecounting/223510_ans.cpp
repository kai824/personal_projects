// ans.cpp 18 Oct 17, 17:33:32 0 0 Judging completed in 8.2s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
unsigned long long ar2[52700];
int n,a,k,nn,nnn;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    char arr[n];
    for(int x=0;x<n;x++){
        cin>>a;
        arr[x]=(char)(a%101);
        ar2[x/19]*=10;
        ar2[x/19]+=a/101;
        //ar2[x]=(a/101)+'0';
    }
    for(int x=n;(true);x++){
        ar2[x/19]*=10;
        if(ar2[x/19]==0)break;
    }
    cin>>k;
    for(int x=0;x<n;x++){
        nn=ar2[x/19];
        nnn=18-(x%19);
        /*number of digits to divide*/
        if(nnn>9){
            nn/=1e9;
            nnn-=9;
        }
        if(nnn>5){
            nn/=1e5;
            nnn-=5;
        }
        if(nnn>3){
            nn/=1e3;
            nnn-=3;
        }
        if(nnn==3)nn/=1000;
        if(nnn==2)nn/=100;
        if(nnn==1)nn/=10;
        a=101*/*(ar2[x]-'0')*/(nn%10);
        a+=(int)(arr[x]);
        cout<<a+k<<'\n';
        //cout<<arr[x]<<' '<<(int)arr[x]<<' '<<ar2[x]<<'\n';
    }
    return 0;
}