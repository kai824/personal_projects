// ans.cpp 5 Nov 16, 11:38:14 20 1.02 Judging completed in 5.76s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,c,d=0,e=0;
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