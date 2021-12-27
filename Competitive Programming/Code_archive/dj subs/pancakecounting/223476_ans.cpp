// ans.cpp 18 Oct 17, 16:46:54 40 0 Judging completed in 6.73s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unsigned short int n,a,k;
    cin>>n;
    char arr[n];
    char ar2[n];
    for(int x=0;x<n;x++){
        cin>>a;
        arr[x]=(char)(a%101);
        ar2[x]=(a/101)+'0';
    }
    cin>>k;
    for(int x=0;x<n;x++){
        a=101*(ar2[x]-'0');
        a+=(int)(arr[x]);
        cout<<a+k<<'\n';
        //cout<<arr[x]<<' '<<(int)arr[x]<<' '<<ar2[x]<<'\n';
    }
    return 0;
}