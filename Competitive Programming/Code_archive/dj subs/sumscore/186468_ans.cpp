// ans.cpp 1 Feb 17, 20:56:15 100 0 Judging completed in 6.306s on AWS Ireland.
#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int a,b=0;
    while(true){
        cin>>a;
        if(a==-1){
            cout<<b;
            break;
        }
        b+=a;
    }
    return 0;
}