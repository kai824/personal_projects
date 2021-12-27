// ans.cpp 13 Feb 17, 09:38:04 0 0 Judging completed in 7.866s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b,c,d;
    cin>>a>>b;
    if(a>b)swap(a,b);
    c=min(a,b/2);
    a-=c;
    b-=c*2;
    if(a>b){
        c+=min(b,a/2);
    }
    cout<<c;
    return 0;
}