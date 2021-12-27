// ans.cpp 13 Feb 17, 09:43:59 75 1.03 Judging completed in 11.91s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int a,c,d=0,e=0;
    cin>>a;
    for(int b=0;b<a;b=b+1){
        cin>>c;
        d=d+c;
    }
    for(int b=0;b<(a-1);b=b+1){
        cin>>c;
        e=e+c;
    }
    cout<<(d-e);
    return 0;
}