// ans.cpp 18 Oct 17, 17:25:28 0 0.24 Judging completed in 6.554s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,k;
    cin>>n;
    char arr[n];
    //char ar2[n];
    int ar2[111112];
    for(int x=0;x<n;x++){
        cin>>a;
        arr[x]=(char)(a%101);
        //ar2[x]=(a/101)+'0';
    }
    cin>>k;
    for(int x=0;x<n;x++){
        //a=101*(ar2[x]-'0');
        a+=(int)(arr[x]);
        cout<<a+k<<'\n';
        //cout<<arr[x]<<' '<<(int)arr[x]<<' '<<ar2[x]<<'\n';
    }
    return 0;
}