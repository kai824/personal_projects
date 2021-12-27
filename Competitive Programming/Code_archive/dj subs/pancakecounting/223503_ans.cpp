// ans.cpp 18 Oct 17, 17:20:19 0 0 Judging completed in 6.734s on AWS Oregon.
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
        arr[x]=(char)(a%151);
        ar2[x/19]*=10;
        ar2[x/19]+=a/151;
        //ar2[x]=(a/101)+'0';
    }
    for(int x=n;;x++){
        ar2[x/19]*=10;
        if(ar2[x/19]==0)break;
    }
    cin>>k;
    for(int x=0;x<n;x++){
        nn=ar2[x/19];
        for(int y=x%19;y<18;y++)nn/=10;
        a=151*/*(ar2[x]-'0')*/(nn%10);
        a+=(int)(arr[x]);
        cout<<a+k<<'\n';
        //cout<<arr[x]<<' '<<(int)arr[x]<<' '<<ar2[x]<<'\n';
    }
    return 0;
}