// ans.cpp 29 Jan 17, 16:19:56 75 1.17 Judging completed in 8.688s on AWS Ireland.
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