// ans.cpp 13 Feb 17, 09:43:11 45 2 Judging completed in 10.264s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
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