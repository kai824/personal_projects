// ans.cpp 12 Jul 18, 10:53:08 100 0.03 Judging completed in 3.128s on AWS Oregon.
#include <bits/stdc++.h>
using namespace std;
#pragma O3
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    long long a;
    bool b;
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>a;
        if((a%4)==0)b=(a>=0);
        else if((a%4)==1)b=(a>=21);
        else if((a%4)==2)b=(a>=14);
        else b=(a>=7);
        if(b)cout<<"Lucky\n";
        else cout<<"Unlucky\n";
    }
    return 0;
}