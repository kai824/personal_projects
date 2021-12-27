// ans.cpp 18 Oct 17, 16:55:02 0 0.15 Judging completed in 7.205s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,a,k;
    cin>>n;
    char arr[n];
    long long ar2[52631];
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